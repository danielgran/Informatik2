#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARG 6

void printBits(size_t const size, void const *const ptr) {
    unsigned char *b = (unsigned char *) ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    int zahl = 0;
    char options[MAX_ARG];


    if (argv[1][0] == '-') {
        strcpy(options, argv[1]);
        zahl = atoi(argv[2]);
    } else {
        strcpy(options, "--boh");
        zahl = atoi(argv[1]);
    }

    for (int i = 2; i < strlen(options); ++i) {
        char cur = options[i];

        switch (cur) {
            case 'b': {
                printf("Binary: \t", cur);
                printBits(2, &zahl);
                break;
            }
            case 'o': {
                printf("Octal: \t\t", cur);

                printf("%o\n", zahl);
                break;
            }
            case 'h': {
                printf("Hex: \t\t", cur);
                printf("%02hhX\n", zahl);
                break;
            }
        }
    }

    return 0;
}
