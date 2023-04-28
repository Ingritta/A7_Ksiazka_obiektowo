#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {
    Adresat adresat;
    const string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string daneJednegoAdresataOddzielonePionowymiKreskami;
    string daneAdresataOddzielonePionowymiKreskami;

public:
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();
    Adresat pobierzDaneAdresata();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami();
    int dodajAdresata();
    Adresat podajDaneNowegoAdresata();
};

#endif
