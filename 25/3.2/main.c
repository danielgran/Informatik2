/**********************************************************************\
* Aufgabe 25.3.2 (Folgen von Nullen und Einsen)
*
* Datum: 04.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int rand_bit() {
    return rand() & 1;
}

int *gen_chain(int length) {
    int *chain = malloc(length); // Vorgriff
    for (int i = 0; i < length; i++) {
        chain[i] = rand_bit();
    }
    return chain;
}

void view(int *chain, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", chain[i]);
    }
    printf("\n");
}

int process(int *chain, int length) {
    int newlength = 0, processed = 0;
    for (int i = 0; i < length - 1; i++) {
        processed = 0;
        if (chain[i] == chain[i + 1]) {
            chain[i] = 0;
            processed = 1;

        } else {
            chain[i] = 1;
            processed = 1;
        }
        if (processed) {
            memmove(&chain[i+1], &chain[i+2], (length-(1+i)) * sizeof(int));
            newlength = length - 1;
            break;
        }
    }
    return newlength;
}


int main() {
    srand(time(NULL));
    int eingabe = 0;
    printf("Bitte geben Sie ein Zahl ein: ");
    scanf("%d", &eingabe);

    int *chain = gen_chain(eingabe);

    int newlength = eingabe;
    while (newlength != 0) {
        view(chain, newlength);
        newlength = process(chain, newlength);
    }

    return 0;

}
