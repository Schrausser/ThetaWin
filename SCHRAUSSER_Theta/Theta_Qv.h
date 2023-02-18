//----------------------------------------------------------------------------------------------------|Theta_Qv.h (c) SCHRAUSSER 2009
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void fn_TTHAsub(int sw, int sw1, int sw3);
void fn_TTHA(int sw);

void profil();
void kopf();

double fn_erg, fn_erg1, fn_erg2;
double seed, seed1;
double zf_wert[200], s_wert[200], s1_wert[200], s2_wert[200], sr_wert[200], Q_wert[200];

int a_TTHA, a_THETP, a_THETS1, a_THETS2, a_THETQ, a_THETQQ, sw4, sw6=0, iLauf; 
 
int a_V;
int a_M;
int a_N;
int a_S;

double   a_MAX, a_MIN, _S[5], d_[5], d_sum[5], sum[5], sum2[5], qqe_[5];

int _SmiN[5]; double _min[5], _min2[5], min_[5], min__[5], d_min[5], d_min_sum[5], q_min[5];      
int _Smax[5]; double _max[5], _max2[5], max_[5], max__[5], d_max[5], d_max_sum[5], q_max[5];

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
	double sd, sd_sum=0, n1=0;//pw
	
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
				if(theta==3 ||theta==4) {sd=fn_erg - wert[iLauf]; sd_sum += pow(sd,2);}														
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
};

//Lineare Regressionsfunktion (f(x=y)=bx+a, b=B1y_, a=B0y_; f(y=x)=by+a, b=B1x_, a=B0x_;) 
double fn_lin_reg(double wert[2000]/*Regressionsmatrix R(x,y)*/, int n/*nR*/, int koef)
																						// Korrelation(1), KOR x11,x12, ... ,xn1,xn2
																						// Kovarianz(2), COV x11,x12, ... ,xn1,xn2
																						// Determinationskoeffizient(3), DET x11,x12, ... ,xn1,xn2
																						// Redundanz(4), RED x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent ayx (5), AYX x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent byx (6), BYX x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent axy (7), AXY x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent bxy (8), BXY x11,x12, ... ,xn1,xn2
{
	int iLauf; 
	double sum_x=0 ,sum_y=0, sum_y2=0, sum_x2=0, sum_xy=0, am_x, am_y, s2_x=0, s2_y=0, s_x, s_y, r_=0;
	double B1x_, B1y_, B0x_, B0y_;  
	
	for (iLauf = 1; iLauf <= n; iLauf+=2)// summierung x, y, y2, xy über n
	{
		sum_x  +=     wert[iLauf]; 
		sum_y  +=     wert[iLauf+1];
		sum_x2 += pow(wert[iLauf],2);
		sum_y2 += pow(wert[iLauf+1],2); 
		sum_xy +=     wert[iLauf]*wert[iLauf+1];
	}
	
	//mittelung
	am_x = sum_x / (n/2);
	am_y = sum_y / (n/2);

	for (iLauf = 1; iLauf <= n; iLauf+=2)//standardabweichungsberechnung (nb s unkorrigiert nach df)
	{
		s2_x  +=    pow(wert[iLauf]-am_x,2);
		s2_y  +=    pow(wert[iLauf+1]-am_y,2); 
	}

	s_x = sqrt(s2_x/(n/2));
	s_y = sqrt(s2_y/(n/2));

	//beta gewichte
	B1y_ = (((n/2) * sum_xy) - (sum_x * sum_y)) / (((n/2) * sum_x2) - pow(sum_x,2)); // byx
	B1x_ = (((n/2) * sum_xy) - (sum_x * sum_y)) / (((n/2) * sum_y2) - pow(sum_y,2)); // bxy
	
	if(koef==6) fn_erg = B1y_;//BYX / b / b1 / byx / x -> y / f(x) / y = bx
	if(koef==8) fn_erg = B1x_;//BXY / b / b1 / bxy / y -> x / f(y) / x = by
	
	B0y_ = am_y - (B1y_ * am_x);// ayx
	B0x_ = am_x - (B1x_ * am_y);// axy
	
	if(koef==5) fn_erg = B0y_;//AYX / a / b0 / ayx / x -> y / f(x) / y = x + a
	if(koef==7) fn_erg = B0x_;//AXY / a / b0 / axy / y -> x / f(y) / x = y + a
	
	if(koef==1 || koef==3 || koef==4)
	for (iLauf = 1; iLauf <= n; iLauf+=2)//korrelationskoeffizient
	{
		r_ += ((wert[iLauf]-am_x) /s_x) * ((wert[iLauf+1]-am_y) /s_y);	
	}

	if(koef==2)for (iLauf = 1; iLauf <= n; iLauf+=2)//kovarianz
	{
		r_ += (wert[iLauf]-am_x) * (wert[iLauf+1]-am_y);	
	}

	if(koef==1 || koef==2 || koef==3 || koef==4) fn_erg = r_ /(n/2);

	if(koef==3) fn_erg = pow(fn_erg,2); //determinationkoeffizient
	if(koef==4) fn_erg = 100*(pow(fn_erg,2)); //redundanz von y

	return 0;
};

double qzufall(double seed, double min, double max)
{
	double SIGMA = 34.0/45;
	
	fn_erg =		   10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) 
		      - floor( 10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) );
	
	fn_erg= min + (max-min)*fn_erg;
	
	return fn_erg;
};


void fn_TTHAsub(int sw, int sw1, int sw3)
{
	if (sw3==1) sw4=(a_N*2);
    if (sw3>=2) sw4=1;
	
	if(sw3<=3 || sw6<5)
	{
		if(sw == 0)                       { _min[sw3] +=   1/min_[sw3];              _max[sw3] +=   1/max_[sw3];                         }         //sub v 1/minimal-, 1/maximalwert summierung 
		if(sw >= 1 && sw <= 4 || sw >= 7) { _min[sw3] +=     min_[sw3];              _max[sw3] +=     max_[sw3];                         }         //sub v minimal-, maximalwert summierung 
		if(sw == 3 || sw == 4)            { _min2[sw3]+= pow(min_[sw3],2);           _max2[sw3]+= pow(max_[sw3],2);                      }         //sub v minimal-, maximalwert quadriert summierung
		if(sw == 5)                       { _min[sw3] *=     min_[sw3];              _max[sw3] *=     max_[sw3];                         }         //sub v minimal-, maximalwert produkt 
		if(sw == 6)                       { _min[sw3] *= pow(min_[sw3],1.0/a_S*sw4); _max[sw3] *= pow(max_[sw3],1.0/a_S*sw4);            }         //sub v wurzel minimal-, wurzel maximalwert produkt

		if(sw1==2 && sw >= 7)             { d_min[sw3] = q_min[sw3]-fn_erg; d_min_sum[sw3] += fabs(d_min[sw3]); if(d_min[sw3] != 0) _SmiN[sw3]++;} //am sub v minimal diff summierung
		if(sw1==2 && sw >= 7)             { d_max[sw3] = q_max[sw3]-fn_erg; d_max_sum[sw3] += fabs(d_max[sw3]); if(d_max[sw3] != 0) _Smax[sw3]++;} //am sub v minimal diff summierung
	
	
		if (sw3==1)  stat_theta(zf_wert,a_V,a_THETP);                                                                                               //pop kennwert berechnung
		if (sw3==2)  stat_theta(s1_wert,a_N,a_THETS1);    
		if (sw3==3)  stat_theta(s2_wert,a_N,a_THETS2);     
		if (sw3==4)  stat_theta( Q_wert,a_N,a_THETQQ);   
	}
	
	if (sw3==4)if(iLauf==1)                 { min__[sw3]=fn_erg; max__[sw3]=fn_erg;}  
	
	if(fn_erg<min__[sw3])                           min__[sw3]= fn_erg;                                                                        //minimalwert bestimmung
	if(fn_erg>max__[sw3])                           max__[sw3]= fn_erg;                                                                        //maximalwert bestimmung
	
	if(sw == 0)                                   sum[sw3] += 1/fn_erg;                                                                        //1/kennwert summierung 
	if(sw >= 1 && sw <= 4 || sw >= 7)               sum[sw3] += fn_erg;                                                                        //kennwert summierung 
	if(sw == 3 || sw == 4)                     sum2[sw3] += pow(fn_erg,2);                                                                     //kennwert quadriert summierung
	if(sw == 5)                                     sum[sw3] *= fn_erg;                                                                        //kennwert produkt
	if(sw == 6)                                 sum[sw3] *= pow(fn_erg,1.0/a_S*sw4);                                                      //wurzel kennwert produkt
	
	if(sw1==2 && sw >= 7)                    {d_[sw3]=qqe_[sw3]-fn_erg; d_sum[sw3] += fabs(d_[sw3]); if(d_[sw3] != 0) _S[sw3]++;}              //am kennwert diff summierung 
}


void fn_TTHA(int sw)
{
	int i, sw5=1;

	for (i=1; i<=4; i++)
	{
		if(i==1) sw4=(a_N*2);
		if(i>=2) {sw4=1; sw5=0;} 
		
		if(sw == 0)                         q_min[i] = (a_S*sw4)/_min[i];                                                             //sub v,m 1/minimalwert mittelung
		if(sw == 0)                         q_max[i] = (a_S*sw4)/_max[i];                                                             //sub v,m 1/maximalwert mittelung
		if(sw == 1)                         q_min[i] =           _min[i]/(a_S*sw4);                                                   //sub v,m minimalwert mittelung
		if(sw == 1)                         q_max[i] =           _max[i]/(a_S*sw4);                                                   //sub v,m maximalwert mittelung
		if(sw == 2 || sw == 5 || sw == 6) { q_min[i] = _min[i]; q_max[i] = _max[i];}                                                  //direkt
		if(sw == 3)                         q_min[i] =       pow(_min2[i]/(a_S*sw4)-pow(_min[i]/(a_S*sw4),2),0.5);                    //sub v,m minimalwert sd ermittelung
		if(sw == 3)                         q_max[i] =       pow(_max2[i]/(a_S*sw4)-pow(_max[i]/(a_S*sw4),2),0.5);                    //sub v,m minimalwert sd ermittelung
		if(sw == 4)                         q_min[i] =          (_min2[i]/(a_S*sw4)-pow(_min[i]/(a_S*sw4),2))*(a_S*sw4/(a_S*sw4-sw5));  //sub v,m minimalwert var ermittelung
		if(sw == 4)                         q_max[i] =          (_max2[i]/(a_S*sw4)-pow(_max[i]/(a_S*sw4),2))*(a_S*sw4/(a_S*sw4-sw5));  //sub v,m minimalwert var ermittelung
		if(sw == 7 || sw == 8)              q_min[i] =          d_min_sum[i]/(_SmiN[i]);                                              //sub v,m minimalwert mittelung
		if(sw == 7 || sw == 8)              q_max[i] =          d_max_sum[i]/(_Smax[i]);                                              //sub v,m minimalwert mittelung
		if(sw == 8)                       { q_min[i]=       pow(q_min[i]/0.7955556,0.5); q_max[i]=pow(q_max[i]/0.7955556,0.5);}       //sub v,m min max dvaro berechnung
	
		if(sw == 0)                         qqe_[i]=  (a_S*sw4)/sum[i];                                                               //kennwert mittelung
		if(sw == 1)                         qqe_[i]=            sum[i]/(a_S*sw4);                                                     //kennwert mittelung
		if(sw == 2 || sw == 5 || sw == 6)   qqe_[i]=            sum[i];                                                               //direkt
		if(sw == 3)                         qqe_[i]=        pow(sum2[i]/(a_S*sw4)-pow(sum[i]/(a_S*sw4),2),0.5);                       //sd ermittelung
		if(sw == 4)                         qqe_[i]=           (sum2[i]/(a_S*sw4)-pow(sum[i]/(a_S*sw4),2))*(a_S*sw4/(a_S*sw4-1));     //var ermittelung
		if(sw == 7 || sw == 8)              qqe_[i]=          d_sum[i]/(_S[i]);                                                       //kennwert mittelung
		if(sw == 8)                       { qqe_[i]=pow(qqe_[i]/0.7955556,0.5); }                                                     //dvaro berechnung
	}
}

void profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=77; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: Theta_Qv [sd][min][max][qq][qp][qs1][qs2][qQ][QQ][v][n][s] [[x]] [[g]]\n");
	printf(" [sd]  ........................... Seed: |0| Zeitwert \n");
	printf(" [min] ........................... R Minimalwert\n");
	printf(" [max] ........................... R Maximalwert\n");
	printf(" [qq]  ........................... Theta-Theta/\n");
	printf(" [qp]  ........................... Theta P/\n");
	printf(" [qs1][qs2]....................... Theta S1, S2/\n");
	printf(" [qQ]  ........................... Theta Q:\n");
	printf("                                    |0| Harmonisches Mittel (HM)\n");
	printf("                                    |1| Arithmetisches Mittel (AM)\n");
	printf("                                    |2| Summe (SUM)\n");
	printf("                                    |3| Standardabweichung (SD)\n");
	printf("                                    |4| Populationsvarianzschaetzung (VAR)\n");
	printf("                                    |5| Produktsumme(PSM) \n");
	printf("                                    |6| Geometrisches Mittel(GM)\n");
	printf("                                    |7| Schrausser's d (D)\n");
	printf("                                    |8| DvarO (DV)\n");
	printf(" [QQ]  ........................... Theta Theta Q:\n");
	printf("                                    |1| Differenz\n");
	printf("                                    |2| Quotient\n");
	printf("                                    |3| Summe\n");
	printf("                                    |4| Produkt\n");
	printf("                                    |5| Korrelation\n");
	printf("                                    |6| Kovarianz\n");
	printf("                                    |7| Determinationskoeffizient\n");
	printf("                                    |8| Redundanz\n");
	printf(" [v]  ...........................  n zu Theta P (v)\n");
	printf(" [n]  ...........................  n zu Theta S1,S2 (n)\n");
	printf(" [s]  ...........................  n Subpopulationen (s)\n");
	printf(" [x]  ...........................  Vergleichswert x\n");
	printf(" [g]  ...........................  |1| Wertebereich ganzzahlig\n");
	for(iLauf=1; iLauf<=77; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Theta_Qv by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	getch();
	
	exit(0);
}	

void kopf() 
{
	printf("\nTheta_Qv by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Theta_Qv:\n\n"); 
}
