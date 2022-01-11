#include <stdio.h>

#include "matrixOp.h"

int main() {
    Matrix rueckgabe, rueckgabe2, rueckgabe3;
    MatTyp ret_f, value;
    int auswahl;
    unsigned int z, s;
    double det;

    int ret = 0; //Nur um keine Warnungen bei scanf zu bekommen
    ret++;

    printf(
            "0 = creatematrixzero\n"
            "1 = creatematrixrand\n"
            "2 = copymatrix\n"
            "3 = getentryat\n"
            "4 = setentryat\n"
            "5 = addmatrix\n"
            "6 = submatrix\n"
            "7 = multmatrix\n"
            "8 = transmatrix\n"
            "9 = determMatrix\n"
            "Sonstiges = Ende\n");

    ret = scanf("%d", &auswahl);

    switch (auswahl) {
        case 0: {
            printf("Spalten,Zeilen: ");
            fflush(stdin);
            ret = scanf("%d,%d", &s, &z);
            printf("%d,%d", s, z);
            rueckgabe = createMatrixZero(s, z);
            printMatrix(rueckgabe);
            break;
        }

        case 1: {
            printf("Spalten,Zeilen: ");
            fflush(stdin);
            ret = scanf("%d,%d", &s, &z);
            rueckgabe = createMatrixRand(s, z);
            printMatrix(rueckgabe);
            break;
        }

        case 2: {
            printf("Spalten,Zeilen: ");
            fflush(stdin);
            ret = scanf("%d,%d", &s, &z);
            rueckgabe = createMatrixRand(s, z);
            rueckgabe2 = copyMatrix(rueckgabe);
            printf("Eingabe: \n");
            printMatrix(rueckgabe);
            printf("Kopierte: \n");
            printMatrix(rueckgabe2);
            break;
        }

        case 3: {
            printf("xPos,yPos: ");
            fflush(stdin);
            ret = scanf("%d,%d", &s, &z);
            rueckgabe = createMatrixRand(3, 3);
            ret_f = getEntryAt(rueckgabe, s, z);
            printMatrix(rueckgabe);
            printf("\n%7.2f", ret_f);
            break;
        }

        case 4: {
            printf("xPos,yPos,Value: ");
            fflush(stdin);
            ret = scanf("%d,%d,%f", &z, &s, &value);
            rueckgabe = createMatrixZero(3, 2);
            setEntryAt(rueckgabe, z, s, value);
            printMatrix(rueckgabe);
            break;
        }

        case 5: {
            rueckgabe = createMatrixRand(3, 3);
            rueckgabe2 = createMatrixRand(3, 3);
            rueckgabe3 = addMatrix(rueckgabe, rueckgabe2);
            printMatrix(rueckgabe);
            printf("\n");
            printMatrix(rueckgabe2);
            printf("\n");
            printMatrix(rueckgabe3);
            printf("\n");
            break;
        }

        case 6: {
            rueckgabe = createMatrixRand(3, 3);
            rueckgabe2 = createMatrixRand(3, 3);
            rueckgabe3 = subMatrix(rueckgabe, rueckgabe2);
            printMatrix(rueckgabe);
            printf("\n");
            printMatrix(rueckgabe2);
            printf("\n");
            printMatrix(rueckgabe3);
            printf("\n");
            break;
        }

        case 7: {
            rueckgabe = createMatrixRand(3, 3);
            rueckgabe2 = createMatrixRand(3, 3);
            rueckgabe3 = multMatrix(rueckgabe, rueckgabe2);
            printMatrix(rueckgabe);
            printf("\n");
            printMatrix(rueckgabe2);
            printf("\n");
            printMatrix(rueckgabe3);
            printf("\n");
            break;
        }

        case 8: {
            rueckgabe = createMatrixRand(3, 2);
            rueckgabe2 = transposeMatrix(rueckgabe);
            printMatrix(rueckgabe);
            printf("\n");
            printMatrix(rueckgabe2);
            printf("\n");
            break;
        }

        case 9: {
            rueckgabe = createMatrixRand(2, 2);
            printMatrix(rueckgabe);
            det = determMatrix(rueckgabe);
            printf("det(A) = %f", det);
            break;
        }
        default:
            printf("Ende...\n");

    }
    return 0;
}
