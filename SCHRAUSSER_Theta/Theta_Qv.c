//----------------------------------------------------------------------------------------------------|Theta_Qv (c) SCHRAUSSER 2009

#include "Theta_Qv.h"

void fn_minwert(int sw);
	
FILE *outStreamR, *outStreamP, *outStreamS1, *outStreamS2, *outStreamQ, *logStream;

void main(int argc, char *argv[])
{
	int   jLauf, sLauf, mLauf, dLauf, zlr=0, zlr1=0, i_=1, i;
	                 
	int    ds=1;  //SCHRAUSSER d, dvaro berechnungs durchlauf indikator
	int    a_GZ;  //ganzzahlig indikator
	double a_SD;  //seed 
    double a_X;   //vergleichswert 
	double pr_=0; //prozentrang

	char dbuffer[9], tbuffer[9], thetp[5], thets1[5], thets2[5], ttha[5], thetq[5],  thetqq[5];

	if (argc < 13) profil();

	for(i=1; i<=4; i++)  
	{     
		       sum[i]=0; 
	          sum2[i]=0; 
	         d_sum[i]=0;    
                _S[i]=0;     
	          _min[i]=0;
             _min2[i]=0;
             _SmiN[i]=0;
	         _Smax[i]=0;
              _max[i]=0; 
             _max2[i]=0; 
         d_min_sum[i]=0;  
         d_max_sum[i]=0;
	}
	
	                a_SD     = atof(argv[1]);
	                a_MIN    = atof(argv[2]);
	                a_MAX    = atof(argv[3]);
	                a_TTHA   = atoi(argv[4]);
					a_THETP  = atoi(argv[5]);
	                a_THETS1 = atoi(argv[6]);
	                a_THETS2 = atoi(argv[7]);
	            	a_THETQQ = atoi(argv[8]);    
	                a_THETQ  = atoi(argv[9]);	sw6= a_THETQ;
                	a_V      = atoi(argv[10]);
	                a_N      = atoi(argv[11]);
	                a_S      = atoi(argv[12]);
	if (argc >= 14) a_X      = atof(argv[13]);
	if (argc == 15) a_GZ     = atoi(argv[14]);

	if (a_THETP == 0 ) strcpy(thetp, "HM");		if (a_THETS1 == 0 ) strcpy(thets1, "HM");		if (a_THETS2 == 0 ) strcpy(thets2, "HM");
	if (a_THETP == 1 ) strcpy(thetp, "AM");		if (a_THETS1 == 1 ) strcpy(thets1, "AM");		if (a_THETS2 == 1 ) strcpy(thets2, "AM");
	if (a_THETP == 2 ) strcpy(thetp, "SUM");	if (a_THETS1 == 2 ) strcpy(thets1, "SUM");		if (a_THETS2 == 2 ) strcpy(thets2, "SUM");
	if (a_THETP == 3 ) strcpy(thetp, "SD");		if (a_THETS1 == 3 ) strcpy(thets1, "SD");		if (a_THETS2 == 3 ) strcpy(thets2, "SD");
	if (a_THETP == 4 ) strcpy(thetp, "VAR");	if (a_THETS1 == 4 ) strcpy(thets1, "VAR");		if (a_THETS2 == 4 ) strcpy(thets2, "VAR");
	if (a_THETP == 5 ) strcpy(thetp, "PSUM");	if (a_THETS1 == 5 ) strcpy(thets1, "PSUM");		if (a_THETS2 == 5 ) strcpy(thets2, "PSUM");
	if (a_THETP == 6 ) strcpy(thetp, "GM");		if (a_THETS1 == 6 ) strcpy(thets1, "GM");		if (a_THETS2 == 6 ) strcpy(thets2, "GM");
	if (a_THETP == 7 ) strcpy(thetp, "D");		if (a_THETS1 == 7 ) strcpy(thets1, "D");		if (a_THETS2 == 7 ) strcpy(thets2, "D");
	if (a_THETP == 8 ) strcpy(thetp, "DV");		if (a_THETS1 == 8 ) strcpy(thets1, "DV");		if (a_THETS2 == 8 ) strcpy(thets2, "DV");

	if (a_THETQQ == 0 ) strcpy(thetqq, "HM");		
	if (a_THETQQ == 1 ) strcpy(thetqq, "AM");	
	if (a_THETQQ == 2 ) strcpy(thetqq, "SUM");	
	if (a_THETQQ == 3 ) strcpy(thetqq, "SD");	
	if (a_THETQQ == 4 ) strcpy(thetqq, "VAR");	
	if (a_THETQQ == 5 ) strcpy(thetqq, "PSUM");	
	if (a_THETQQ == 6 ) strcpy(thetqq, "GM");		
	if (a_THETQQ == 7 ) strcpy(thetqq, "D");		
	if (a_THETQQ == 8 ) strcpy(thetqq, "DV");		
	
	if (a_TTHA == 0 ) strcpy(ttha, "HM");
	if (a_TTHA == 1 ) strcpy(ttha, "AM");
	if (a_TTHA == 2 ) strcpy(ttha, "SUM");
	if (a_TTHA == 3 ) strcpy(ttha, "SD");
	if (a_TTHA == 4 ) strcpy(ttha, "VAR");
	if (a_TTHA == 5 ) {strcpy(ttha, "PSUM"); _min[1]=_max[1]=sum[1]=1;_min[2]=_max[2]=sum[2]=1;_min[3]=_max[3]=sum[3]=1;_min[4]=_max[4]=sum[4]=1;}
	if (a_TTHA == 6 ) {strcpy(ttha, "GM");   _min[1]=_max[1]=sum[1]=1;_min[2]=_max[2]=sum[2]=1;_min[3]=_max[3]=sum[3]=1;_min[4]=_max[4]=sum[4]=1;}
	if (a_TTHA == 7 ) {strcpy(ttha, "D");  ds=2;}
	if (a_TTHA == 8 ) {strcpy(ttha, "DV"); ds=2;}

	
	if (a_THETQ == 1 ) strcpy(thetq, "Diff");
	if (a_THETQ == 2 ) strcpy(thetq, "Quot");
	if (a_THETQ == 3 ) strcpy(thetq, "Summ");
	if (a_THETQ == 4 ) strcpy(thetq, "Prod");
	if (a_THETQ == 5 ) strcpy(thetq, "Kor");
	if (a_THETQ == 6 ) strcpy(thetq, "Cov");
	if (a_THETQ == 7 ) strcpy(thetq, "Det");
	if (a_THETQ == 8 ) strcpy(thetq, "Red");
	
	
	if(a_SD == 0)
	{
		          seed1=time(0)-1234567890;
		   seed=  seed1-(floor(seed1/10000))*10000;
	}
	else { seed= a_SD; }

    seed1= seed;

	min__[1]= a_MAX; min__[2]= a_MAX; min__[3]= a_MAX;//sic
	max__[1]= a_MIN; max__[2]= a_MIN; max__[3]= a_MIN;
	
	outStreamR  = fopen( "Theta_Qv_R.txt",   "w" );
	outStreamP  = fopen( "Theta_Qv_P.txt",   "w" );
	outStreamS1 = fopen( "Theta_Qv_S1.txt",  "w" );
	outStreamS2 = fopen( "Theta_Qv_S2.txt",  "w" );
	outStreamQ  = fopen( "Theta_Qv_Q.txt",   "w" );
	logStream   = fopen( "Theta_Qv_log.txt", "a" );
	
	kopf();
	
	//bildschirmausgabe
	if(argc == 15 && a_GZ==1) printf("gW "); 
	                          printf("seed= %.0f, v= %i, n= %i, s= %i, q= %s\n\n",           seed, a_V, a_N, a_S, ttha );
	                          printf("R( %.2f, %.2f)\n",                                     a_MIN, a_MAX);
                              printf("\xC2\n");

	_strdate( dbuffer ); _strtime( tbuffer );
	
	//log ausgabe
	                         fprintf (logStream,"SCHRAUSSER - Theta_Qv");
	                         fprintf(logStream,"                        ");
	if (argc >= 14)          fprintf(logStream,"            ");
	                         fprintf (logStream,"%s @ %s\n",                                  dbuffer, tbuffer);
	                         fprintf(logStream, "\n");
	if(argc == 15 && a_GZ==1)fprintf(logStream,"Ganzzahlig "); 
	                         fprintf(logStream, "seed= %.0f, v= %i, n= %i, s= %i, q= %s\n",   seed, a_V, a_N, a_S, ttha);
	                         for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 14)          for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	                         fprintf(logStream,"\nEbene\tqE\tN\tmin\tqmin\tmax\tqmax\tqqE"); 
	if (argc >= 14)          fprintf(logStream, "\tPR(%.2f)",                                 a_X);
	                         fprintf(logStream, "\n");
	                         for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 14)          for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	                         fprintf(logStream,"\nR\t\ts2nv\t%.3f\t\t%.3f",                   a_MIN, a_MAX );
	

	for(dLauf=1;dLauf<=ds; dLauf++)                                                                                     //2 fach durchgang bei q=D=DV
	{
		for(iLauf=1;iLauf<=a_S; iLauf++)                                                                                //vektorerzeugung über subpopulationen s
		{
			for(sLauf=1;sLauf<=a_N*2; sLauf++)                                                                          //vektorerzeugung über mn
			{
				for(jLauf=1;jLauf<=a_V; jLauf++)                                                                        //vektorerzeugung über v
				{
					                                                zf_wert[jLauf]= qzufall(seed,a_MIN,a_MAX);          // pop zufallszahl zwischen min und max
					if(argc == 15 && a_GZ==1) zf_wert[jLauf]= floor(zf_wert[jLauf]);                                    // ganzzahliger wertebereich

					if(dLauf==1)if(zlr1<30000)           fprintf(outStreamR,"%f\n", fn_erg);                            // ausgabe von R bis sv=30000 in datei

					                                                          seed= fn_erg;
					zlr1++;
				}
				// P
				fn_minwert(1);
				
				if(dLauf==1)if(zlr<30000)fprintf(outStreamP,"%f\t%f\t", min_[1], max_[1]);                                // ausgabe von min/max_v bis s=30000 in datei 
				fn_TTHAsub(a_TTHA, dLauf, 1); 
				if(dLauf==1)if(zlr<30000)fprintf(outStreamP,"%f\n", fn_erg);                                          // ausgabe von theta  bis s=30000 in datei  
					
				s_wert[sLauf] = fn_erg;                                                                               // subwert-vektor subwert(i) = pop kennwert	

				zlr++;
			}
			//s_wertvektor aufteilung
			for(mLauf=1;mLauf<=a_N*2;mLauf+=2)	{ s1_wert[i_] = s_wert[mLauf];i_++; }   i_=1;
			for(mLauf=2;mLauf<=a_N*2;mLauf+=2)  { s2_wert[i_] = s_wert[mLauf];i_++; }	i_=1;
		
			// S1 [2]
		    fn_minwert(2);
			
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS1,"%f\t%f\t", min_[2], max_[2]);                              // ausgabe von min/max_m bis s=30000 in datei
			fn_TTHAsub(a_TTHA, dLauf, 2);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS1,"%f\n", fn_erg);                                        // ausgabe von theta  bis s=30000 in datei  
			
			// S2 [3]
			fn_minwert(3);
		
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS2,"%f\t%f\t", min_[3], max_[3]);                              // ausgabe von min/max_n bis s=30000 in datei  
			fn_TTHAsub(a_TTHA, dLauf, 3);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS2,"%f\n", fn_erg);                                        // ausgabe von theta  bis s=30000 in datei  
			
			//Q [4]
			if(a_THETQ<5)
			{	
				for(mLauf=1;mLauf<=a_N*2;mLauf+=2)
				{
					if(a_THETQ==1) Q_wert[mLauf] = s1_wert[mLauf]-s2_wert[mLauf+1];                //S1-S2 
					if(a_THETQ==2) Q_wert[mLauf] = s1_wert[mLauf]/s2_wert[mLauf+1];                //S1/S2
					if(a_THETQ==3) Q_wert[mLauf] = s1_wert[mLauf]+s2_wert[mLauf+1];                //S1+S2
					if(a_THETQ==4) Q_wert[mLauf] = s1_wert[mLauf]*s2_wert[mLauf+1];                //S1*S2
				}
				fn_minwert(4);
	            if(dLauf==1)if(iLauf<=30000)fprintf(outStreamQ,"%f\t%f\t", min_[4], max_[4]); // ausgabe von min/max_Q bis s=30000 in datei
			}
			
			if(a_THETQ>=5)                                                                         //rS1S2
			{
				for(mLauf=1;mLauf<=a_N*2;mLauf+=2) { sr_wert[mLauf]= s1_wert[i_];i_++; } i_=1;
				for(mLauf=2;mLauf<=a_N*2;mLauf+=2) { sr_wert[mLauf]= s2_wert[i_];i_++; } i_=1;
				
				if(a_THETQ==5) fn_lin_reg(sr_wert, a_N*2, 1);
				if(a_THETQ==6) fn_lin_reg(sr_wert, a_N*2, 2);
				if(a_THETQ==7) fn_lin_reg(sr_wert, a_N*2, 3);
				if(a_THETQ==8) fn_lin_reg(sr_wert, a_N*2, 4);
			
			}
			
			fn_TTHAsub(a_TTHA, dLauf, 4);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamQ,"%f\n", fn_erg);                    // ausgabe von theta  bis s=30000 in datei

			if(dLauf==1)printf("\xC0\xB0\xB1\xB2 s(%i)\r",      iLauf);                           //bildschirmausgabe zähler
			if(dLauf==2)printf("\xC0\xB0\xB1\xB2 s(%i) \r", a_S-iLauf);                           //bildschirmausgabe zähler
			
			if(dLauf==1)if(argc >= 14 && a_X > fn_erg) pr_++; //prozentrang von x		 	
		}
		
		if(ds==2)//bei q=D=DV
		{
			q_min[1] = _min[1]/(a_S*(a_N*2));q_max[1] = _max[1]/(a_S*(a_N*2));qqe_[1]=sum[1]/(a_S*(a_N*2)); //sub v minimalwert mittelung//sub v maximalwert mittelung //kennwert mittelung 
			q_min[2] = _min[2]/(a_S);        q_max[2] = _max[2]/(a_S);	      qqe_[2]=sum[2]/(a_S);           //sub m minimalwert mittelung	//sub m maximalwert mittelung	 //kennwert mittelung 
			q_min[3] = _min[3]/(a_S);        q_max[3] = _max[3]/(a_S);        qqe_[3]=sum[3]/(a_S);           //sub n minimalwert mittelung	//sub n maximalwert mittelung //kennwert mittelung 
			q_min[4] = _min[4]/(a_S);        q_max[4] = _max[4]/(a_S);        qqe_[4]=sum[4]/(a_S);           //sub Q minimalwert mittelung//sub Q maximalwert mittelung //kennwert mittelung 
		
			seed= seed1; 
		}
	}

	fn_TTHA(a_TTHA);   //

	if (argc >= 13) pr_=(pr_/(a_S))*100;
	
	//bildschirmausgabe
	                printf("\r\xC0\xB4P( %.2f, %.2f), %s(%s)= %.2f",               min__[1], max__[1], ttha, thetp,  qqe_[1]); 
	                printf("\n \xB3");
	                printf("\n \xC0\xB4S1( %.2f, %.2f), %s(%s)= %.2f",             min__[2], max__[2], ttha, thets1, qqe_[2]); 
	if(a_THETQ <5)  printf("\n  \xB3");
	if(a_THETQ>=5)  printf("\n  x");
	                printf("\n  \xB3S2( %.2f, %.2f), %s(%s)= %.2f",                min__[3], max__[3], ttha, thets2, qqe_[3]);
	                printf("\n  \xB3");
	                printf("\n  \xC0");
	if(a_THETQ< 5)  printf("\xC4");
					printf("\x10Q( %.2f, %.2f), %s(%s)= %.2f",                     min__[4], max__[4], ttha, thetq,  qqe_[4]);
	if(argc >= 14 ) printf(", PR(%.2f)= %.2f",                                     a_X, pr_);
	

	
	//log ausgabe
		           fprintf(logStream,"\n:R\t%s\tv\t\t%.3f\t\t%.3f",                thetp,    q_min[1], q_max[1] );
	               fprintf(logStream,"\nP\t\ts2n\t%.3f\t\t%.3f\t\t%.3f",           min__[1], max__[1],  qqe_[1] );
	               fprintf(logStream,"\n:P\t%s\tn\t\t%.3f\t\t%.3f",                thets1,   q_min[2], q_max[2] );
	               fprintf(logStream,"\nS1\t\ts\t%.3f\t\t%.3f\t\t%.3f",            min__[2], max__[2],  qqe_[2] );
	               fprintf(logStream,"\n:P\t%s\tn\t\t%.3f\t\t%.3f",                thets2,   q_min[3], q_max[3] );
	               fprintf(logStream,"\nS2\t\ts\t%.3f\t\t%.3f\t\t%.3f",            min__[3], max__[3],  qqe_[3] );
	if(a_THETQ< 5) fprintf(logStream,"\n:Q\t%s\tn\t\t%.3f\t\t%.3f",                thetqq,   q_min[4], q_max[4] );              
				   fprintf(logStream,"\nQ\t%s\ts\t%.3f\t\t%.3f\t\t%.3f",           thetq,    min__[4], max__[4], qqe_[4]);
	if (argc >= 14)fprintf(logStream, "\t%.3f",                                    pr_);
	               fprintf(logStream, "\n");
	               for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 14)for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	               fprintf(logStream, "\n\x95\n\n");
	

	//bildschirmausgabe
	printf("\n\ncall bearb_.bat\n"); 
	printf("edit Theta_Qv.xls\n");
	
	fclose(outStreamR);
	fclose(outStreamP);
	fclose(outStreamS1);
	fclose(outStreamS2);
	fclose(outStreamQ);
	fclose(logStream);

	getch();

	//system("start Theta_Qv_log.txt");
	//system("bearb_.bat");
}

void fn_minwert(int sw)
{
	int mLauf;
	min_[sw]= a_MAX; max_[sw]= a_MIN;
			
	if (sw==1)for(mLauf=1;mLauf<=a_V;mLauf++) 
	{
		if(zf_wert[mLauf]<min_[sw]) min_[sw]= zf_wert[mLauf];//sub v minimalwert bestimmung
		if(zf_wert[mLauf]>max_[sw]) max_[sw]= zf_wert[mLauf];//sub v maximalwert bestimmung
	}

	if (sw==2)for(mLauf=1;mLauf<=a_N;mLauf++) 
	{
		if(s1_wert[mLauf]<min_[sw]) min_[sw]= s1_wert[mLauf];//sub 1 minimalwert bestimmung
		if(s1_wert[mLauf]>max_[sw]) max_[sw]= s1_wert[mLauf];//sub 1 maximalwert bestimmung
	}

	if (sw==3)for(mLauf=1;mLauf<=a_N;mLauf++) 
	{
		if(s2_wert[mLauf]<min_[sw]) min_[sw]= s2_wert[mLauf];//sub 2 minimalwert bestimmung
		if(s2_wert[mLauf]>max_[sw]) max_[sw]= s2_wert[mLauf];//sub 2 maximalwert bestimmung
	}

	if (sw==4)for(mLauf=1;mLauf<=a_N;mLauf++) 
	{
		if(Q_wert[mLauf]<min_[sw]) min_[sw]= Q_wert[mLauf];//sub Q minimalwert bestimmung
		if(Q_wert[mLauf]>max_[sw]) max_[sw]= Q_wert[mLauf];//sub Q maximalwert bestimmung
	}


}