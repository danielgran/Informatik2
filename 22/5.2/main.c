/**********************************************************************\
* Aufgabe 22.5.2 (Gr��ter gemeinsamer Teiler)
*
* Datum: 27.10.2019
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>

unsigned long ggt(unsigned long n, long m)
{
    unsigned long result = (m==0) ? n : ggt(m,n%m);

    return result;
}

int main()
{
    unsigned long teiler, input;
    int i = 1;

    printf("Gib nicht-negative ganze Zahlen ein (Ende=0)\n");
    printf("%i. Zahl: ",i);
    scanf("%i", &teiler);
    printf("%i. Zahl: ",++i);
    scanf("%i", &input);
    teiler = ggt(teiler, input);

    while (input != 0)
    {
        i++;
        printf("%i. Zahl: ",i);
        scanf("%i", &input);

        teiler = ggt(teiler,input);

    }
    printf("Der groesste gemeinsame Teiler ist: %i", teiler);
    return 0;
}

