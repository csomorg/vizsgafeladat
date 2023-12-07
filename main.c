#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Ez a f�ggv�ny megadja, hogy egy megadott karakter h�nyszor szerepel a sz�vegben.
int elofordulas(char szoveg[], char karakter) {
    int darab = 0;
    int hossz = strlen(szoveg);

    // V�gigsz�moljuk a karaktereket a sz�vegben �s ha kell n�velj�k a darab v�ltoz�ban elt�rolt �rt�ket.
    for (int i = 0; i < hossz; i++) {
        if (szoveg[i] == karakter) {
            darab++;
        }
    }
    return darab;
}

// Pontok ellen�rz�se
bool egymasmellettiellenorzes(char szoveg[]) {
    // V�gigsz�moljuk a karaktereket a sz�vegben �s ellen�rizz�k, hogy van-e k�t pont egym�s ut�n. Ha van hamis �rt�ket adunk vissza.
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

// Az ellen�rz�s alapj�n ki�rja, hogy �rv�nyes-e a megadott e-mail c�m
void kiiratas(char email[]) {
    int kukacokszama = elofordulas(email, '@');  // H�nyszor van a kukac jel a sz�vegben
    int pontokszama = elofordulas(email,'.'); // Pontok sz�ma

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
