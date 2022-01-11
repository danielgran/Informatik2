#include <stdio.h>
#include "complexma1lib.h"


int main() {


    int proceed = 1, eingabe = 0, correct = 0;

    Complex list[2], buffer;


    for (int i = 1; i < 3; ++i) {
        printf("%d. Zahl eingeben \n", i);
        printf("\tRealteil: ");
        while (correct == 0) {
            fflush(stdin);
            correct = scanf("%d", &eingabe);
        }
        buffer.real = eingabe;

        correct = 0;
        printf("\tImaginärteil: ");
        while (correct == 0) {
            fflush(stdin);
            correct = scanf("%d", &eingabe);
        }
        correct = 0;
        buffer.imag = eingabe;
        list[i - 1] = buffer;
    }


    printf("Summe: \t\t x + x = \t\t");
    printComplex(addComplex(list[0], list[1]));

    printf("Differenz: \t x - x = \t\t");
    printComplex(subComplex(list[0], list[1]));

    printf("Produkt: \t x * x = \t\t");
    printComplex(mulComplex(list[0], list[1]));

    printf("Quotient: \t x / x = \t\t");
    printComplex(divComplex(list[0], list[1]));

    return 0;
}
