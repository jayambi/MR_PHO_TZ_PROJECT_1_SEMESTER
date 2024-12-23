/* Abbildungsrechner.c
Disese Programm macht folgendes: 
1. Wahl zur Berechnung von optischen Messgroessen
2. Berechnung der gewaehlte Messgroesse
3. Gibt die Berechnung auf der Konsole aus

Autor: Catherine, Mika und Sebastian
Firma: FHGR
Version 1.0
Datum 14.12.2024
Aenderungen:
V 1.0 14.12.2024 Erste Version

*/

/******************************************************************************
 ** Eingebundene Bibliotheken			                                     **
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/******************************************************************************
 ** Variablen                                                                **
 ******************************************************************************/
float f, a, A, M, y, Y; //Brennweite, Objektweite, Bildweite, Vergroesserung, Objektgroesse, Bildgroesse
int P = 0; //Programmauswahl 

/******************************************************************************
 ** Funktions Prototypen                                                     **
 ******************************************************************************/
void programmAuswahl();
void Berechnung_Optische_Abbildung(float f, float a, float A, float M, float y, float Y, int P);

/******************************************************************************
 ** Hauptfunktion                                                            **
 ******************************************************************************/
int Abbildungsrechner()
{
    while (P != 10){
    programmAuswahl();
    Berechnung_Optische_Abbildung(f, a, A, M, y, Y, P); 
    }
    P = 0;
    return 10;
}
/******************************************************************************
 ** Funktionen                                                               **
 ******************************************************************************/
void programmAuswahl()
{
    printf("Waehlen Sie die zu berechnende Groesse: \n");
    printf("1: Brennweite (f)\n");
    printf("2: Objektweite (a)\n");
    printf("3: Bildweite (A)\n");
    printf("4: Objektgroesse (y)\n");
    printf("5: Bildgroesse (Y)\n");
    printf("6: Vergroesserung (M)\n");
    printf("q: zurück zum Menu\n");
    printf("Geben sie Ihre P ein(1-6):\n ");

    char auswahl[21] = {0};
    long auswahl_int = 0;
    char *endptr;

    scanf("%20s", auswahl);
    auswahl_int = strtol((const char*)auswahl, &endptr, 10);

    if (*endptr != 0){
        auswahl_int = -1;
    }
    if (*endptr == 'q'){
        P = 10;
        return;
    }

    P = auswahl_int;

    switch(P)
    {
        case 1:
        printf("Sie haben Programm 1 gewaehlt: Brennweite berechnen\n");
        break;

        case 2:
        printf("Sie haben Programm 2 gewaehlt: Objektweite berechnen\n");
        break;

        case 3:
        printf("Sie haben Programm 3 gewaehlt: Bildweite berechnen\n");
        break;

        case 4:
        printf("Sie haben Programm 4 gewaehlt: Objektgroesse berechnen\n");
        break;

        case 5:
        printf("Sie haben Programm 5 gewaehlt: Bildgroesse berechnen\n");
        break;

        case 6:
        printf("Sie haben Programm 6 gewaehlt: Vergroesserung berechnen\n");
        break;

        default:
        printf("Dieses Programm ist ungueltigt.\n");
    }

}
void Berechnung_Optische_Abbildung(float f, float a, float A, float M, float y, float Y, int P)
{
    switch (P) {

        case 1:     // Berechnung Brennweite [f]
        printf("Geben Sie Bildweite [A] und Objektweite [a] ein:\n");
        printf("Bildweite [A]: ");
        scanf("%f", &A);
        printf("Objektweite [a]: ");
        scanf("%f", &a);

        // Berechnung Brennweite mit Objektweite [a] und Bildweite [A]
        f = (a * A) / (A + a);
        // Berechnung Vergroesserung mit Objektweite (a) und Bildweite [A]
        M = -(A / a);

        printf("-----------------------\n");
        printf("Brennweite [f]:\n%f", f);
        printf("\nVergroesserung [M]:\n%f", M);

        printf("\n-----------------------\n");
        printf("f = (a * A) / (A + a)\n");
        printf("M = (A / a)\n");
        printf("-----------------------\n");
        break;

        case 2:     // Berechnung Objektweite [a]
        printf("Waehlen Sie die Berechnungsmethode:\n");
        printf("1: Mit Bildweite [A] und Brennweite [f]\n");
        printf("2: Mit Bildgroesse [Y] und Objektgroesse [y]\n");
        scanf("%d", &P);

        if (P == 1) {
        printf("Geben Sie Bildweite [A] und Brennweite [f] ein:\n");
        printf("Bildweite [A]: ");
        scanf("%f", &A );
        printf("Brennweite [f]: ");
        scanf("%f", &f);

        // Berechnung Objektweite [a] mit Bildweite [A] und Brennweite [f]
        a = (f * A) / (A - f);

        printf("-----------------------\n");
        printf("Objektweite [a]:\n%f", a);

        printf("\n-----------------------\n");
        printf("a = (f * A) / (A - f)\n");
        printf("-----------------------\n");
        }
        else if (P == 2) {
        printf("Geben Sie Bildgroesse [Y] und Objektgroesse [y] ein:\n");
        printf("Bildgroesse [Y]: ");
        scanf("%f", &Y);
        printf("Objektgroesse [y]: ");
        scanf("%f", &y);

        // Berechnung Objektweite [a] mit Bildweite [A] und Vergroesserung (M) 
        a = -(A / M);

        printf("-----------------------\n");
        printf("Objektweite [a]:\n%f", a);

        printf("\n-----------------------\n");
        printf("a = a(A / M)\n");
        printf("-----------------------\n");
        }
        break;

        case 3:     // Berechnung Bildweite [A]
        printf("Waehlen Sie die Berechnungsmethode:\n");
        printf("1: Mit Objektweite [a] und Brennweite [f]\n");
        printf("2: Mit Objektweite [a] und Vergroesserung [M]\n");
        scanf("%d", &P);

        if (P == 1) {
        printf("Geben Sie Objektweite [a] und Brennweite [f] ein:\n");
        printf("Objektweite [a]: ");
        scanf("%f", &a);
        printf("Brennweite [f]: ");
        scanf("%f", &f);

        // Berechnung Bildweite [A] mit Brennweite [f] und Objektweite [a]
        A = (f * a) / (a - f);

        printf("-----------------------\n");
        printf("Bildweite [A]:\n%f", A);

        printf("\n-----------------------\n");
        printf("A = (f * a) / (a - f)\n");
        printf("-----------------------\n");
        } 
        else if (P == 2) {
        printf("Geben Sie Vergroesserung [M] und Objektweite [a] ein:\n");
        printf("Vergroesserung [M]: ");
        scanf("%f", &M);
        printf("Objektweite [a]");
        scanf("%f", &a);  

        // Berechnung Bildweite [A] mit Vergroesserung [M] und Objektweite [a]
        A = -(a * M);

        printf("-----------------------\n");
        printf("Bildweite [A]:\n%f", A);

        printf("\n-----------------------\n");
        printf("A = -(a * M)\n");
        printf("-----------------------\n");
        }
        break;

        case 4:     // Berechnung Objektgroesse [y]

        printf("Waehlen Sie die Berechnungsmethode:\n");
        printf("1: Mit Bildweite [A], Objektweite [a] und Bildgroesse [y]\n");
        printf("2: Mit Bildgroesse [Y] und Vergroesserung [M]\n");
        scanf("%d", &P);

        if (P == 1) {
        printf("Geben Sie Bildweite [A] und Objektweite [a] ein:\n");
        printf("Bildweite [A]: ");
        scanf("%f", &A);
        printf("Objektweite [a]: ");
        scanf("%f", &a); 

        // Berechnung Objektgroesse [y] mit Bildweite [A] und Objektweite [a] und Bildgroesse [y]
        y = -(Y * A) / a;

        printf("-----------------------\n");
        printf("Objektgroesse [y]:\n%f", y);

        printf("\n-----------------------\n");
        printf("a = -(Y * A) / a\n");
        printf("-----------------------\n");
        } 

        else if (P == 2) {
        printf("Geben Sie Bildgroesse [Y] und Vergroesserung [M] ein:\n");
        printf("Bildgroesse [Y]: ");
        scanf("%f", &Y);
        printf("Vergroesserung[M]: ");
        scanf("%f", &M);

        // Berechnung Objektgroesse [y] mit Bildgroesse [Y] und Vergroesserung [M]
        y = Y / M;

        printf("-----------------------\n");
        printf("Objektgroesse [y]:\n%f", y);

        printf("\n-----------------------\n");
        printf("y = Y / M\n");
        printf("-----------------------\n");
        }
        break;

        case 5:     // Berechnung Bildgroesse [Y]
        printf("Waehlen Sie die Berechnungsmethode:\n");
        printf("1: Mit Bildweite [A], Objektweite [a] und Objektgroesse [y]\n");
        printf("2: Mit Bildgroesse [Y] und Vergroesserung [M]\n");
        scanf("%d", &P);

        if (P == 1) {
        printf("Geben Sie Bildweite [A], Objektweite [a] und Objektgroesse [y] ein:\n");
        printf("Bildweite [A]: ");
        scanf("%f", &A);
        printf("Objektweite [a]: ");
        scanf("%f", &a);
        printf("Objektgroesse [y]: ");
        scanf("%f", &y); 

        // Berechnung Bildgroesse [Y] mit Objektweite [a] und Bildweite [A] und Objektgroesse [y]
        Y = -(A / a) * y;

        printf("-----------------------\n");
        printf("Bildgroesse [Y]:\n%f", Y);

        printf("\n-----------------------\n");
        printf("\nY = -(A / a) * y\n");
        printf("-----------------------\n");
        } 
        else if (P == 2) {
        printf("Geben Sie Bildgroesse [Y] und Vergroesserung [M] ein:\n");
        printf("Bildgroesse [Y]: ");
        scanf("%f", &Y);
        printf("Vergroesserung [M]: ");
        scanf("%f", &M);

        // Berechnung Bildgroesse [Y] mit Vergroesserung [M] und Objektgroesse [y]
        Y = y * M;

        printf("-----------------------\n");
        printf("Bildgroesse [Y]:\n%f", Y);

        printf("\n-----------------------\n");
        printf("Y = y * M\n");
        printf("-----------------------\n");
        }
        break;

        case 6:     // Berechnung Vergroesserung [M]
        printf("Waehlen Sie die Berechnungsmethode:\n");
        printf("1: Mit Bildweite [A] und Objektweite [a]\n");
        printf("2: Mit Bildgroesse [Y] und Objektgroesse [y]\n");
        scanf("%d", &P);

        if (P == 1) {
        printf("Geben Sie Bildweite [A] und Objektweite [a] ein:\n");
        printf("Bildweite [A]: ");
        scanf("%f", &A);
        printf("Objektweite [a]: ");
        scanf("%f", &a);

        // Berechnung Vergroesserung [M] mit Objektweite [a] und Bildweite [A]
        M = -(A / a);

        printf("-----------------------\n");
        printf("Vergroesserung [M]\n%f", M);

        printf("\n-----------------------\n");
        printf("M = -(A / a)\n");
        printf("-----------------------\n");
        } 

        else if (P == 2) {
        printf("Geben Sie Bildgroesse [Y] und Objektgroesse [y] ein:\n");
        printf("Bildgroeße [Y]: ");
        scanf("%f", &Y);
        printf("Objektgroesse [y]: ");
        scanf("%f", &y);

        // Berechnung Vergroesserung [M] mit Objektgroesse [y] und Bildgroesse [Y]
        M = (Y / y); 

        printf("-----------------------\n");
        printf("Vergroesserung [M]\n%f", M);

        printf("\n-----------------------\n");
        printf("M = (Y /y)\n");
        printf("-----------------------\n");
        }
        break;
    }
}


