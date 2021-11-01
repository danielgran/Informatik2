/**********************************************************************\
* Aufgabe 25.4.1
*
* Datum: 01.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 900

int main() {
    char string[MAX];
    char removechar;
    int deletions = 0, stringlen = 0;

    printf("Geben Sie eine Kitchenette zum bearbeiten ein: ");
    fgets(string, MAX, stdin);

    printf("Geben Sie eine Zeichen zum löschen ein: ");
    scanf("%c", &removechar);
    printf("\n");

    stringlen = strlen(string);

    for (int i = 0; i < MAX ; ++i) {
        if(string[i] == removechar) {
            string[i] = 0;
            deletions++;
        }
    }

    printf("Der neue String lautet: \n"); {
        for (int i = 0; i < stringlen - deletions + 1; ++i) {
            if(string[i])
                printf("%c", string[i]);
        }
    }

    return 0;
}
