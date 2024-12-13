/* 2024-12-09_Programier-Projekt_Main.c
Programm das Funktionen zu unserem Studium enthält
Autor: Jan Krummenacher
Firma: FHGR
Version: 1
Datum: 10.12.2024
Änderungen:
*/
// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Einbinden .h File der Funktionen
#include "funktion_wein.h"
#include "funktion_beenden.h"




// Mit main beginnt das Programm.
int main(void)
{
    //Varible definieren
    int var;
    
    do        
    {   
        // Möglichkeiten ausgeben
        printf("Was moechten Sie tun?\n");
        printf("1\t Funktion Wein\n");
        printf("2\t Funktion Wein\n");
        printf("3\t Funktion Wein\n");
        printf("0\t Programm beenden\n");
        // Abfrage was tun
        scanf("%d", &var);
        // Auswahl
        switch(var)
        {
            case 1 :funktion_wein();
                    break;
            case 2 :funktion_wein();
                    break;
            case 3 :funktion_wein();
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

