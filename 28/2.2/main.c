/**********************************************************************\
* Aufgabe 28.2.2
*
* Datum: 04.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct zahl {
    int vor;
    int nach;
};

int main() {
    struct zahl eingabe1, eingabe2, summe;
    int hilf = 0;
    char str_eingabe1[MAX], str_eingabe2[MAX];
    const char delimiter1 = ',';
    const char delimiter2 = '0';

    fflush(stdin);
    printf("Bitte geben Sie die erste Zahl mit Komma separiert ein");
    fgets(str_eingabe1, MAX, stdin);

    fflush(stdin);
    printf("Bitte geben Sie die zweite Zahl mit Komma separiert ein");
    fgets(str_eingabe2, MAX, stdin);

    // Process these two numbers into the corresponding structs
    eingabe1.vor = atoi(strtok(str_eingabe1, &delimiter1));
    eingabe1.nach = atoi(strtok(NULL, &delimiter2));
    eingabe2.vor = atoi(strtok(str_eingabe2, &delimiter1));
    eingabe2.nach = atoi(strtok(NULL, &delimiter2));

    // Calculate the sum struct
    int over = (eingabe1.nach + eingabe2.nach) % 10;
    summe.vor = eingabe1.vor + eingabe2.vor + over;
    summe.nach = over % 10;


    // (Optional) output with float
    char *to_format = malloc(sizeof(char) * MAX);
    sprintf(to_format, "%d.%d", summe.vor, summe.nach);
    float erg = atof(to_format);


    printf("Die Summe ist: %d,%d bzw %f", summe.vor, summe.nach, erg);


    return 0;
}
