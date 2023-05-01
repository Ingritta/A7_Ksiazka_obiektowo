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
    int idOstatniegoAdresata;
    Adresat adresat;
    const string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string daneJednegoAdresataOddzielonePionowymiKreskami;
    string daneAdresataOddzielonePionowymiKreskami;

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami();
    int dodajAdresata();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();
    void dopiszAdresataDoPliku(Adresat adresat);
    Adresat pobierzDaneAdresata();
    Adresat podajDaneNowegoAdresata();
    int pobierzIdUzytkownika();//??
};

#endif
