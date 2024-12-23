
/* 
---------------------------------------------------------------------------------------------------------
2024-12-09_Programier-Projekt_Main.c
Programm das Simple Funktionen zu unserem Studium Robotik oder Photonik enthält
Autor: Jan, Jay, Marco und Cyrill
Firma: FHGR
Version: 1
Datum: 10.12.2024
Änderungen:
13.12.2024:     funktion für beenden wurde hinzgefügt von Jay Spiderman
17.12.2024:     funktionen der anderen Gruppen wurde hinzugefügt.
23.12.2024:     nach abwarten auf Funktionierende Programme der gruppen "widerstand" und "studyplander",
                leider ohne erfolg -> Projekt abgeschlossen.
                Eventuell wird später Version 1.2 gebaut
---------------------------------------------------------------------------------------------------------
*/

// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Einbinden .h File der Funktionen
#include "funktion_helloworld.h"
#include "funktion_beenden.h"
#include "Abbildungsrechner.h"
#include "funktion_quiz.h"
//#include "StudyPlanner.h"             //beide auskommentiert weil Funktion nicht gegeben.
//#include "funktion_widerstand.h"      //bis 23.12.24 keine abgabe der Parteien 


// Mit main beginnt das Programm.
int main(void)
{
    //Varible für Auswahl definieren
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
        printf("3\t Hello World\n");
        //printf("4\t Studyplaner\n");
        //printf("5\t Widerstand\n");
        printf("0\t Programm beenden\n");
        
        // Abfrage was tun
        fflush(stdin); // einabepuffer entleeren
        scanf("%d", &var);

        // Auswahl
        switch(var)
        {
            case 1 :Abbildungsrechner();
                    break;
            case 2 :funktion_quiz();             //Fragen für's quiz erweiter bar in "questions.txt im Hauptordner des Programms"                                     
                    break;
            case 3 :funktion_helloworld();
                    break;
            //case 4 :StudyPlanner();           //keine funktionierende programme abgegeben
                    //break;  
            //case 5 :funktion_widerstand();    //keine funktionierende programme abgegeben
                    //break;             
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

