/**********************************************************************\
* Aufgabe 22.4.1
*
* Datum: 27.10.2021
* Autor: Daniel Gran
*
\**********************************************************************/
#include <stdio.h>
#include <stdarg.h>

int max(int no_items, ...) {
    int result = 0;

    va_list array;

    va_start(array, no_items);
    for (int i = no_items - 1; i > 0; i--) {
        int number = va_arg(array, int);
        if (number > result) {
            result = number;
        }
    }
    va_end(array);
    return result;
}

int main() {
    max(10, 1, 2, 3, 4, 5, 6, 7, 9, 0);
    printf("Das Maximum der Zahlen 1, 2, 3, 4, 5, 90 und 1 ist: %d\n", max(7, 1, 2, 3, 4, 5, 90, 1));
    printf("Das Maximum der Zahlen 1, 2, 3, 4, 2, 3 und 1 ist: %d\n", max(7, 1, 2, 3, 4, 2, 3, 1));

    return 0;
}
