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
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    string daneAdresataOddzielonePionowymiKreskami;
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)  {
        idZalogowanegoUzytkownika = 0;
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();//nie ma
    bool sprawdzCzyWpisanoAdresatow();//nie ma
    char wybierzOpcjeZMenuUzytkownika();//nie ma
    int pobierzIdAdresata();//nie ma
    void wyswietlWszystkichAdresatow();
};

#endif
