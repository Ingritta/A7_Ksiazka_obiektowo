#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy {
    int idOstatniegoAdresata;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami;
    string daneAdresataOddzielonePionowymiKreskami;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneOstaniegoAdresataWPliku);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {
        idOstatniegoAdresata = 0;
    };
    int pobierzIdOstatniegoAdresata();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    void usunAdresataZPliku();
    void edytujWybranaLinieWPliku(string liniaZDanymiAdresata, int idEdytowanegoAdresata);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void dopisz(string tekst);
};

#endif
