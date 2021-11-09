#include <stdio.h>



int erg(int *array) {
    return array[0] + array[1];

}

int main() {

    int ar[2] = {12,3};

    int *zeigerarray[12];

    int ********zeigerwahnsinn[43];

    int dasisteinwert = 4;

    int **zeigerzeiger = zeigerarray;

    zeigerarray[3] = &dasisteinwert;

    printf("%d", *zeigerzeiger[0]);

    return 0;
}
