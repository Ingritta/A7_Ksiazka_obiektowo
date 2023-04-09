#ifndef ADRESATKMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer {
    int idZalogowanegoUzytkownika;
    //vector <Uzytkownik> uzytkownicy;
    vector <Adresat> adresaci;

    //Uzytkownik podajDaneNowegoUzytkownika();
    //int pobierzIdNowegoUzytkownika();
    //bool czyIstniejeLogin(string login);
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    //void rejestracjaUzytkownika();
    //void wypiszWszystkichUzytkownikow();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif
