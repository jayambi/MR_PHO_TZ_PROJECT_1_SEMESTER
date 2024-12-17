/* 2024-12-09_Programier-Projekt_Main.c
Programm das Funktionen zu unserem Studium enthält
Autor: Jan und Jay
Firma: FHGR
Version: 1
Datum: 10.12.2024
Änderungen:
13.12.2024: funktion für beenden wurde hinzgefügt von Jay Spiderman
17.12.2024
*/
// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Einbinden .h File der Funktionen
#include "funktion_wein.h"
#include "funktion_beenden.h"
#include "Abbildungsrechner.h"
#include "Funktion_Flugi.h"
#include "StudyPlanner.h"


// Mit main beginnt das Programm.
int main(void)
{
    //Varible definieren
    int var;
    
    printf("\n");
    printf("**********************************\n");
    printf("*     WILLKOMMEN ZUM             *\n");
    printf("*     FH GR HILFEPROGRAMM        *\n");
    printf("**********************************\n");
    printf("\n");

    do        
    {   
        // Möglichkeiten ausgeben
        printf("Was moechten Sie tun?\n");
        printf("1\t Abbildungsrechner fuer geometrische Optik\n");
        printf("2\t Quiz\n");
        printf("3\t Studyplaner\n");
        printf("4\t Hello World\n");
        printf("0\t Programm beenden\n");
        // Abfrage was tun
        fflush(stdin);
        scanf("%d", &var);
        // Auswahl
        switch(var)
        {
            case 1 :Abbildungsrechner();
                    break;
            case 2 :Flugi();
                    break;
            case 3 :StudyPlanner();
                    break;       
            case 4 :funktion_wein();
                    break;
            case 0 :funktion_beenden(); 
                    exit(0);
            default: printf("\nFalsche Eingabe\n");
        }     

    } while (var!=0);//Abbruchbedingung wenn keine weiteren Adressen

	// Präprozessoranweisung (Linux oder Windows?)
#ifndef __linux__ 
	// Hält die Konsole offen.
	system("pause");
#endif
	// Rückgabewert, dass das Programm erfolgreich beendet wurde.
	return 0;
}

