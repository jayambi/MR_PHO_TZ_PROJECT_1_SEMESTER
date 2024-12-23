/* hier werden funktionen oder Variablen definiert

Funktion welche beim beenden des Proramms ausgeführt wird.

 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "funktion_beenden.h"

void funktion_beenden()
{
	
    // Rechenaufgabe erstellen (z. B. Multiplikation von zwei Zufallszahlen)
    srand(time(NULL)); //Initisalisiere den Zufalls-generator mit der aktuellen Zeit
    int num1 = rand() % 100 + 1;  // Zufallszahl zwischen 1 und 100
    int num2 = rand() % 100 + 1;  // Zufallszahl zwischen 1 und 100
    int correct_answer = num1 * num2;
   
	



	// Frage erstellen   
    printf("Loese zuerst die Rechenaufgabe: %d * %d = ?\n", num1, num2);

    int user_answer;
    
    // Benutzer zur Eingabe auffordern, bis die richtige Antwort gegeben wird
    while (user_answer != correct_answer || user_answer != 0) {
        printf("Deine Antwort: ");
        fflush(stdin);
        scanf("%d", &user_answer);

        if (user_answer == correct_answer  ) {
            printf("Richtig! Die Antwort ist %d.\n", correct_answer);
            break;
        }
     
		if(user_answer == 0){
            printf("Schade! Die richtige Antwort waere %d.\n", correct_answer);
            break;

        }


        else {
            printf("Falsch! Versuche es noch einmal.\n");
            printf("Null geht auch du Null! \n");
        }
        
       
    }
    
	time_t t;
    time(&t);

    // Umwandeln der Zeit in eine strukturierte Zeit
    struct tm *localTime = localtime(&t);

    // Ausgabe der Uhrzeit
    printf("\n Aktuelle Uhrzeit: \n %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    printf("\n \n");
    return;

}	
