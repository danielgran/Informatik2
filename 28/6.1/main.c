/**********************************************************************\
* Aufgabe 28.6.1 (Folgen von Nullen und Einsen)
*
* Datum: 04.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char liste1[MAX][MAX];
    char liste2[MAX][MAX];


    int list_input, size1 = 0, size2 = 0;
    char name_input[MAX];


    int proceed = 1;

    while (proceed == 1) {

        printf("Nummer der Liste: ");
        scanf("%d", &list_input);
        printf("Name: ");
        fflush(stdin);
        fgets(name_input, MAX, stdin);

        if (name_input[0] == '\n')
            proceed = 0;

        if (list_input == 1) {
            strcpy(liste1[size1], name_input);
            size1++;
        }

        if (list_input == 2) {
            strcpy(liste2[size2], name_input);
            size2++;
        }


    };

    printf("Liste1: \n");
    for (int i = 0; i < size1; ++i) {
        printf("%s", liste1[i]);
    }

    printf("\n");

    printf("Liste2: \n");
    for (int i = 0; i < size2; ++i) {
        printf("%s", liste2[i]);
    }


    return 0;
}
