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
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    string daneAdresataOddzielonePionowymiKreskami;
    int idZalogowanegoUzytkownika;//zrobic zmienna globalna
    string daneJednegoAdresataOddzielonePionowymiKreskami;
    int dodajAdresata();
    PlikZAdresatami plikZAdresatami;

public:
    Adresat adresat;
    vector <Adresat> podajDaneNowegoAdresata();
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void wyswietlWszystkichAdresatow();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlDaneAdresata();
    //Adresat wyswietlDaneAdresata();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    void dopiszAdresataDoPliku();
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    Adresat pobierzDaneAdresata();
};

#endif
