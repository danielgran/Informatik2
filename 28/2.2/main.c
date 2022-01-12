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
#define EINGABEN 2

struct zahleneingabe {
    char *vorkomma;
    char *nachkomma;
    float result;
};

int main() {
    char *buffer, *eingabe;
    const char delimiter1 = ',';
    const char delimiter2 = '\n';

    int counter = 0;
    float sum = 0;

    eingabe = malloc(MAX * sizeof(char));

    struct zahleneingabe eingaben[MAX];

    for (int i = 0; i < EINGABEN; ++i) {
        printf("Bitte die %d. Zahl eingeben (xx,xx): ", i);
        fflush(stdin);
        fgets(eingabe, MAX, stdin);

        buffer = strtok(eingabe, &delimiter1);
        eingaben[i].vorkomma = malloc(strlen(buffer) * sizeof(char));
        strcpy(eingaben[i].vorkomma, buffer);

        buffer = strtok(NULL, &delimiter2);
        eingaben[i].nachkomma = malloc(strlen(buffer) * sizeof(char));
        strcpy(eingaben[i].nachkomma, buffer);

        counter++;
    }


    for (int i = 0; i < counter; ++i) {

        // Convert the string pair into a single float
        char *to_be_float = malloc((strlen(eingaben[i].vorkomma) + strlen(eingaben[i].nachkomma)) * sizeof(char) + 1);
        sprintf(to_be_float, "%s.%s", eingaben[i].vorkomma, eingaben[i].nachkomma);
        eingaben[i].result = atof(to_be_float);

        sum += eingaben[i].result;

    }

    printf("Das Ergebnis ist %.5f\n", sum);
    return 0;
}
