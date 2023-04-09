#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    //AdresatMenedzer adresatMenedzer;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    /*
    KsiazkaAdresowa(string nazwaPlikuZAdresatami) : adresatMenedzer(nazwaPlikuZAdresatami) {
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    };
*/
};

#endif


