#include <stdio.h>
#include "queue.h"

int main() {
    int n, z, i = 1, nr;

    do {
        printf("Wie viele Personen: ");
        nr = scanf("%d", &n);
        getchar();
    } while (nr != 1 || n < 0);
    do {
        printf("Wie vielte ist auszusondern: ");
        nr = scanf("%d", &z);
        getchar();
    } while (nr != 1 || z < 0);

    for (i = 1; i <= n; i++) // Queue füllen
        put(i);

    while (!isEmpty()) {
        for (i = 1; i < z; i++) { // z-1 Zahlen aus Queue lesen
            if (put(get()) == FALSE) { // und wieder am Ende der Queue einfügen
                fprintf(stderr, "Fehler beim Einfügen\n");
                return 1;
            }
        }
        printf("%d, ", get());      // z. Zahl aus Queue lesen und ausgeben
        // Diese Zahl nicht mehr einfügen
    }
    printf("\n");

    return 0;
}
