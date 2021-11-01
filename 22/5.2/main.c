/**********************************************************************\
* Aufgabe 22.5.2 (Größter gemeinsamer Teiler)
*
* Datum: 27.10.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>

unsigned long ggt(unsigned long alt, long neu) {
    unsigned long result;

    if (neu == 0) {
        result = alt;
    } else {
        result = ggt(neu, alt % neu);
    }

    return result;
}

int main() {
    unsigned long teiler = 0, input = 0;
    int i = 1;

    printf("Gib nicht-negative ganze Zahlen ein (Ende=0)\n");
    printf("%i. Zahl: ", i);
    scanf("%i", &teiler);
    printf("%i. Zahl: ", ++i);
    scanf("%i", &input);
    teiler = ggt(teiler, input);

    while (input != 0) {
        i++;
        printf("%i. Zahl: ", i);
        scanf("%i", &input);

        teiler = ggt(teiler, input);

    }
    printf("Der groesste gemeinsame Teiler ist: %i", teiler);
    return 0;
}

