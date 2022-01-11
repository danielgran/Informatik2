/**********************************************************************\
* Kurzbeschreibung:
* queue.c - realisiert eine Queue (Warteschlange)
*
* Datum:     Autor:
* 
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/
struct element *anfang, *ende;

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\
 * Einfuegen in Liste
 * Parameter:
 *    zahl  fügt die übergebene Zahl 'zahl' am Ende der Liste ein
 * Return Wert:
 *    TRUE  wenn noch genug Speicherplatz vorhanden
 *    FALSE wenn kein Speicherplatz mehr allokiert werden konnte
 *--------------------------------------------------------------------*/
Bool put(int zahl) {
    struct element *le;

    le = (struct element *) malloc(sizeof(struct element));
    if (le == NULL) {
        printf("Speicherplatzmangel...");
        exit(1);
    }


    le->next = NULL;
    le->value = zahl;

    if (isEmpty()) { //Kein Element in der Liste
        anfang = le;
        ende = le;
    } else { //Ein Element in der Liste
        ende->next = le;
        ende = le;
    }

    return TRUE;
}

/*--------------------------------------------------------------------*\
 * Auslesen aus Liste
 * Parameter:
 *    keine
 * Return Wert:
 *    Zahl am Anfang der Liste oder aber QLEER, wenn Liste leer ist.
 *--------------------------------------------------------------------*/
int get(void) {
    int zahl;
    struct element *zgr;

    if (isEmpty()) {
        return QLEER;
    } else {
        zahl = anfang->value;
        zgr = anfang;
        anfang = anfang->next;
        free(zgr);
    }

    return zahl;
}

/*--------------------------------------------------------------------*\
 * Pruefen der Liste
 * Parameter:
 *    keine
 * Return Wert:
 *    liefert TRUE, wenn Queue leer ist, sonst FALSE
 *--------------------------------------------------------------------*/
Bool isEmpty(void) {
    if (anfang == NULL)
        return TRUE;
    else
        return FALSE;
}
