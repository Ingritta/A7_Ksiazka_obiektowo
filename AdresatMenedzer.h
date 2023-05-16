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
    string daneAdresataOddzielonePionowymiKreskami;
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat);
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
        idZalogowanegoUzytkownika = 0;
    };
    void ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    bool sprawdzCzyWpisanoAdresatow();
    void wylogujUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();
    int pobierzIdAdresata();
    Adresat podajDaneNowegoAdresata();
    void dodajAdresata(int idZalogowanegoUzytkownika);
};

#endif
