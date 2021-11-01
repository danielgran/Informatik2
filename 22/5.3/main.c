/**********************************************************************\
* Aufgabe 22.5.3 (Umwandeln einer Dezimalzahl in Dualzahl)
*
* Datum: 22.10.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>

void convert(int decimal)
{
    if (decimal!=0)
    {
        convert(decimal/2);
        printf("%i", decimal%2);
    }
}

int main()
{
    int dec;
    printf("Gib eine Dezimalzahl ein: ");
    scanf("%i", &dec);
    printf("Die Dualzahl dazu lautet: ");
    convert(dec);
}
