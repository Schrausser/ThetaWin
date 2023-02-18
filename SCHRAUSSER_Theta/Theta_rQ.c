//----------------------------------------------------------------------------------------------------|Theta_rQ (c) SCHRAUSSER 2009

#include "Theta_rQ.h"

void fn_minwert(int sw);

FILE *outStreamR, *outStreamP, *outStreamS11, *outStreamS12, *outStreamS21, *outStreamS22, *outStreamr1, *outStreamr2,*outStreamQ, *logStream;

void main(int argc, char *argv[])
{
	int   jLauf, sLauf, mLauf, dLauf, yLauf, zlr=0, zlr1=0, i_=1, i;

	int    ds=1;  //SCHRAUSSER d, dvaro berechnungs durchlauf indikator
	int    a_GZ;  //ganzzahlig indikator
	double a_SD;  //seed 
    double a_X;   //vergleichswert 
	double pr_=0; //prozentrang

	char dbuffer [9],tbuffer [9], thetp[5], thets11[5], thets12[5], thets21[5], thets22[5], ttha[5], tthr1[5], tthr2[5], thetq[5];

	for(i=1; i<=8; i++)  
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
	
	if (argc < 17) profil();

	                a_SD      = atof(argv[1]);
	                a_MIN     = atof(argv[2]);
	                a_MAX     = atof(argv[3]);
	                a_TTHA    = atoi(argv[4]);
					a_THETP   = atoi(argv[5]);
	                a_THETS11 = atoi(argv[6]);
	                a_THETS12 = atoi(argv[7]);
	                a_THETS21 = atoi(argv[8]);
	                a_THETS22 = atoi(argv[9]);
	                a_TTHR1   = atoi(argv[10]);
					a_TTHR2   = atoi(argv[11]);
					a_THETQ   = atoi(argv[12]);  
	                a_V       = atoi(argv[13]);
	                a_M       = atoi(argv[14]);
	                a_N       = atoi(argv[15]);
	                a_S       = atoi(argv[16]);
	if (argc >= 18) a_X       = atof(argv[17]);
	if (argc == 19) a_GZ      = atoi(argv[18]);

	if (a_THETP == 0 ) strcpy(thetp, "HM");		if (a_THETS11 == 0 ) strcpy(thets11, "HM");		if (a_THETS12 == 0 ) strcpy(thets12, "HM");
	if (a_THETP == 1 ) strcpy(thetp, "AM");		if (a_THETS11 == 1 ) strcpy(thets11, "AM");		if (a_THETS12 == 1 ) strcpy(thets12, "AM");
	if (a_THETP == 2 ) strcpy(thetp, "SUM");	if (a_THETS11 == 2 ) strcpy(thets11, "SUM");	if (a_THETS12 == 2 ) strcpy(thets12, "SUM");
	if (a_THETP == 3 ) strcpy(thetp, "SD");		if (a_THETS11 == 3 ) strcpy(thets11, "SD");		if (a_THETS12 == 3 ) strcpy(thets12, "SD");
	if (a_THETP == 4 ) strcpy(thetp, "VAR");	if (a_THETS11 == 4 ) strcpy(thets11, "VAR");	if (a_THETS12 == 4 ) strcpy(thets12, "VAR");
	if (a_THETP == 5 ) strcpy(thetp, "PSUM");	if (a_THETS11 == 5 ) strcpy(thets11, "PSUM");	if (a_THETS12 == 5 ) strcpy(thets12, "PSUM");
	if (a_THETP == 6 ) strcpy(thetp, "GM");		if (a_THETS11 == 6 ) strcpy(thets11, "GM");		if (a_THETS12 == 6 ) strcpy(thets12, "GM");
	if (a_THETP == 7 ) strcpy(thetp, "D");		if (a_THETS11 == 7 ) strcpy(thets11, "D");		if (a_THETS12 == 7 ) strcpy(thets12, "D");
	if (a_THETP == 8 ) strcpy(thetp, "DV");		if (a_THETS11 == 8 ) strcpy(thets11, "DV");		if (a_THETS12 == 8 ) strcpy(thets12, "DV");

	if (a_THETS21 == 0 ) strcpy(thets21, "HM");		if (a_THETS22 == 0 ) strcpy(thets22, "HM");
	if (a_THETS21 == 1 ) strcpy(thets21, "AM");		if (a_THETS22 == 1 ) strcpy(thets22, "AM");
	if (a_THETS21 == 2 ) strcpy(thets21, "SUM");	if (a_THETS22 == 2 ) strcpy(thets22, "SUM");
	if (a_THETS21 == 3 ) strcpy(thets21, "SD");		if (a_THETS22 == 3 ) strcpy(thets22, "SD");
	if (a_THETS21 == 4 ) strcpy(thets21, "VAR");	if (a_THETS22 == 4 ) strcpy(thets22, "VAR");
	if (a_THETS21 == 5 ) strcpy(thets21, "PSUM");	if (a_THETS22 == 5 ) strcpy(thets22, "PSUM");
	if (a_THETS21 == 6 ) strcpy(thets21, "GM");		if (a_THETS22 == 6 ) strcpy(thets22, "GM");
	if (a_THETS21 == 7 ) strcpy(thets21, "D");		if (a_THETS22 == 7 ) strcpy(thets22, "D");
	if (a_THETS21 == 8 ) strcpy(thets21, "DV");		if (a_THETS22 == 8 ) strcpy(thets22, "DV");
		
	
	if (a_TTHA == 0 ) strcpy(ttha, "HM");
	if (a_TTHA == 1 ) strcpy(ttha, "AM");
	if (a_TTHA == 2 ) strcpy(ttha, "SUM");
	if (a_TTHA == 3 ) strcpy(ttha, "SD");
	if (a_TTHA == 4 ) strcpy(ttha, "VAR");
	if (a_TTHA == 5 ) {strcpy(ttha, "PSUM"); for(i=1; i<=8; i++) _min[i]=_max[i]=sum[i]=1; }
	if (a_TTHA == 6 ) {strcpy(ttha, "GM");   for(i=1; i<=8; i++) _min[i]=_max[i]=sum[i]=1; }
	if (a_TTHA == 7 ) {strcpy(ttha, "D");  ds=2;}
	if (a_TTHA == 8 ) {strcpy(ttha, "DV"); ds=2;}

	
	if (a_TTHR1 == 1 ) strcpy(tthr1, "kor");
	if (a_TTHR1 == 2 ) strcpy(tthr1, "cov");
	if (a_TTHR1 == 3 ) strcpy(tthr1, "det");
	if (a_TTHR1 == 4 ) strcpy(tthr1, "red");

	if (a_TTHR2 == 1 ) strcpy(tthr2, "kor");
	if (a_TTHR2 == 2 ) strcpy(tthr2, "cov");
	if (a_TTHR2 == 3 ) strcpy(tthr2, "det");
	if (a_TTHR2 == 4 ) strcpy(tthr2, "red");
	
	
	if (a_THETQ == 1 ) strcpy(thetq, "Diff");
	if (a_THETQ == 2 ) strcpy(thetq, "Quot");
	if (a_THETQ == 3 ) strcpy(thetq, "Summ");
	if (a_THETQ == 4 ) strcpy(thetq, "Prod");
	
	
	if(a_SD == 0)
	{
		          seed1=time(0)-1234567890;
		   seed=  seed1-(floor(seed1/10000))*10000;
	}
	else { seed= a_SD; }

	seed1= seed;

	min__[1]= a_MAX; min__[2]= a_MAX; min__[3]= a_MAX; min__[4]= a_MAX; min__[5]= a_MAX;//sic
	max__[1]= a_MIN; max__[2]= a_MIN; max__[3]= a_MIN; max__[4]= a_MIN; max__[5]= a_MIN;
                                               
	
	outStreamR   = fopen( "Theta_rQ_R.txt",   "w" );
	outStreamP   = fopen( "Theta_rQ_P.txt",   "w" );
	outStreamS11 = fopen( "Theta_rQ_S11.txt", "w" );
	outStreamS12 = fopen( "Theta_rQ_S12.txt", "w" );
	outStreamS21 = fopen( "Theta_rQ_S21.txt", "w" );
	outStreamS22 = fopen( "Theta_rQ_S22.txt", "w" );
	outStreamr1  = fopen( "Theta_rQ_r1.txt",  "w" );
	outStreamr2  = fopen( "Theta_rQ_r2.txt",  "w" );
	outStreamQ   = fopen( "Theta_rQ_Q.txt",   "w" );
	logStream    = fopen( "Theta_rQ_log.txt", "a" );
	
	kopf();
	
	//bildschirmausgabe
	if(argc == 18 && a_GZ==1) printf("gW "); 
	                          printf("seed= %.0f, v= %i, m= %i, n= %i, s= %i, q= %s\n\n",            seed, a_V, a_M, a_N, a_S, ttha );
	                          printf("R( %.2f, %.2f)\n",                                             a_MIN, a_MAX);
                              printf("\xC2\n");
	

	_strdate( dbuffer ); _strtime( tbuffer );
	
	//log ausgabe
	                         fprintf (logStream,"SCHRAUSSER - Theta_rQ");
	                         fprintf(logStream,"                        ");
	if (argc >= 18)          fprintf(logStream,"            ");
	                         fprintf (logStream,"%s @ %s\n",                                         dbuffer, tbuffer);
	                         fprintf(logStream, "\n");
	if(argc == 19 && a_GZ==1)fprintf(logStream,"Ganzzahlig "); 
	                         fprintf(logStream, "seed= %.0f, v= %i, m= %i, n= %i, s= %i, q= %s\n",   seed, a_V, a_M, a_N, a_S, ttha);
	                         for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 18)          for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	                         fprintf(logStream,"\nEbene\tqE\tN\tmin\tqmin\tmax\tqmax\tqqE"); 
	if (argc >= 18)          fprintf(logStream, "\tPR(%.2f)",                                        a_X);
	                         fprintf(logStream, "\n");
	                         for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 18)          for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	                         fprintf(logStream,"\nR\t\ts(n+m)v\t%.3f\t\t%.3f",                       a_MIN, a_MAX );
	

	for(dLauf=1;dLauf<=ds; dLauf++)                                                                              //2 fach durchgang bei q=D=DV
	{
		for(iLauf=1;iLauf<=a_S; iLauf++)                                                                         //vektorerzeugung über subpopulationen s
		{
			for(sLauf=1;sLauf<=2*(a_M+a_N); sLauf++)                                                             //vektorerzeugung über 2(m+n)
			{
				for(jLauf=1;jLauf<=a_V; jLauf++)                                                                 //vektorerzeugung über v
				{
					                                               zf_wert[jLauf] = qzufall(seed,a_MIN,a_MAX);                           // pop zufallszahl zwischen min und max
					if(argc == 19 && a_GZ==1) zf_wert[jLauf]=floor(zf_wert[jLauf]);                              // ganzzahliger wertebereich

					if(dLauf==1)if(zlr1<30000)fprintf(outStreamR,"%f\n", fn_erg);                                // ausgabe von R bis sv=30000 in datei
					                                               
					                                               seed= fn_erg;
					zlr1++;
				}
				// P [1]
				fn_minwert(1);
				
				if(dLauf==1)if(zlr<30000)fprintf(outStreamP,"%f\t%f\t", min_[1], max_[1]);                                // ausgabe von min/max_v bis s=30000 in datei 
				fn_TTHAsub(a_TTHA, dLauf, 1); 
				if(dLauf==1)if(zlr<30000)fprintf(outStreamP,"%f\n", fn_erg);                                          // ausgabe von theta  bis s=30000 in datei  
					
				s_wert[sLauf] = fn_erg;                                                                               // subwert-vektor subwert(i) = pop kennwert	

				zlr++;	
			}
			//S_wertvektor aufteilung
			for(mLauf=1;        mLauf<=a_M*2;          mLauf+=2) { s11_wert[i_] = s_wert[mLauf];i_++; } i_=1;
			for(mLauf=2;        mLauf<=a_M*2;          mLauf+=2) { s12_wert[i_] = s_wert[mLauf];i_++; } i_=1;

			for(mLauf=(a_M*2)+1;mLauf<=(a_M*2)+(a_N*2);mLauf+=2) { s21_wert[i_] = s_wert[mLauf];i_++; } i_=1;
			for(mLauf=(a_M*2)+2;mLauf<=(a_M*2)+(a_N*2);mLauf+=2) { s22_wert[i_] = s_wert[mLauf];i_++; } i_=1;
		
			// S11 [2]
			fn_minwert(2);
			
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS11,"%f\t%f\t", min_[2], max_[2]);                              // ausgabe von min/max_m bis s=30000 in datei
			fn_TTHAsub(a_TTHA, dLauf, 2);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS11,"%f\n", fn_erg);                                        // ausgabe von theta  bis s=30000 in datei  
			
			// S12 [3]
			fn_minwert(3);
		
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS12,"%f\t%f\t", min_[3], max_[3]);                              // ausgabe von min/max_n bis s=30000 in datei  
			fn_TTHAsub(a_TTHA, dLauf, 3);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS12,"%f\n", fn_erg);                                        // ausgabe von theta  bis s=30000 in datei  
			
			// S21 [4]
			fn_minwert(4);
		
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS21,"%f\t%f\t", min_[4], max_[4]);                              // ausgabe von min/max_n bis s=30000 in datei  
			fn_TTHAsub(a_TTHA, dLauf, 4);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS21,"%f\n", fn_erg);                                        // ausgabe von theta  bis s=30000 in datei  
			
			// S22 [5]
			fn_minwert(5);
		
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS22,"%f\t%f\t", min_[5], max_[5]);                              // ausgabe von min/max_n bis s=30000 in datei  
			fn_TTHAsub(a_TTHA, dLauf, 5);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS22,"%f\n", fn_erg);                                        // ausgabe von theta  bis s=30000 in datei  
			
			//r1 [6]
			for(mLauf=1;mLauf<=a_M*2;mLauf+=2) { sr_wert[mLauf]= s11_wert[i_];i_++; } i_=1;
			for(mLauf=2;mLauf<=a_M*2;mLauf+=2) { sr_wert[mLauf]= s12_wert[i_];i_++; } i_=1;
			
			fn_lin_reg(sr_wert, a_M*2, a_TTHR1); fn_erg1 =fn_erg; //<--
			
			fn_TTHAsub(a_TTHA, dLauf, 6);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamr1,"%f\n", fn_erg);                                            // ausgabe von theta  bis s=30000 in datei

			//r2 [7]
			for(mLauf=1;mLauf<=a_N*2;mLauf+=2) { sr_wert[mLauf]= s21_wert[i_];i_++; } i_=1;
			for(mLauf=2;mLauf<=a_N*2;mLauf+=2) { sr_wert[mLauf]= s22_wert[i_];i_++; } i_=1;
			
			fn_lin_reg(sr_wert, a_N*2, a_TTHR2); fn_erg2 =fn_erg; //<--
			
			fn_TTHAsub(a_TTHA, dLauf, 7);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamr2,"%f\n", fn_erg);                                               // ausgabe von theta  bis s=30000 in datei
			
			//Q [8]
			if(a_THETQ==1) fn_erg= fn_erg1-fn_erg2; //S1-S2 
			if(a_THETQ==2) fn_erg= fn_erg1/fn_erg2; //S1/S2
			if(a_THETQ==3) fn_erg= fn_erg1+fn_erg2; //S1+S2
			if(a_THETQ==4) fn_erg= fn_erg1*fn_erg2; //S1*S2
			

			fn_TTHAsub(a_TTHA, dLauf, 8);
			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamQ,"%f\n", fn_erg);                                           // ausgabe von theta  bis s=30000 in datei
	
			
			if(dLauf==1)printf("\xC0\xB0\xB1\xB2 s(%i)\r",      iLauf);                               //bildschirmausgabe zähler
			if(dLauf==2)printf("\xC0\xB0\xB1\xB2 s(%i) \r", a_S-iLauf);                               //bildschirmausgabe zähler
			
			
			if(dLauf==1)if(argc >= 18 && a_X > fn_erg) pr_++; //prozentrang von x		 	
		}
		
		if(ds==2)//bei q=D=DV
		{
			q_min[1] = _min[1]/(a_S*(2*(a_M+a_N)));q_max[1] = _max[1]/(a_S*(2*(a_M+a_N)));qqe_[1]=sum[1]/(a_S*(2*(a_M+a_N))); //sub v minimalwert mittelung//sub v maximalwert mittelung //kennwert mittelung 
			
			for(yLauf=2; yLauf<=8; yLauf++)
			{
		 		q_min[yLauf] = _min[yLauf]/(a_S); 
				q_max[yLauf] = _max[yLauf]/(a_S); 
				qqe_[yLauf]  =  sum[yLauf]/(a_S);           //sub Q minimalwert mittelung//sub Q maximalwert mittelung //kennwert mittelung 
			}
			
			seed= seed1;
  
		}
	}
	
	fn_TTHA(a_TTHA);   //

	if (argc >= 18) pr_=(pr_/(a_S))*100;
	
	//bildschirmausgabe
	                printf("\r\xC0\xB4P( %.2f, %.2f), %s(%s)= %.2f",               min__[1], max__[1], ttha, thetp,  qqe_[1]); 
	                printf("\n \xB3");
	                printf("\n \xC0\xB4S11( %.2f, %.2f), %s(%s)= %.2f",            min__[2], max__[2], ttha, thets11,qqe_[2]); 
	                printf("\n \xB3\xB3S12( %.2f, %.2f), %s(%s)= %.2f",            min__[3], max__[3], ttha, thets12,qqe_[3]);
	                printf("\n \xB3\xC0\x10r1( %.2f, %.2f), %s(%s)= %.2f",         min__[6], max__[6], ttha, tthr1,  qqe_[6]);
	                printf("\n \xB3");
					printf("\n \xC0\xB4S21( %.2f, %.2f), %s(%s)= %.2f",            min__[4], max__[4], ttha, thets21,qqe_[4]); 
	                printf("\n  \xB3S22( %.2f, %.2f), %s(%s)= %.2f",               min__[5], max__[5], ttha, thets22,qqe_[5]);
	                printf("\n  \xC0\x10r2( %.2f, %.2f), %s(%s)= %.2f",            min__[7], max__[7], ttha, tthr2,  qqe_[7]);
					printf("\n   \xB3");
					printf("\n   \xC0\x10Q( %.2f, %.2f), %s(%s)= %.2f",            min__[8], max__[8], ttha, thetq,  qqe_[8]);
	if(argc >= 18 ) printf(", PR(%.2f)= %.2f",                                     a_X, pr_);
	

	
	//log ausgabe
			       fprintf(logStream,"\n:R\t%s\tv\t\t%.3f\t\t%.3f",                thetp,    q_min[1], q_max[1] );
	               fprintf(logStream,"\nP\t\ts(n+m)\t%.3f\t\t%.3f\t\t%.3f",        min__[1], max__[1],  qqe_[1] );
	               fprintf(logStream,"\n:P\t%s\tm\t\t%.3f\t\t%.3f",                thets11,  q_min[2], q_max[2] );
	               fprintf(logStream,"\nS11\t\ts\t%.3f\t\t%.3f\t\t%.3f",           min__[2], max__[2],  qqe_[2] );
	               fprintf(logStream,"\n:P\t%s\tm\t\t%.3f\t\t%.3f",                thets12,  q_min[3], q_max[3] );
	               fprintf(logStream,"\nS12\t\ts\t%.3f\t\t%.3f\t\t%.3f",           min__[3], max__[3],  qqe_[3] );
				   fprintf(logStream,"\n:P\t%s\tn\t\t%.3f\t\t%.3f",                thets21,  q_min[4], q_max[4] );
	               fprintf(logStream,"\nS21\t\ts\t%.3f\t\t%.3f\t\t%.3f",           min__[4], max__[4],  qqe_[4] );
	               fprintf(logStream,"\n:P\t%s\tn\t\t%.3f\t\t%.3f",                thets22,  q_min[5], q_max[5] );
	               fprintf(logStream,"\nS22\t\ts\t%.3f\t\t%.3f\t\t%.3f",           min__[5], max__[5],  qqe_[5] );            
				   fprintf(logStream,"\nr1\t%s\ts\t%.3f\t\t%.3f\t\t%.3f",            tthr1,    min__[6], max__[6],  qqe_[6] );				   
				   fprintf(logStream,"\nr2\t%s\ts\t%.3f\t\t%.3f\t\t%.3f",            tthr2,    min__[7], max__[7],  qqe_[7] );				   
				   fprintf(logStream,"\nQ\t%s\ts\t%.3f\t\t%.3f\t\t%.3f",           thetq,    min__[8], max__[8],  qqe_[8]);
	if (argc >= 18)fprintf(logStream, "\t%.3f",                                    pr_);
	               fprintf(logStream, "\n");
	               for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 18)for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	               fprintf(logStream, "\n\x95\n\n");
	
	//bildschirmausgabe
	printf("\n\ncall bearb_.bat\n"); 
	printf("edit Theta_rQ.xls\n");
	
	fclose(outStreamR);
	fclose(outStreamP);
	fclose(outStreamS11);
	fclose(outStreamS12);
	fclose(outStreamS21);
	fclose(outStreamS22);
	fclose(outStreamr1);
	fclose(outStreamr2);
	fclose(outStreamQ);
	fclose(logStream);

	getch();

	//system("start Theta_rQ_log.txt");
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

	if (sw==2)for(mLauf=1;mLauf<=a_M;mLauf++) 
	{
		if(s11_wert[mLauf]<min_[sw]) min_[sw]= s11_wert[mLauf];//sub 1 minimalwert bestimmung
		if(s11_wert[mLauf]>max_[sw]) max_[sw]= s11_wert[mLauf];//sub 1 maximalwert bestimmung
	}

	if (sw==3)for(mLauf=1;mLauf<=a_M;mLauf++) 
	{
		if(s12_wert[mLauf]<min_[sw]) min_[sw]= s12_wert[mLauf];//sub 2 minimalwert bestimmung
		if(s12_wert[mLauf]>max_[sw]) max_[sw]= s12_wert[mLauf];//sub 2 maximalwert bestimmung
	}

	if (sw==4)for(mLauf=1;mLauf<=a_N;mLauf++) 
	{
		if(s21_wert[mLauf]<min_[sw]) min_[sw]= s21_wert[mLauf];//sub 1 minimalwert bestimmung
		if(s21_wert[mLauf]>max_[sw]) max_[sw]= s21_wert[mLauf];//sub 1 maximalwert bestimmung
	}

	if (sw==5)for(mLauf=1;mLauf<=a_N;mLauf++) 
	{
		if(s22_wert[mLauf]<min_[sw]) min_[sw]= s22_wert[mLauf];//sub 2 minimalwert bestimmung
		if(s22_wert[mLauf]>max_[sw]) max_[sw]= s22_wert[mLauf];//sub 2 maximalwert bestimmung
	}

}