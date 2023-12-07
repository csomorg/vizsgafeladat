#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Ez a függvény megadja, hogy egy megadott karakter hányszor szerepel a szövegben.
int elofordulas(char szoveg[], char karakter) {
    int darab = 0;
    int hossz = strlen(szoveg);

    // Végigszámoljuk a karaktereket a szövegben és ha kell növeljük a darab változóban eltárolt értéket.
    for (int i = 0; i < hossz; i++) {
        if (szoveg[i] == karakter) {
            darab++;
        }
    }
    return darab;
}

// Pontok ellenõrzése
bool egymasmellettiellenorzes(char szoveg[]) {
    // Végigszámoljuk a karaktereket a szövegben és ellenõrizzük, hogy van-e két pont egymás után. Ha van hamis értéket adunk vissza.
    int hossz = strlen(szoveg);

    for (int i = 0; i<hossz; i++) {
        if (szoveg[i] == '.' && szoveg[i + 1] == '.') {
            return false; }
        if (szoveg[i] == '.' && szoveg[i + 1] == '@') {
            return false;}
        if (szoveg[i] == '@' && szoveg[i + 1] == '.') {
            return false;
        }
    }

    if (szoveg[0] == '@' || szoveg[0] == '.' || szoveg[hossz - 1] == '@' || szoveg[hossz - 1] == '.') {
        return false;
    }

    return true;
}

// Az ellenõrzés alapján kiírja, hogy érvényes-e a megadott e-mail cím
void kiiratas(char email[]) {
    int kukacokszama = elofordulas(email, '@');  // Hányszor van a kukac jel a szövegben
    int pontokszama = elofordulas(email,'.'); // Pontok száma

    if (kukacokszama == 1 && pontokszama>=1 && egymasmellettiellenorzes(email)) {
        printf("A megadott szoveg e-mail cim.\n");
    } else {
        printf("A megadott szoveg nem e-mail cim.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc !=2) {printf("Hianyzik a parameter, igy nem tudom ellenorizni.");
    } else {
    char *emailcim = argv[1];
    kiiratas(emailcim);
    return 0;}
}
