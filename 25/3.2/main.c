/**********************************************************************\
* Aufgabe 25.3.2 (Folgen von Nullen und Einsen)
*
* Datum: 04.11.2019
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


char rand_bit() {
    return rand() & 1;
}

char *gen_chain(int length) {
    char str[1024];
    for (int i = 0; i < length; ++i) {
        str[i] = rand_bit();
    }
    return str;
}


int main() {
    srand(time(NULL));

    char *chain = gen_chain(10);

    int i = 1;
    do {
        printf("%c\n", chain[i]);
        i++;
    } while (chain[i]);

    printf("Hello, World! %s\n", gen_chain(12));


    return 0;

}
