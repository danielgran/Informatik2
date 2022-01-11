/**********************************************************************\
* Aufgabe 28.4.4 (Folgen von Nullen und Einsen)
*
* Datum: 04.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 1000


struct Schueler {
    char vorname[MAX];
    char nachname[MAX];
    int note;
};


int main() {
    int proceed = 1, int_eingabe = 0, counter = 1, sum = 0;
    char str_eingabe[MAX];

    struct Schueler list[MAX], buffer;

    while (proceed) {


        printf("Eingabe des %d. Schueler\n", counter);
        printf("Vorname: ");
        fflush(stdin);
        fgets(str_eingabe, MAX, stdin);
        str_eingabe[strcspn(str_eingabe, "\n")] = 0;

        if (str_eingabe[0] == 0) {
            proceed = 0;
        } else {
            strcpy(buffer.vorname, str_eingabe);

            printf("Nachname: ");
            fflush(stdin);
            fgets(str_eingabe, MAX, stdin);
            str_eingabe[strcspn(str_eingabe, "\n")] = 0;
            if (str_eingabe[0] == 0) {
                proceed = 0;
            } else {
                strcpy(buffer.nachname, str_eingabe);

                printf("Note: ");
                fflush(stdin);
                scanf("%d", &int_eingabe);
                buffer.note = int_eingabe;
                list[counter - 1] = buffer;
                counter++;
            }
        }

    }
    counter--;


    printf("%-30s %-30s %-30s\n", "Name", "Vorname", "Note");

    for (int i = 0; i < counter; i++) {
        sum += list[i].note;
        printf("%-30s %-30s %-30d\n", list[i].nachname, list[i].vorname, list[i].note);
    }

    printf("Durschnittsnote: %.2f\n", (float) sum / (float)counter);

    for (int i = 1; i < 7; ++i) {

        printf("Note %d: ", i);
        int gradecount = 0;
        for (int j = 0; j < counter; ++j) {
            if (list[j].note == i) {
                gradecount++;
            }
        }
        for (int j = 0; j < gradecount; ++j) {
            printf("*");
        }
        printf("\n");
        gradecount = 0;
    }




    return 0;
}
