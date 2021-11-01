#include <stdio.h>

int erg(int *array) {
    return array[0] + array[1];

}



int main() {

    int ar[2] = {12,3};

    printf("%d", erg(ar));

    return 0;
}
