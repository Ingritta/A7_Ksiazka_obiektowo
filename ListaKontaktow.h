#ifndef LISTAKONTAKTOW_H
#define LISTAKONTAKTOW_H

#include <iostream>
#include "AdresatMenedzer.h"

using namespace std;

class ListaKontaktow {
    AdresatMenedzer adresatMenedzer;
public:
    ListaKontaktow(string nazwaPlikuZAdresatami) : adresatMenedzer(nazwaPlikuZAdresatami) {
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    };
    int dodajAdresata();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatow();
};

#endif


