#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer {
    int idZalogowanegoUzytkownika;
    string daneAdresataOddzielonePionowymiKreskami;
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata();
    int idOstatniegoAdresata;

public:
    vector <Adresat> adresaci;
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
    idZalogowanegoUzytkownika = 0;
    };
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool sprawdzCzyWpisanoAdresatow();
    void wylogujUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();
    };

#endif
