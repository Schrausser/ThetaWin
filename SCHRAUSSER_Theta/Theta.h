//----------------------------------------------------------------------------------------------------|Theta.h (c) SCHRAUSSER 2009
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void profil();
void kopf();
void fn_TTHAsub(int sw, int sw1);
void fn_TTHA(int sw);

double fn_erg;
double seed, seed1;
double zf_wert[2000];

int  a_TTHA, a_THETA, _S=0;

int  a_V;
int  a_S;

int _Smin=0; double  a_MIN, min_, d_min, d_min_sum=0, min_v,  v_min=0,  v_min2=0, qv_min, s_v_min=0;
int _Smax=0; double  a_MAX, max_, d_max, d_max_sum=0, max_v,  v_max=0,  v_max2=0, qv_max, s_v_max=0;

double  sum=0, sum2=0, d_, d_sum=0, qqe_;



double stat_theta(double wert[2000], int n, int theta)	// Harmonisches Mittel(0), HM_ x1,x2, ... ,xn
														// Arithmetisches Mittel(1), AM_ x1,x2, ... ,xn
														// Summe(2) // SUM  x1,x2, ... ,xn
														// Standardabweichung(3) // SD  x1,x2, ... ,xn
														// Populationsvarianzschätzung(4) // VAR  x1,x2, ... ,xn
														// Produktsumme(5) // PSUM  x1,x2, ... ,xn
														// Geometrisches Mittel(6) // GM_  x1,x2, ... ,xn
													    // Schrausser's d(7) // D__  x1,x2, ... ,xn
														// DvarO(8) // DVARO  x1,x2, ... ,xn
{
	int iLauf; 
	double sd, sd_sum=0, n1=0;//pw,
	
	if(theta<5 || theta >6) 
	{
		fn_erg=0;
		
		for(iLauf=1; iLauf<=n; iLauf++) //summierung
		{
			if(theta >= 1) fn_erg += wert[iLauf];
			if(theta == 0) fn_erg += 1/wert[iLauf];
		}
	
		if(theta==0) fn_erg = n/fn_erg;//HM mittelung
		if(theta==1) fn_erg = fn_erg/n;//AM mittelung
		if(theta==3 || theta==4 || theta>=7)//SD / pop VAR schätzer
		{
			fn_erg = fn_erg/n;
			for(iLauf=1; iLauf<=n; iLauf++) 
			{
				if(theta==3 ||theta== 4) {sd=fn_erg - wert[iLauf]; sd_sum += pow(sd,2);}
				if(theta==7 ||theta==8) {sd=fn_erg - wert[iLauf]; sd_sum += fabs(sd); if(sd != 0) n1++;} 
			}

			if(theta==3) fn_erg = pow(sd_sum/n,0.5);
			if(theta==4) fn_erg = sd_sum/(n-1);
			if(theta==7 ||theta==8) fn_erg = sd_sum/n1;
			if(theta==8) {fn_erg=fn_erg/0.7955556; fn_erg = pow(fn_erg,0.5);}
		}
	}

	if(theta==5 || theta==6) 
	{
		fn_erg=1;
		if(theta==5)for(iLauf=1; iLauf<=n; iLauf++) fn_erg *= wert[iLauf];//produktsumme
		//if(theta==6) {pw=1.0/n;fn_erg = pow(fn_erg,pw);}//gm
		if(theta==6)for(iLauf=1; iLauf<=n; iLauf++) fn_erg *= pow(wert[iLauf],1.0/n);//GM
	}
	
	return 0;
}

double qzufall(double seed, double min, double max)
{
	double SIGMA = 34.0/45;
	
	fn_erg =		   10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) 
		      - floor( 10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) );
	
	fn_erg= min + (max-min)*fn_erg;
	
	return fn_erg;
}


void fn_TTHAsub(int sw, int sw1)
{
	// minimal- maximalwert Theta berechnung
	
	if(sw == 0)                      { v_min  +=   1/min_v;          v_max  +=   1/max_v;          }           //sub v 1/minimal-, 1/maximalwert summierung 
	if((sw >= 1 && sw <= 4) || (sw1==1 && sw >= 7)){ v_min  +=     min_v;          v_max  +=     max_v;          }           //sub v minimal-, maximalwert summierung 
	if(sw == 3 || sw == 4)           { v_min2 += pow(min_v,2);       v_max2 += pow(max_v,2);       }           //sub v minimal-, maximalwert quadriert summierung
	if(sw == 5)                      { v_min  *=     min_v;          v_max  *=     max_v;          }           //sub v minimal-, maximalwert produkt 
	if(sw == 6)                      { v_min  *= pow(min_v,1.0/a_S); v_max  *= pow(max_v,1.0/a_S); }           //sub v wurzel minimal-, wurzel maximalwert produkt
	
	if(sw1==2 && sw >= 7)            { d_min=qv_min-fn_erg; d_min_sum += fabs(d_min); if(d_min != 0) _Smin++;} //am sub v minimal diff summierung
	if(sw1==2 && sw >= 7)            { d_max=qv_max-fn_erg; d_max_sum += fabs(d_max); if(d_max != 0) _Smax++;} //am sub v minimal diff summierung
	
    // Theta berechnung

	stat_theta(zf_wert,a_V,a_THETA);//> Theta in fn_erg 
	                                //           vvvvvv

	if(fn_erg<min_)                        min_= fn_erg;                                        //minimalwert bestimmung
	if(fn_erg>max_)                        max_= fn_erg;                                        //maximalwert bestimmung
	                                           
	if(sw == 0)                       sum +=   1/fn_erg;                                        //1/kennwert summierung 
	if((sw >= 1 && sw <= 4) || (sw1==1 && sw >= 7))  sum +=     fn_erg;                                        //kennwert summierung 
	if(sw == 3 || sw == 4)            sum2+= pow(fn_erg,2);                                     //kennwert quadriert summierung
	if(sw == 5)                       sum *=     fn_erg;                                        //kennwert produkt
	if(sw == 6)                       sum *= pow(fn_erg,1.0/a_S);                               //wurzel kennwert produkt
	
	if(sw1==2 && sw >= 7)           {    d_=qqe_-fn_erg; d_sum += fabs(d_); if(d_ != 0) _S++; } //am kennwert diff summierung 
                                               //^^^^^^

}


void fn_TTHA(int sw)
{
	// Theta THETA berechnung
	
	if(sw == 0)                         qv_min = (a_S)/v_min;                                                   //sub v 1/minimalwert mittelung
	if(sw == 0)                         qv_max = (a_S)/v_max;                                                   //sub v 1/maximalwert mittelung
	if(sw == 1)                         qv_min =       v_min/(a_S);                                             //sub v minimalwert mittelung
	if(sw == 1)                         qv_max =       v_max/(a_S);                                             //sub v maximalwert mittelung
	if(sw == 2 || sw == 5 || sw == 6) { qv_min = v_min; qv_max = v_max;}                                        //direkt
	if(sw == 3)                         qv_min =   pow(v_min2/(a_S)-pow(v_min/(a_S),2),0.5);                    //sub v minimalwert sd ermittelung
	if(sw == 3)                         qv_max =   pow(v_max2/(a_S)-pow(v_max/(a_S),2),0.5);                    //sub v minimalwert sd ermittelung
	if(sw == 4)                         qv_min =      (v_min2/(a_S)-pow(v_min/(a_S),2))*(a_S/(a_S-1));          //sub v minimalwert var ermittelung
	if(sw == 4)                         qv_max =      (v_max2/(a_S)-pow(v_max/(a_S),2))*(a_S/(a_S-1));          //sub v minimalwert var ermittelung
	if(sw == 7 || sw == 8)              qv_min =       d_min_sum/(_Smin);                                       //sub v minimalwert mittelung
	if(sw == 7 || sw == 8)              qv_max =       d_max_sum/(_Smax);                                       //sub v minimalwert mittelung
	if(sw == 8)                       { qv_min =  pow(qv_min/0.7955556,0.5); qv_max=pow(qv_max/0.7955556,0.5);} //sub v min max dvaro berechnung

	if(sw == 0)                         qqe_ =              (a_S)/sum;                                          //kennwert mittelung
	if(sw == 1)                         qqe_ =                    sum/(a_S);                                    //kennwert mittelung
	if(sw == 2 || sw == 5 || sw == 6)   qqe_ =                    sum;                                          //direkt
	if(sw == 3)                         qqe_ = pow(sum2/(a_S)-pow(sum/(a_S),2),0.5);                            //sd ermittelung
	if(sw == 4)                         qqe_ =    (sum2/(a_S)-pow(sum/(a_S),2))*(a_S/(a_S-1));                  //var ermittelung
	if(sw == 7 || sw == 8)              qqe_ =                  d_sum/(_S);                                     //kennwert mittelung
	if(sw == 8)                       { qqe_ = pow(qqe_/0.7955556,0.5);}                                        //dvaro berechnung
}


void profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=58; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: Theta [sd] [min] [max] [qq] [q] [v] [s] [[x]] [[g]]\n");
	printf(" [sd]  ........... Seed: |0| Zeitwert \n");
	printf(" [min] ........... R Minimalwert\n");
	printf(" [max] ........... R Maximalwert\n");
	printf(" [qq]  ........... Theta-Theta/\n");
	printf(" [q]   ........... Theta: \n");
	printf("                    |0| Harmonisches Mittel (HM)\n");
	printf("                    |1| Arithmetisches Mittel (AM)\n");
	printf("                    |2| Summe (SUM)\n");
	printf("                    |3| Standardabweichung (SD)\n");
	printf("                    |4| Populationsvarianzschaetzung (VAR)\n");
	printf("                    |5| Produktsumme(PSM) \n");
	printf("                    |6| Geometrisches Mittel(GM)\n");
	printf("                    |7| Schrausser's d (D)\n");
	printf("                    |8| DvarO (DV)\n");
	printf(" [v]  ...........  n zu Theta (v)\n");
	printf(" [s]  ...........  n Subpopulationen (s)\n");
	printf(" [x]  ...........  Vergleichswert x\n");
	printf(" [g]  ...........  |1| Wertebereich ganzzahlig\n");
	for(iLauf=1; iLauf<=58; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Theta by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	getch();

	exit(0);
}	

void kopf() 
{
	printf("\nTheta by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Theta:\n\n"); 
}