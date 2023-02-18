//----------------------------------------------------------------------------------------------------|Theta_S (c) SCHRAUSSER 2009

#include "Theta_S.h"

void fn_minwert(int sw);
void fn_data(int sw);

FILE *outStreamR, *outStreamP, *outStreamS, *logStream;

void main(int argc, char *argv[])
{
	
    
	int  iLauf, jLauf, sLauf, dLauf, i;
	
	int    ds=1;  //SCHRAUSSER d, dvaro berechnungs durchlauf indikator
	int    a_GZ;  //ganzzahlig indikator
	double a_SD;  //seed 
    double a_X;   //vergleichswert 
	double pr_=0; //prozentrang

	char dbuffer [9],tbuffer [9], thetp[5], thets[5], ttha[5];

	if (argc < 10) profil();

	for(i=1; i<=2; i++)  
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


	                a_SD    = atof(argv[1]);
	                a_MIN   = atof(argv[2]);
	                a_MAX   = atof(argv[3]);
	                a_TTHA  = atoi(argv[4]);
					a_THETP = atoi(argv[5]);
	                a_THETS = atoi(argv[6]);
	                a_V     = atoi(argv[7]);
	                a_M     = atoi(argv[8]);
	                a_S     = atoi(argv[9]);
	if (argc >= 11) a_X     = atof(argv[10]);
	if (argc == 12) a_GZ    = atoi(argv[11]);

	if (a_THETP == 0 ) strcpy(thetp, "HM");		if (a_THETS == 0 ) strcpy(thets, "HM");
	if (a_THETP == 1 ) strcpy(thetp, "AM");		if (a_THETS == 1 ) strcpy(thets, "AM");
	if (a_THETP == 2 ) strcpy(thetp, "SUM");	if (a_THETS == 2 ) strcpy(thets, "SUM");
	if (a_THETP == 3 ) strcpy(thetp, "SD");		if (a_THETS == 3 ) strcpy(thets, "SD");
	if (a_THETP == 4 ) strcpy(thetp, "VAR");	if (a_THETS == 4 ) strcpy(thets, "VAR");
	if (a_THETP == 5 ) strcpy(thetp, "PSUM");	if (a_THETS == 5 ) strcpy(thets, "PSUM");
	if (a_THETP == 6 ) strcpy(thetp, "GM");		if (a_THETS == 6 ) strcpy(thets, "GM");
	if (a_THETP == 7 ) strcpy(thetp, "D");		if (a_THETS == 7 ) strcpy(thets, "D");
	if (a_THETP == 8 ) strcpy(thetp, "DV");		if (a_THETS == 8 ) strcpy(thets, "DV");
	
	if (a_TTHA == 0 )  strcpy(ttha, "HM");
	if (a_TTHA == 1 )  strcpy(ttha, "AM");
	if (a_TTHA == 2 )  strcpy(ttha, "SUM");
	if (a_TTHA == 3 )  strcpy(ttha, "SD");
	if (a_TTHA == 4 )  strcpy(ttha, "VAR");
	if (a_TTHA == 5 ) {strcpy(ttha, "PSUM"); _min[1] = _max[1] = sum[1] = 1; _min[2] = _max[2] = sum[2] = 1;}
	if (a_TTHA == 6 ) {strcpy(ttha, "GM");   _min[1] = _max[1] = sum[1] = 1; _min[2] = _max[2] = sum[2] = 1;}
	if (a_TTHA == 7 ) {strcpy(ttha, "D");    ds=2;}
	if (a_TTHA == 8 ) {strcpy(ttha, "DV");   ds=2;}

	if(a_SD == 0)
	{
		       seed1=time(0)-1234567890;
		seed=  seed1-(floor(seed1/10000))*10000;
	}
	else { seed= a_SD; }

	seed1=seed;

	min__[1]= a_MAX; min__[2]= a_MAX; //sic
	max__[1]= a_MIN; max__[2]= a_MIN;
	
	outStreamR = fopen( "Theta_S_R.txt",   "w" );
	outStreamP = fopen( "Theta_S_P.txt",   "w" );
	outStreamS = fopen( "Theta_S_S.txt",   "w" );
	logStream  = fopen( "Theta_S_log.txt", "a" );
	
	kopf();
	
	//bildschirmausgabe
	if(argc == 12 && a_GZ==1) printf("gW "); 
	                          printf("seed= %.0f, v= %i, m= %i, s= %i, q= %s\n\n",                seed, a_V, a_M, a_S, ttha );
	                          printf("R( %.2f, %.2f)\n",                                          a_MIN, a_MAX);
	                          printf("\xC2\n");

	_strdate( dbuffer ); _strtime( tbuffer );
	
	//log ausgabe
	                          fprintf(logStream,"SCHRAUSSER - Theta_S");
	                          fprintf(logStream,"                         ");
	if (argc >= 11)           fprintf(logStream,"            ");
	                          fprintf(logStream,"%s @ %s\n",                                      dbuffer, tbuffer);
	                          fprintf(logStream, "\n");
	if(argc == 12 && a_GZ==1) fprintf(logStream,"Ganzzahlig "); 
	                          fprintf(logStream, "seed= %.0f, v= %i, m= %i, s= %i, q= %s\n",      seed, a_V, a_M, a_S, ttha);
	                          for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 11)           for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	                          fprintf(logStream,"\nEbene\tqE\tN\tmin\tqmin\tmax\tqmax\tqqE"); 
	if (argc >= 11)           fprintf(logStream, "\tPR(%.2f)",                                    a_X);
	                          fprintf(logStream, "\n");
	                          for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 11)           for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	                          fprintf(logStream,"\nR\t\tsmv\t%.3f\t\t%.3f",                       a_MIN, a_MAX );
	


	for(dLauf=1;dLauf<=ds; dLauf++)                                                        //2 fach durchgang bei q=D=DV
	{
		for(iLauf=1;iLauf<=a_S; iLauf++)                                                   //vektorerzeugung über subpopulationen s
		{
			for(sLauf=1;sLauf<=a_M; sLauf++)                                               //vektorerzeugung über m
			{
				for(jLauf=1;jLauf<=a_V; jLauf++)                                           //vektorerzeugung über v
				{
					                          zf_wert[jLauf] = qzufall(seed,a_MIN,a_MAX);  // pop zufallszahl zwischen min und max
					if(argc == 12 && a_GZ==1) zf_wert[jLauf]=floor(zf_wert[jLauf]);        // ganzzahliger wertebereich

					if(dLauf==1)if(iLauf*a_M*a_V<=30000)fprintf(outStreamR,"%f\n", fn_erg); // ausgabe von R bis sv=30000 in datei
				
					seed= fn_erg;
				}//v
				
				// P

							         fn_minwert(1);                                 //minimalwertbestimmung
				if(dLauf==1) 
				if(iLauf*a_M<=30000) fn_data(1);                                    //ausgabe von max/min_v bis s=30000 in datei 
                             
				                     fn_TTHAsub(a_TTHA, dLauf, 1);                  //
			
				if(dLauf==1)if(iLauf*a_M<=30000)fprintf(outStreamP,"%f\n", fn_erg); // ausgabe von theta  bis s=30000 in datei  
					
				s_wert[sLauf] = fn_erg;                                             // subwert-vektor subwert(i) = pop kennwert	
			
			}//m
			
			// S 
			
			                     fn_minwert(2);                                     //minimalwertbestimmung
			if(dLauf==1)
		    if(iLauf<=30000)     fn_data(2);                                        //ausgabe von max/min_m bis s=30000 in datei
		
			fn_TTHAsub(a_TTHA, dLauf, 2);                                           //
 
			
			if(dLauf==1)printf("\xC0\xB0\xB1 s(%i)\r",      iLauf);                 //bildschirmausgabe zähler
			if(dLauf==2)printf("\xC0\xB0\xB1 s(%i) \r", a_S-iLauf);                 //

			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamS,"%f\n", fn_erg);         //ausgabe von theta  bis s=30000 in datei  

			if(dLauf==1)if(argc >= 11 && a_X > fn_erg) pr_++;                                   //prozentrang von x		 	
		
		}//s
		
		
		if(ds==2)                                                                               //bei q=D=DV
		{
			q_min[1]= _min[1]/(a_S*a_M); q_max[1]= _max[1]/(a_S*a_M); qqe_[1]=sum[1]/(a_S*a_M); //sub v min/max / kennwert mittelung                                           
			q_min[2] =_min[2]/(a_S);     q_max[2] =_max[2]/(a_S);     qqe_[2]=sum[2]/(a_S);     //sub m min/max / kennwert mittelung                                                                                        
			seed= seed1;
		}
	}//dvaro


	fn_TTHA(a_TTHA);   //


	if (argc >= 11) pr_=(pr_/(a_S))*100;
	
	//bildschirmausgabe
	                printf("\r\xC0\xB4P( %.2f, %.2f), %s(%s)= %.2f",          min__[1], max__[1], ttha, thetp, qqe_[1]); 
	                printf("\n \xB3");
	                printf("\n \xC0\x10S( %.2f, %.2f), %s(%s)= %.2f",         min__[2], max__[2], ttha, thets, qqe_[2]); 
	if(argc >= 11 ) printf(", PR(%.2f)= %.2f",                                a_X, pr_);
	
	//log ausgabe
	                fprintf(logStream,"\n:R\t%s\tv\t\t%.3f\t\t%.3f",          thetp,    q_min[1], q_max[1]  );
	                fprintf(logStream,"\nP\t\tsm\t%.3f\t\t%.3f\t\t%.3f",      min__[1], max__[1],  qqe_[1]  );
	                fprintf(logStream,"\n:P\t%s\tm\t\t%.3f\t\t%.3f",          thets,    q_min[2], q_max[2]  );
	                fprintf(logStream,"\nS\t\ts\t%.3f\t\t%.3f\t\t%.3f",       min__[2], max__[2],  qqe_[2]  );
	if (argc >= 11) fprintf(logStream, "\t%.3f",                              pr_                           );
	                fprintf(logStream, "\n");
	                for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 11) for(iLauf=1; iLauf<=12; iLauf++) fprintf(logStream,"\x97");
	                fprintf(logStream, "\n\x95\n\n");
	
	//bildschirmausgabe
	printf("\n\ncall bearb_.bat\n"); 
	printf("edit Theta_S.xls\n");
	
	fclose(outStreamR);
	fclose(outStreamP);
	fclose(outStreamS);
	fclose(logStream);

	getch();

	//system("start Theta_S_log.txt");
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
		if(s_wert[mLauf]<min_[sw]) min_[sw]= s_wert[mLauf];//sub m minimalwert bestimmung
		if(s_wert[mLauf]>max_[sw]) max_[sw]= s_wert[mLauf];//sub m maximalwert bestimmung
	}
}

void fn_data(int sw)
{
	if(sw==1) fprintf(outStreamP,"%f\t%f\t", min_[1], max_[1]); // ausgabe von min_v/max_v bis s=30000 in datei  
	if(sw==2) fprintf(outStreamS,"%f\t%f\t", min_[2], max_[2]); // ausgabe von min_m/max_m bis s=30000 in datei 
}