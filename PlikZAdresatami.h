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
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string daneJednegoAdresataOddzielonePionowymiKreskami;
    string daneAdresataOddzielonePionowymiKreskami;
     int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
     int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneOstaniegoAdresataWPliku);//??
     Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
    idOstatniegoAdresata = 0;
    };
    int pobierzIdOstatniegoAdresata();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);//?
    void dopiszAdresataDoPliku(Adresat adresat);


    //nt pobierzIdUzytkownika();
    //void ustawIdOstatniegoAdresata(int idOstatniegoAdresata);
};

#endif
