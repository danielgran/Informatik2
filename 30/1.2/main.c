#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(int argc, char *argv[]) {

    char *file = malloc((strlen(argv[1]) + 1) * sizeof(char));

    strcpy(file, argv[1]);

    FILE *f;

    f = fopen(file, "r");

    char current_char;
    int counter = 1;
    printf("%-3d", counter);
    while(1) {
        current_char = fgetc(f);
        if (current_char == EOF)
            break;
        printf("%c", current_char);
        if (current_char == '\n')
        {
            counter++;
            printf("%-3d", counter);
        }
    }


    return fclose(f);
}
