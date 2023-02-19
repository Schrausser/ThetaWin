# ThetaWin
Graphical user interface for SCHRAUSSER Theta (Schrausser, 2009) applications 
generating distributions and estimators for several parameters q within different designs via bootstrap method:

## Theta

    Usage: Theta [sd] [min] [max] [qq] [q] [v] [s] [[x]] [[g]]
     [sd]  ........... Seed: |0| Zeitwert
     [min] ........... R Minimalwert
     [max] ........... R Maximalwert
     [qq]  ........... Theta-Theta/
     [q]   ........... Theta:
                       |0| Harmonisches Mittel (HM)
                       |1| Arithmetisches Mittel (AM)
                       |2| Summe (SUM)
                       |3| Standardabweichung (SD)
                       |4| Populationsvarianzschaetzung (VAR)
                       |5| Produktsumme(PSM)
                       |6| Geometrisches Mittel(GM)
                       |7| Schrausser's d (D)
                       |8| DvarO (DV)
     [v]  ...........  n zu Theta (v)
     [s]  ...........  n Subpopulationen (s)
     [x]  ...........  Vergleichswert x
     [g]  ...........  |1| Wertebereich ganzzahlig

## Theta Q

    Usage: Theta_Q [sd][min][max][qq][qp][qs1][qs2][qQ][v][m][n][s] [[x]] [[g]]
     [sd]  ........................... Seed: |0| Zeitwert
     [min] ........................... R Minimalwert
     [max] ........................... R Maximalwert
     [qq]  ........................... Theta-Theta/
     [qp]  ........................... Theta P/
     [qs1] [qs2] ..................... Theta S1, S2:
                                       |0| Harmonisches Mittel (HM)
                                       |1| Arithmetisches Mittel (AM)
                                       |2| Summe (SUM)
                                       |3| Standardabweichung (SD)
                                       |4| Populationsvarianzschaetzung (VAR)
                                       |5| Produktsumme(PSM)
                                       |6| Geometrisches Mittel(GM)
                                       |7| Schrausser's d (D)
                                       |8| DvarO (DV)
     [qQ]  ........................... Theta Q:
                                       |1| Differenz
                                       |2| Quotient
                                       |3| Summe
                                       |4| Produkt
     [v]  ...........................  n zu Theta P (v)
     [m]  ...........................  n zu Theta S1 (m)
     [n]  ...........................  n zu Theta S2 (n)
     [s]  ...........................  n Subpopulationen (s)
     [x]  ...........................  Vergleichswert x
     [g]  ...........................  |1| Wertebereich ganzzahlig

## Theta Qv

    Usage: Theta_Qv [sd][min][max][qq][qp][qs1][qs2][qQ][QQ][v][n][s] [[x]] [[g]]
     [sd]  ........................... Seed: |0| Zeitwert
     [min] ........................... R Minimalwert
     [max] ........................... R Maximalwert
     [qq]  ........................... Theta-Theta/
     [qp]  ........................... Theta P/
     [qs1][qs2]....................... Theta S1, S2/
     [qQ]  ........................... Theta Q:
                                       |0| Harmonisches Mittel (HM)
                                       |1| Arithmetisches Mittel (AM)
                                       |2| Summe (SUM)
                                       |3| Standardabweichung (SD)
                                       |4| Populationsvarianzschaetzung (VAR)
                                       |5| Produktsumme(PSM)
                                       |6| Geometrisches Mittel(GM)
                                       |7| Schrausser's d (D)
                                       |8| DvarO (DV)
     [QQ]  ........................... Theta Theta Q:
                                       |1| Differenz
                                       |2| Quotient
                                       |3| Summe
                                       |4| Produkt
                                       |5| Korrelation
                                       |6| Kovarianz
                                       |7| Determinationskoeffizient
                                       |8| Redundanz
     [v]  ...........................  n zu Theta P (v)
     [n]  ...........................  n zu Theta S1,S2 (n)
     [s]  ...........................  n Subpopulationen (s)
     [x]  ...........................  Vergleichswert x
     [g]  ...........................  |1| Wertebereich ganzzahlig

## Theta rQ
- |1| Correlation (kor) 
- |2| Covariance (cov) 
- |3| Determinatin coeffizient (det) 
- |4| Redundance (red) 
- |1| Difference (Diff) 
- |2| Quotient (Quot) 
- |3| Sum (Summ) 
- |4| Product (Prod)
### Theta S
Parameters q

## References
Schrausser, D., G. (2009). *SCHRAUSSER Theta*. Academia Draft. https://www.academia.edu/81800920/SCHRAUSSER_Theta
