#include <stdio.h>



int erg(int *array) {
    return array[0] + array[1];

}

int main() {

    int ar[2] = {12,3};

    int *zeigerarray[12];

    int dasisteinwert = 4;

    zeigerarray[3] = &dasisteinwert;

    printf("%d", *zeigerarray[3]);

    return 0;
}
