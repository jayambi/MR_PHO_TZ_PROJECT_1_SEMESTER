#include "funktion_quiz.h"




int quiz(char Question[][500], char Answer[], int zahl_h) {
    char repeat[zahl_h][500]; // Array, um falsche Fragen zu speichern
    char userAnswer;
    int incorrectIndices[zahl_h]; // Indizes der falschen Antworten
    int incorrectCount = 0;  // Anzahl falscher Antworten 
    srand(time(NULL)); //SL Zufallsgenerator initialisieren                  

    int zufallszahl = 0;
    int i;

    // Fragen durchgehen und Antworten überprüfen
    for (i = 0; i < zahl_h; i++) 
    {
        zufallszahl = rand() % zahl_h  ; // SL % 2 räpresentier die Obergrenze


        printf("Frage %d: %s\n", i + 1, Question[zufallszahl]);//SL Zufallszahl durch i ersetzt
        scanf(" %c", &userAnswer); // wichtig lehrschlag vor %c

        if (userAnswer == Answer[zufallszahl]) {
            printf("Korrekt!\n");
        } 
        else if (userAnswer != Answer[zufallszahl])
        {
            printf("Falsch!\n");
            strcpy(repeat[incorrectCount], Question[i]); // Frage speichern
            incorrectIndices[incorrectCount] = zufallszahl;        // Index speichern
            incorrectCount++;
        }
    }

    // Überprüfen, ob es falsche Antworten gibt
    if (incorrectCount > 0) {
        char retry;
        printf("Du hast %d falsche Antworten. Willst du diese wiederholen? (j/n): ", incorrectCount);
        scanf(" %c", &retry);

        if (retry == 'j' || retry == 'J') {
            for (int i = 0; i < incorrectCount; i++) {
                printf("Wiederholung: %s\n", repeat[i]);
                scanf(" %c", &userAnswer);

                if (userAnswer == Answer[incorrectIndices[i]]) {
                    printf("Jetzt korrekt!\n");
                } else {
                    printf("Immer noch falsch.\n");
                }
            }
        }
    } else {
        printf("Alle Antworten waren korrekt!\n");
    }

    return incorrectCount;
}

// Funktion: Baum zeichnen
void draw_tree(int total , int wrong) {
    total++;
    for (int i = 0; i < total - 1; i++) {
        // Sterne einrücken
        for (int j = 0; j < total - i - 1; j++) {
            printf(" ");
        }

        // Sterne für diese Ebene zeichnen
        for (int y = 0; y < (2 * i + 1); y++) {
            if (wrong == 0 && i == 0) {
                // Besondere goldene Spitze, wenn alles richtig ist
                printf("\033[1;33m*\033[0m");
            } else if (i < wrong) {
                // Ebene gehört zu den falschen Fragen (Rot)
                printf("\033[1;31m*\033[0m"); // Rote Sterne
            } else {
                // Ebene gehört zu den richtigen Fragen (Grün)
                printf("\033[1;32m*\033[0m"); // Grüne Sterne
            }
        }
        printf("\n");
    }

    // Stamm zentrieren
    for (int i = 0; i < total - 1; i++) {
        printf(" ");
    }
    printf("|\n");
}

// Funktion: Ergebnisse ausgeben
void print_results(int total, int wrong) {
    printf("\n=== Ergebnis der Auswertung ===\n");
    printf("Gesamtfragen: %d\n", total);
    printf("Falsche Fragen: %d\n", wrong);
    printf("Richtige Fragen: %d\n", total - wrong);

    // Besondere Nachricht, wenn alles richtig ist
    if (wrong == 0) {
        printf("\n Perfekt gemacht! Alle Fragen richtig beantwortet! \n");
    }
}

// Hauptfunktion
int funktion_quiz() {
    int zahl_h ; // Höhe des Baumes (Gesamtfragen)
    int wrong_questions; // Anzahl der falschen Fragen


    FILE *file;                             // File-Pointer
    char filename[50] = "questions.txt" ;   // Filename
    int MaxLines = 500;
    int MaxLength = 500;
    char lines[MaxLines][MaxLength];        // Array for separate lines
    int line_count = 0;                     // Counter for number of lines

    char Question[MaxLines][MaxLength];     // Array for questions
    char Answer[MaxLines];                  // Array for answer
    int qst = 0;
    int len = 0;


    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Fehler: Datei \"%s\" konnte nicht geoeffnet werden.\n", filename);
        return 1; // End program if file can't be opened
    }

    // Read lines from the file
    while (fgets(lines[line_count], MaxLength, file) != NULL) {
        size_t len = strlen(lines[line_count]);
        if (len > 0 && lines[line_count][len - 1] == '\n') {
            lines[line_count][len - 1] = '\0'; // Entferne das '\n'
            len--; 
        }
        
        // Frage und Antwort trennen
        if (len > 2) { 
            Answer[line_count] = lines[line_count][len - 1]; // Letztes Zeichen als Antwort
            lines[line_count][len - 2] = '\0';              // Kürze Frage um Antwortzeichen
            strcpy(Question[line_count], lines[line_count]);
        }
        line_count++;
    
    }

    
    zahl_h = line_count;

    // close file
    fclose(file);

    /*
    // Output
    printf("\nDie Datei wurde in %d Zeilen eingelesen:\n", line_count);
    for (int i = 0; i < line_count; i++) {
        printf("Zeile %d: %s\n", i + 1, Question[i]);
        size_t len = strlen(lines[i]);
        printf("Antwort: %c\n", Answer[i]);
    

    }
    */

    //char question[2][50]; //= {"Schaffen wir das? (1 = Ja, 0 = Nein)", "Wie geht das? (1 = Einfach, 0 = Schwer)"};
    //int answer[2] = {1, 0};

    // Eingabebefehl
    printf("Für wahre Aussage: W, für falsch Ausage: F\n");

    int incorrectCount = quiz(Question, Answer, zahl_h);
    printf("Anzahl falscher Antworten: %d\n", incorrectCount);

    wrong_questions = incorrectCount;

    // Baum zeichnen
    draw_tree(zahl_h, wrong_questions);

    // Ergebnisse ausgeben
    print_results(zahl_h, wrong_questions);

  return 0;
}


/*
int main()
{
   Flugi();
}
*/