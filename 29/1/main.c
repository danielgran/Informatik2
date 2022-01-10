#include <stdio.h>

#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

typedef enum {
    salz, schwefel, salpeter, kohle
} saure;

typedef enum {
    natron, kalium, kalk
} lauge;

char *get_name_from_saure(saure name) {
    switch (name) {
        case salz:
            return "chlorid";
        case schwefel:
            return "sulfat";
        case salpeter:
            return "nitrat";
        case kohle:
            return "carbonat";
        default:
            return "undef";
    }
}

char *get_name_from_lauge(lauge name) {
    switch (name) {
        case natron:
            return "Natrium";
        case kalium:
            return "Kalium";
        case kalk:
            return "Calcium";
        default:
            return "undef";
    }
}

int main() {

    printf("%-30s || %-31s | %-31s | %-31s | %-31s\n",
           "", "Salzsäure", "Schwefelsäure", "Salpetersäure", "Kohlensäure");


    printf("%-30s || %-30s | %-30s | %-30s | %-30s\n",
           "Natronlauge",
           concat(get_name_from_lauge(natron), get_name_from_saure(salz)),
           concat(get_name_from_lauge(natron), get_name_from_saure(schwefel)),
           concat(get_name_from_lauge(natron), get_name_from_saure(salpeter)),
           concat(get_name_from_lauge(natron), get_name_from_saure(kohle)));

    printf("%-30s || %-30s | %-30s | %-30s | %-30s\n",
           "Kalilauge",
           concat(get_name_from_lauge(kalium), get_name_from_saure(salz)),
           concat(get_name_from_lauge(kalium), get_name_from_saure(schwefel)),
           concat(get_name_from_lauge(kalium), get_name_from_saure(salpeter)),
           concat(get_name_from_lauge(kalium), get_name_from_saure(kohle)));

    printf("%-30s || %-30s | %-30s | %-30s | %-30s\n",
           "Kalkwasser",
           concat(get_name_from_lauge(kalk), get_name_from_saure(salz)),
           concat(get_name_from_lauge(kalk), get_name_from_saure(schwefel)),
           concat(get_name_from_lauge(kalk), get_name_from_saure(salpeter)),
           concat(get_name_from_lauge(kalk), get_name_from_saure(kohle)));


    return 0;
}
