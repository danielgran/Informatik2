/**********************************************************************\
* Kurzbeschreibung: complex.c
* Bietet Funktionen zum Rechnen mit komplexen Zahlen
*
* Datum:       Autor:        Grund der Aenderung:
*
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <float.h>
#include <stdio.h>
#include "complexma1lib.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\
* Addition komplexer Zahlen: x + y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex addComplex(Complex x, Complex y) {
    Complex sum;
    sum.real = x.real + y.real;
    sum.imag = x.imag + y.imag;
    return sum;
}

/*--------------------------------------------------------------------*\
* Subtraktion komplexer Zahlen: x - y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex subComplex(Complex x, Complex y) {
    Complex dif;
    dif.real = x.real - y.real;
    dif.imag = x.imag - y.imag;
    return dif;
}

/*--------------------------------------------------------------------*\
* Multiplikation komplexer Zahlen: x * y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex mulComplex(Complex x, Complex y) {
    Complex mul;
    mul.real = x.real * y.real - x.imag * y.imag;
    mul.imag = x.real * y.imag + x.imag * y.real;
    return mul;
}

/*--------------------------------------------------------------------*\
* Division komplexer Zahlen: x / y
* Rueckgabe: Ergebnis im Typ "Complex"; im Fehlerfall 0. bzw. ERROR_C
\*--------------------------------------------------------------------*/
Complex divComplex(Complex x, Complex y) {
    Complex div;
    div.imag = 0;
    div.real = 0;

    if (y.real == 0 && y.imag == 0) return div;

    div.real = (x.real * y.real + x.imag * y.imag) / (y.real * y.real + y.imag * y.imag);
    div.imag = (x.imag * y.real - x.real * y.imag) / (y.real * y.real + x.imag * x.imag);

    return div;
}

/*--------------------------------------------------------------------*\
* Lesbar formatierte Ausgabe einer komplexen Zahl
\*--------------------------------------------------------------------*/
int printComplex(Complex z) {
    printf("(%.3f + %.3fi)", z.real, z.imag);
    return 1;
}

