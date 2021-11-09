/**********************************************************************\
* Aufgabe 25.6.4 (Mischen von Farben)
*
* Datum: 9.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 100

int read_color(char *text);

char *base_col[] = {"Gruen", "Rot", "Violett"};
char *mix_col[] = {"Gruen", "Gelb", "Blau", "Rot", "Purpur", "Violett"};

int tabelle[3][3] = {{0, 1, 2},
                     {1, 3, 4},
                     {2, 4, 5}
};

int main() {
    int col1, col2;

    col1 = read_color("Erste Grundfarbe");

    col2 = read_color("Zweite Grundfarbe");

    printf(" Die Mischfarbe ist dann %s\n", mix_col[tabelle[col1][col2]]);

    return 0;
}

int read_color(char *text) {
    int i;
    char color[MAX];

    while (1) {
        /// Aufforderung zur Eingabe ausdrucken
        printf("%s (", text);
        for (i = 0; i < 3; i++)
            printf("%s ", base_col[i]);
        printf("): ");

        /// Einlesen
        fgets(color, MAX, stdin);
        color[strlen(color) - 1] = '\0';

        for (i = 0; i < 3; i++)
            if (strcmp(color, base_col[i]) == 0)
                break;
        if (i > 2)
            printf("...Unbekannte Grundfarbe %s (Neue Eingabe machen)\n", color);
        else
            return i;
    }
}