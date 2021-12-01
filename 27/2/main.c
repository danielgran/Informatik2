#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void evaluate_array(char *array) {

    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, zero = 0;
    int i;
    for (i = 0; i < strlen(array); i++) {
        if (array[i] == '1')
            one++;
        if (array[i] == '2')
            two++;
        if (array[i] == '3')
            three++;
        if (array[i] == '4')
            four++;
        if (array[i] == '5')
            five++;
        if (array[i] == '6')
            six++;
        if (array[i] == '7')
            seven++;
        if (array[i] == '8')
            eight++;
        if (array[i] == '9')
            nine++;
        if (array[i] == '0')
            zero++;
    }

    printf("Einsen: ");
    for (i = 0; i < one; i++) {
        printf("|");
    }
    printf("\n");

    printf("Zweier: ");
    for (i = 0; i < two; i++) {
        printf("|");
    }
    printf("\n");

    printf("Dreier: ");
    for (i = 0; i < three; i++) {
        printf("|");
    }
    printf("\n");

    printf("Vierer: ");
    for (i = 0; i < four; i++) {
        printf("|");
    }
    printf("\n");

    printf("Fünfer: ");
    for (i = 0; i < five; i++) {
        printf("|");
    }
    printf("\n");

    printf("Sechser: ");
    for (i = 0; i < six; i++) {
        printf("|");
    }
    printf("\n");

    printf("Siebener: ");
    for (i = 0; i < seven; i++) {
        printf("|");
    }
    printf("\n");

    printf("Achter: ");
    for (i = 0; i < eight; i++) {
        printf("|");
    }
    printf("\n");

    printf("Neuner: ");
    for (i = 0; i < nine; i++) {
        printf("|");
    }
    printf("\n");

    printf("Nuller: ");
    for (i = 0; i < zero; i++) {
        printf("|");
    }
    printf("\n");
}


int main() {
    char *array;
    char *cache = "";
    int *sum_arr;
    int eingabe;
    char strEingabe[MAX + 1];
    // Check if there is enough memory
    array = malloc(MAX * sizeof(long int));
    if (array == NULL) {
        printf("Programmabbruch wegen Speicherplatzmangel");
        return 0;
    }

    printf("Eingabe bitte - mit Eingabe = 0 beenden.\n");

    do {
        fflush(stdin);
        fgets(strEingabe, MAX, stdin);

        strEingabe[strlen(strEingabe) - 1] = '\0';

        array = (char *) malloc(sizeof(char) * (strlen(strEingabe) + strlen(cache)) + 1);
        strcpy(array, cache);
        strcat(array, strEingabe);

        cache = (char *) malloc(strlen(array));
        strcpy(cache, array);

        printf("%s\n", array);

    } while (strlen(strEingabe) > 0);

    evaluate_array(cache);

    return 0;
}
