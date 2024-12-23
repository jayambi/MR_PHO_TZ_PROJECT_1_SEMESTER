/*main_widerstand.c
Program: main für widerstand.c
Author:DAK
Version:0.0
Date: 2024-12-16
Changes: 0,
*/

// Include Headerfiles from Libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funktion_widerstand.h"

int funktion_widerstand() 
{
    int nF;
    char color[6][10], repeat[10];
    float ohm, toleranz, tempk;

    for (int i = 0; i < 1; i++) {
        printf("Wieviele Farbringe hat der Widerstand?: ");
        scanf("%i", &nF);
        if (nF <=6 && nF >= 3){
            funktion_widerstand(nF);
        }else{
            printf("Nur Widerstände mit 3 bis 6 Farbringe können berechnet werden\nBerechnung wiederholen? (j/n): ");
        } 
        scanf("%s", repeat);
        if (strcmp(repeat, "j") == 0)
        {
            i--;
        }else{
            return 10;
        }
        
    }    
    
    return 0;
}

