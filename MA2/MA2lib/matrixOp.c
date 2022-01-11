/**********************************************************************\
* Kurzbeschreibung: matrixOp.c
* Bietet Funktionen fuer Operationen mit Matrizen
*
* Datum:       Autor:        Grund der Aenderung:
* 
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrixOp.h"

/*--- #defines -------------------------------------------------------*/
#define LIMITZUFALL 200
/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\ 
* Erstellt eine neue Matrix (cM)
*  - reserviert lediglich den notwendigen Speicher
*  - dynamische Verwaltung von Speicher muss mit malloc() und free() 
*    durchgef�hrt werden; dynamische Arrays sind nicht erlaubt !!!
\*--------------------------------------------------------------------*/
Matrix createMatrix(unsigned int spalten, unsigned int zeilen) {
    Matrix rueckgabe;

    rueckgabe.mElement = malloc(zeilen * spalten * sizeof(MatTyp));
    if (rueckgabe.mElement == NULL) {
        printf("Speicherplatzmangel....");
        exit(1);
    }

    rueckgabe.spalten = spalten;
    rueckgabe.zeilen = zeilen;

    return rueckgabe;
}

/*--------------------------------------------------------------------*\
* Erstellt und initialisiert eine neue Matrix (zM)
* - reserviert den notwendigen Speicher
* - befuellt die Matrix mit 0
\*--------------------------------------------------------------------*/
Matrix createMatrixZero(unsigned int spalten, unsigned int zeilen) {
    unsigned int i;
    Matrix rueckgabe;

    rueckgabe = createMatrix(spalten, zeilen);

    for (i = 0; i < (zeilen * spalten); i++)
        *(rueckgabe.mElement + i) = 0;

    return rueckgabe;
}

/*--------------------------------------------------------------------*\
* Erstellt und initialisiert eine neue Matrix (rM)
* - reserviert den notwendigen Speicher
* - befuellt die Matrix mit Zufallszahlen
\*--------------------------------------------------------------------*/
Matrix createMatrixRand(unsigned int spalten, unsigned int zeilen) {
    unsigned int i;
    //srand(time(NULL));
    Matrix rueckgabe;

    rueckgabe = createMatrix(spalten, zeilen);

    for (i = 0; i < (spalten * zeilen); i++)
        *(rueckgabe.mElement + i) = rand() % LIMITZUFALL;

    return rueckgabe;
}

/*--------------------------------------------------------------------*\
* Kopiert eine Matrix und gibt die Kopie zurueck (yM)
\*--------------------------------------------------------------------*/
Matrix copyMatrix(const Matrix toCopy) {
    Matrix rueckgabe;

    rueckgabe.mElement = toCopy.mElement;
    rueckgabe.spalten = toCopy.spalten;
    rueckgabe.zeilen = toCopy.zeilen;

    return rueckgabe;
}

/*--------------------------------------------------------------------*\
* "Loescht" eine Matrix (dM)
* - gibt reservierten Speicher wieder frei !
* - in der urspruenglichen, uebergebenen Matrix bleiben die Werte erhalten!
\*--------------------------------------------------------------------*/
void deleteMatrix(Matrix toDelete) {
    free(toDelete.mElement);
}

/*--------------------------------------------------------------------*\
* "Loescht / Zerstoert" eine uebergegebene Matrix (ddM)
* - gibt Speicher wieder frei, setzt alle Werte auf NULL bzw. "0" !
* - Beachte Unterschiede zur vorigen Funktion !!! 
\*--------------------------------------------------------------------*/
void destroyMatrix(Matrix *pToDestroy) {
    free((*pToDestroy).mElement);
    (*pToDestroy).mElement = NULL;
    (*pToDestroy).zeilen = 0;
    (*pToDestroy).spalten = 0;
}

/*--------------------------------------------------------------------*\
* Gibt den Eintrag der Matrix an der Stelle (xPos, yPos) zurueck (gE)
* Rueckgabe im Fehlerfall: ERROR
\*--------------------------------------------------------------------*/
MatTyp getEntryAt(const Matrix ma, unsigned int xPos, unsigned int yPos) {
    MatTyp ret; //Erstes Element (0,0)

    if ((ma.spalten * ma.zeilen) < (yPos * ma.spalten + xPos))
        return ERROR;

    ret = *(ma.mElement + yPos * ma.spalten + xPos);

    return ret;
}

/*--------------------------------------------------------------------*\
* Setzt den Eintrag der Matrix an der Stelle (xPos, yPos) (sE)
* Rueckgabe: TRUE, im Fehlerfall: FALSE
\*--------------------------------------------------------------------*/
Bool setEntryAt(Matrix ma, unsigned int xPos, unsigned int yPos, MatTyp value) {
    if ((ma.spalten * ma.zeilen) < (yPos * ma.spalten + xPos))
        return FALSE;

    *(ma.mElement + yPos * ma.spalten + xPos) = value;

    return TRUE;
}

/*--------------------------------------------------------------------*\
* Gibt eine Matrix im Kommandofenster "schoen formatiert" aus (pM)
\*--------------------------------------------------------------------*/
void printMatrix(const Matrix ma) {
    unsigned int s, z;

    for (z = 0; z < ma.zeilen; z++) {
        printf("\n(");
        for (s = 0; s < ma.spalten; s++)
            printf(" %7.2f ", *(ma.mElement + s + z * ma.spalten));
        printf(")");
    }
    printf("\n");
}

/*--------------------------------------------------------------------*\
* Addiert zwei Matrizen (aM)
* Rueckgabe:
* - Ergebnis der Addition in neu erzeugter Matrix
* - Rueckgabe im Fehlerfall: Matrix der Groesse "0"
\*--------------------------------------------------------------------*/
Matrix addMatrix(const Matrix ma, const Matrix mb) {
    Matrix ergebnis;
    unsigned int z, s;

    ergebnis = createMatrix(ma.spalten, ma.zeilen);

    if ((ma.spalten != mb.spalten) || (ma.zeilen != mb.zeilen)) {
        ergebnis.zeilen = 0;
        ergebnis.spalten = 0;
        ergebnis.mElement = NULL;
    } else {
        for (z = 0; z < ergebnis.zeilen; z++)
            for (s = 0; s < ergebnis.spalten; s++)
                *(ergebnis.mElement + s + z * ergebnis.zeilen) =
                        *(ma.mElement + s + z * ergebnis.zeilen) +
                        *(mb.mElement + s + z * ergebnis.zeilen);
    }

    return ergebnis;
}

/*--------------------------------------------------------------------*\
* Subtrahiert zwei Matrizen (sM)
* Rueckgabe: "ma - mb"
* - Ergebnis der Subtraktion in neu erzeugter Matrix
* - Rueckgabe im Fehlerfall: Matrix der Groesse "0"
\*--------------------------------------------------------------------*/
Matrix subMatrix(const Matrix ma, const Matrix mb) {
    Matrix ergebnis;
    unsigned int z, s;

    ergebnis = createMatrix(ma.spalten, ma.zeilen);

    if ((ma.spalten != mb.spalten) || (ma.zeilen != mb.zeilen)) {
        ergebnis.zeilen = 0;
        ergebnis.spalten = 0;
        ergebnis.mElement = NULL;
    } else {
        for (z = 0; z < ergebnis.zeilen; z++)
            for (s = 0; s < ergebnis.spalten; s++)
                *(ergebnis.mElement + s + z * ergebnis.zeilen) =
                        *(ma.mElement + s + z * ergebnis.zeilen) -
                        *(mb.mElement + s + z * ergebnis.zeilen);
    }

    return ergebnis;
}

/*--------------------------------------------------------------------*\
* Multipliziert zwei Matrizen (mM)
* Rueckgabe: "ma * mb"
* - Ergebnis der Multiplikation in neu erzeugter Matrix
* - Rueckgabe im Fehlerfall: Matrix der Groesse "0"
\*--------------------------------------------------------------------*/
Matrix multMatrix(const Matrix ma, const Matrix mb) {
    Matrix ergebnis;
    unsigned int z, s, i;

    ergebnis = createMatrix(mb.spalten, ma.zeilen); //Zeilen von A und Spalten von B

    if (ma.spalten != mb.zeilen) {
        //Spalten A == Zeilen B
        ergebnis.zeilen = 0;
        ergebnis.spalten = 0;
        ergebnis.mElement = NULL;
    } else {
        for (z = 0; z < ma.zeilen; z++)
            for (s = 0; s < mb.spalten; s++)
                for (i = 0; i < ma.spalten; i++)
                    *(ergebnis.mElement + s + z * ergebnis.spalten) +=
                            *(ma.mElement + i + z * ma.zeilen) *
                            *(mb.mElement + s + i * mb.zeilen);
    }

    return ergebnis;
}

/*--------------------------------------------------------------------*\
* Transponiert eine Matrix (tM)
* Rueckgabe: "ma^T"
\*--------------------------------------------------------------------*/
Matrix transposeMatrix(const Matrix ma) {
    Matrix ergebnis;
    unsigned int z, s;

    ergebnis = createMatrix(ma.zeilen, ma.spalten); //Spalten(t) = Zeilen(ma); Zeilen(t) = Spalten(ma)

    for (z = 0; z < ma.zeilen; z++)
        for (s = 0; s < ma.spalten; s++)
            *(ergebnis.mElement + z + s * ergebnis.spalten) =
                    *(ma.mElement + s + z * ma.spalten);

    return ergebnis;
}

/*--------------------------------------------------------------------*\
* Gibt die Determinante der Matrix ma zurueck (dt)
* Rueckgabe im Fehlerfall: ERROR
* !!! Optional / Implementation freiwillig !!!
* fuer kleine Matrizen reicht ein einfacher Algorithmus
* wer moechte kann auch ein effizientes Verfahren implementieren
\*--------------------------------------------------------------------*/
double determMatrix(const Matrix ma) {
    /// Algorithmus aktuell nur f¸r 2x2 Matrizen implementiert
    if (ma.spalten != ma.zeilen) {
        printf("ERROR! Determinante kann nicht gebildet werden!\n");
        return ERROR;
    } else if (ma.spalten != 2) {
        printf("ERROR! Dieses Programm kann leider nur 2x2 Matrizen!");
        return ERROR;
    }

    unsigned int s, z;
    float elements[ma.zeilen][ma.spalten];

    /// Formel: det(A) = a*c - b*d
    for (z = 0; z < ma.spalten; z++)
        for (s = 0; s < ma.spalten; s++)
            elements[z][s] = *(ma.mElement + s + z * ma.spalten);

    return (elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0]); // det(A) = a*d - b*c;
}

