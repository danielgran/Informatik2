/**********************************************************************\
* Aufgabe 25.5.2
*
* Datum: 01.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>

static char *NummerZuTag(int wochentag) {
    static char *strings[] = {"Sonntag", "Modntag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Sonntag"};
    return strings[wochentag];
}

int main() {

    int jh_koeff[4] = {4, 2, 0, 5};
    int monat_koeff[12] = {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0};

    enum WochentagEnum {
        Sonntag = 0,
        Montag = 1,
        Dienstag = 2,
        Mittwoch = 3,
        Donnerstag = 4,
        Freitag = 5,
        Samstag = 6
    };
    int tag = 0, jahr = 0, monat = 0, schaltjahr = 0, wochentag = 0;
    printf("Gib ein Datum ein (tt.mm.jjjj): ");
    scanf("%d.%d.%d", &tag, &monat, &jahr);
    printf("%d", tag);

    int jh = jahr / 100;
    int ja = jahr % 100;

    if (monat > 2) {
        schaltjahr = 0;
    } else {
        if (jahr % 400 == 0) {
            schaltjahr = 1;
        } else {
            if (ja == 0) {
                schaltjahr = 0;
            } else {
                if (jahr % 4 == 0) {
                    schaltjahr = 1;
                } else {
                    schaltjahr = 0;
                }
            }
        }
    }

    int tagnummer = (tag + monat_koeff[monat - 1] - schaltjahr + jh_koeff[jh % 4] + ja + ja / 4);

    char *c = NummerZuTag(tagnummer);
    printf("%s", c);

    return 0;

}
