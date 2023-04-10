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
    vector <Adresat> adresaci;
    Adresat adresat;
    const string nazwaPlikuZAdresatami;
    int idZalogowanegoUzytkownika;
    fstream plikTekstowy;
    bool czyPlikJestPusty();

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dopiszAdresataDoPliku();
};

#endif
