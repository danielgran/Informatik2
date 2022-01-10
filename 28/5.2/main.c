#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
typedef unsigned long ulong;

struct zeit {
    ulong day;
    ulong hour;
    ulong min;
    ulong seks;
};

ulong zeit_in_sek(struct zeit z) {
    ulong secs = 0;
    secs += z.day * 24 * 60 * 60;
    secs += z.hour * 60 * 60;
    secs += z.min * 60;
    secs += z.seks;

    return secs;
}

struct zeit repair_time(struct zeit z) {
    struct zeit value;
    ulong remaining_secs = zeit_in_sek(z);

    ulong days = remaining_secs / (24 * 60 * 60);
    value.day = days;
    remaining_secs -= days * 24 * 60 * 60;

    ulong hours = remaining_secs / (60 * 60);
    value.hour = hours;
    remaining_secs -= hours * 60 * 60;

    ulong minutes = remaining_secs / 60;
    value.min = minutes;
    remaining_secs -= minutes * 60;

    value.seks = remaining_secs;
    return value;
}

struct zeit sek_in_zeit(ulong sek) {
    struct zeit value;

    value.seks = sek;

    value = repair_time(value);

    return value;
}

struct zeit add_times(struct zeit z1, struct zeit z2) {

    struct zeit sum;
    sum.day = z1.day + z2.day;
    sum.hour = z1.hour + z2.hour;
    sum.min = z1.min + z2.min;
    sum.seks = z1.seks + z2.seks;

    struct zeit repaired = repair_time(sum);

    return repaired;
}


int main() {

    struct zeit time1, time2, sum;

    const char delimiter = '.';

    char eingabe[1000];

    printf("Zeit eingeben:(tt.hh.mm.ss) ");
    fflush(stdin);
    fgets(eingabe, MAX, stdin);

    time1.day = atoi(strtok(eingabe, &delimiter));
    time1.hour = atoi(strtok(NULL, &delimiter));
    time1.min = atoi(strtok(NULL, &delimiter));
    time1.seks = atoi(strtok(NULL, &delimiter));

    printf("Zeit eingeben:(tt.hh.mm.ss) ");
    fflush(stdin);
    fgets(eingabe, MAX, stdin);

    time2.day = atoi(strtok(eingabe, &delimiter));
    time2.hour = atoi(strtok(NULL, &delimiter));
    time2.min = atoi(strtok(NULL, &delimiter));
    time2.seks = atoi(strtok(NULL, &delimiter));

    sum = add_times(time1, time2);

    printf("Summe: %lu Tage, %lu Stunden, %lu Minuten, %lu Sekunden", sum.day, sum.hour, sum.min, sum.seks);


    return 0;
}
