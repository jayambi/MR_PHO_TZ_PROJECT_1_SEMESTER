/* Funktion_Flugi.h

Autor: Simon Sommer, Simon Ladner, Lucas Defuns, Delia Schmid
Firma: FHGR
Version 1.0
Datum 16.12.2024
Aenderungen:
V 1.0 16.12.2024 Erste Version
*/

#ifndef Funktion_Flugi_H
#define Funktion_Flugi_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Konstanten für die Dateiverwaltung
#define MAX_LINES 500
#define MAX_LENGTH 500

// Funktionsprototypen
int quiz(char Question[][MAX_LENGTH], char Answer[], int zahl_h);
void draw_tree(int total, int wrong);
void print_results(int total, int wrong);
int Flugi();
#endif // QUIZ_H
