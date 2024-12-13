/* hier werden funktionen oder Variablen definiert

Funktion welche beim beenden des Proramms ausgeführt wird.

 */
#include <stdio.h>
#include <time.h>

void funktion_beenden()
{
	time_t t;
    time(&t);

    // Umwandeln der Zeit in eine strukturierte Zeit
    struct tm *localTime = localtime(&t);

    // Ausgabe der Uhrzeit im Format HH:MM:SS
    printf("Aktuelle Uhrzeit: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    return;
}	
