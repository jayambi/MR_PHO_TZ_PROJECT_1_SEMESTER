/* hier werden funktionen oder Variablen definiert

Funktion welche beim beenden des Proramms ausgeführt wird.

 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void funktion_beenden()
{
	
    // Rechenaufgabe erstellen (z. B. Multiplikation von zwei Zufallszahlen)
    int num1 = rand() % 100 + 1;  // Zufallszahl zwischen 1 und 100
    int num2 = rand() % 100 + 1;  // Zufallszahl zwischen 1 und 100
    int correct_answer = num1 * num2;
	

	// Frage erstellen   
    printf("Loese die Rechenaufgabe: %d * %d = ?\n", num1, num2);

    int user_answer;
    
    // Benutzer zur Eingabe auffordern, bis die richtige Antwort gegeben wird
    while (1) {
        printf("Deine Antwort: ");
        scanf("%d", &user_answer);

        if (user_answer == correct_answer) {
            printf("Richtig! Die Antwort ist %d.\n", correct_answer);
            break;
		


        } else {
            printf("Falsch! Versuche es noch einmal.\n");
        }
    }
	time_t t;
    time(&t);

    // Umwandeln der Zeit in eine strukturierte Zeit
    struct tm *localTime = localtime(&t);

    // Ausgabe der Uhrzeit
    printf("Aktuelle Uhrzeit: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    return;
}	
