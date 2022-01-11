/**********************************************************************\
* Aufgabe 23.1 (Folgen von Nullen und Einsen)
*
* Datum: 04.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>

int i = 0;

int main(void) {
    int i = 1;
    printf("i=%d\n", i); // i=1
    {
        int i = 2;
        printf("i=%d\n", i); // i=2
        {
            i++;
            printf("i=%d\n", i); // i=3
        }
        printf("i=%d\n", i); // i=3
    }
    printf("i=%d\n", i); // i = 1
    return (0);
}