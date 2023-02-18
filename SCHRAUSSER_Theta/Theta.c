//----------------------------------------------------------------------------------------------------|Theta (c) SCHRAUSSER 2009

#include "Theta.h"

void main(int argc, char *argv[])
{
	FILE *outStreamR, *outStreamP,*logStream;

	int  iLauf, jLauf, mLauf, dLauf;
    
	int    ds=1;  //SCHRAUSSER d, dvaro berechnungs durchlauf indikator
	int    a_GZ;  //ganzzahlig indikator
	double a_SD;  //seed 
    double a_X;   //vergleichswert 
	double pr_=0; //prozentrang

	char dbuffer [9], tbuffer [9], theta[5], ttha[5];

	if (argc < 8) profil();

	                a_SD   = atof(argv[1]);
	                a_MIN  = atof(argv[2]);
	                a_MAX  = atof(argv[3]);
	                a_TTHA = atoi(argv[4]);
					a_THETA= atoi(argv[5]);
	                a_V    = atoi(argv[6]);
	                a_S    = atoi(argv[7]);
	if (argc >= 9)  a_X    = atof(argv[8]);
	if (argc == 10) a_GZ   = atoi(argv[9]);

	            if (a_THETA == 0 )  strcpy(theta, "HM");
	            if (a_THETA == 1 )  strcpy(theta, "AM");
	            if (a_THETA == 2 )  strcpy(theta, "SUM");
	            if (a_THETA == 3 )  strcpy(theta, "SD");
	            if (a_THETA == 4 )  strcpy(theta, "VAR");
	            if (a_THETA == 5 )  strcpy(theta, "PSUM");
	            if (a_THETA == 6 )  strcpy(theta, "GM");
	            if (a_THETA == 7 )  strcpy(theta, "D");
	            if (a_THETA == 8 )  strcpy(theta, "DV");
	
	            if (a_TTHA == 0 )   strcpy(ttha, "HM");
	            if (a_TTHA == 1 )   strcpy(ttha, "AM");
	            if (a_TTHA == 2 )   strcpy(ttha, "SUM");
	            if (a_TTHA == 3 )   strcpy(ttha, "SD");
	            if (a_TTHA == 4 )   strcpy(ttha, "VAR");
				if (a_TTHA == 5 ) { strcpy(ttha, "PSUM"); v_min = v_max = sum = 1; }
				if (a_TTHA == 6 ) { strcpy(ttha, "GM");   v_min = v_max = sum = 1; }
				if (a_TTHA == 7 ) { strcpy(ttha, "D");    ds= 2                   ;}
				if (a_TTHA == 8 ) { strcpy(ttha, "DV");   ds= 2                   ;}

	if(a_SD == 0)
	{
		          seed1=time(0)-1234567890;
		   seed = seed1-(floor(seed1/10000))*10000;
	}
	else { seed= a_SD; }

	seed1=seed;
	
	min_= a_MAX; //sic
	max_= a_MIN; 
	
	outStreamR = fopen( "Theta_R.txt",   "w" );
	outStreamP = fopen( "Theta_P.txt",   "w" );
	logStream  = fopen( "Theta_log.txt", "a" );
	
	kopf();
	
	//bildschirmausgabe
	if(argc == 10 && a_GZ==1) printf("gW "); 
	                          printf("seed= %.0f, v= %i, s= %i, q= %s\n\n",                   seed, a_V, a_S, ttha );
	                          printf("R( %.2f, %.2f)\n",                                      a_MIN, a_MAX);
	                          printf("\xC2\n");            

	_strdate( dbuffer ); _strtime( tbuffer );
	
	//log ausgabe
	                          fprintf(logStream,"SCHRAUSSER - Theta");
	                          fprintf(logStream,"                           ");
	if (argc >= 9)            fprintf(logStream,"          ");
	                          fprintf(logStream,"%s @ %s\n",                                  dbuffer, tbuffer);
	                          fprintf(logStream,"\n");
	if(argc == 10 && a_GZ==1) fprintf(logStream,"Ganzzahlig "); 
	                          fprintf(logStream,"seed= %.0f, v= %i, s= %i, q= %s\n",          seed, a_V, a_S, ttha);
	                          for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 9)            for(iLauf=1; iLauf<=10; iLauf++) fprintf(logStream,"\x97");
	                          fprintf(logStream,"\nEbene\tqE\tN\tmin\tqmin\tmax\tqmax\tqqE"); 
	if (argc >= 9)            fprintf(logStream,"\tPR(%.2f)",                                 a_X);
	                          fprintf(logStream, "\n");
	                          for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 9)            for(iLauf=1; iLauf<=10; iLauf++) fprintf(logStream,"\x97");
	                          fprintf(logStream,"\nR\t\tsv\t%.3f\t\t%.3f",                    a_MIN, a_MAX );
	  


	for(dLauf=1;dLauf<=ds; dLauf++)                                                   //2 fach durchgang bei q=D=DV
	{
		for(iLauf=1;iLauf<=a_S; iLauf++)                                              //vektorerzeugung über subpopulationen s
		{
			for(jLauf=1;jLauf<=a_V; jLauf++)	                                      //vektorerzeugung über v
			{
				                          zf_wert[jLauf] = qzufall(seed,a_MIN,a_MAX); //zufallszahl zwischen min und max
				if(argc == 10 && a_GZ==1) zf_wert[jLauf] = floor(zf_wert[jLauf]);     //ganzzahliger wertebereich
				
				if(dLauf==1)if(iLauf*a_V<=30000)fprintf(outStreamR,"%f\n", fn_erg);   //ausgabe von R bis sv=30000 in datei 
				
				seed= fn_erg;	
			}//v
			
			//P
			
			min_v= a_MAX; max_v= a_MIN;
		     
			for(mLauf=1;mLauf<=a_V;mLauf++) 
			{
				if(zf_wert[mLauf]<min_v) min_v= zf_wert[mLauf];                       //sub v minimalwert bestimmung
				if(zf_wert[mLauf]>max_v) max_v= zf_wert[mLauf];                       //sub v maximalwert bestimmung
			}

			if(dLauf==1)if(iLauf<=30000)
			fprintf(outStreamP,"%f\t%f\t", min_v, max_v);                             //ausgabe von min_v max_v bis s=30000 in datei  
			                   
			
			fn_TTHAsub(a_TTHA, dLauf);                                                //min,max theta, Theta berechnung , Theta in fn_erg


			if(dLauf==1)printf("\xC0\xB0 s(%i)\r",      iLauf);                       //bildschirmausgabe zähler
			if(dLauf==2)printf("\xC0\xB0 s(%i) \r", a_S-iLauf);                       //bildschirmausgabe zähler

			if(dLauf==1)if(iLauf<=30000)fprintf(outStreamP,"%f\n", fn_erg);           //ausgabe von theta  bis s=30000 in datei  
                                                                 //^^^^^^
			if(dLauf==1)if(argc >= 9 && a_X >                      fn_erg) pr_++;     //prozentrang von x																																									
		                                                         //^^^^^^
		}//s
			
		if(ds==2 && dLauf==1)                 //bei q=D=DV
		{
			qv_min = v_min/(a_S); //sub v minimalwert mittelung
			qv_max = v_max/(a_S); //sub v maximalwert mittelung
			      qqe_=sum/(a_S); //kennwert mittelung 

			seed= seed1;
		}
	
	}//dvaro
	

    fn_TTHA(a_TTHA);	// Theta THETA berechnung


	if (argc >= 9) pr_=(pr_/(a_S))*100;
	
	//bildschirmausgabe
	               printf("\r\xC0\x10P( %.2f, %.2f), %s(%s)= %.2f",    min_, max_, ttha, theta, qqe_); 
	if(argc >= 9 ) printf(", PR(%.2f)= %.2f",                          a_X, pr_);

	//log ausgabe
	              fprintf(logStream,"\n:R\t%s\tv\t\t%.3f\t\t%.3f",     theta, qv_min, qv_max );
	              fprintf(logStream,"\nP\t\ts\t%.3f\t\t%.3f\t\t%.3f",  min_, max_, qqe_);
	if (argc >= 9)fprintf(logStream, "\t%.3f",                         pr_);
	              fprintf(logStream, "\n");
	              for(iLauf=1; iLauf<=64; iLauf++) fprintf(logStream,"\x97");
	if (argc >= 9)for(iLauf=1; iLauf<=10; iLauf++) fprintf(logStream,"\x97");
	              fprintf(logStream, "\n\x95\n\n");
	
	//bildschirmausgabe
	printf("\n\ncall bearb_.bat\n"); 
	printf("edit Theta.xls\n");
	
	fclose(outStreamR);
	fclose(outStreamP);
	fclose(logStream);

	getch();

	//system("start Theta_log.txt");
	//system("bearb_.bat");
}


