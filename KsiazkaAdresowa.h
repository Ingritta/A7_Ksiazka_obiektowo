#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa() {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    };
    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();//nie ma
    void zmianaHaslaZalogowanegoUzytkownika();
    char wybierzOpcjeZMenuGlownego();// nie ma
    char wybierzOpcjeZMenuUzytkownika(); //nie ma
    void dodajAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(); //nie ma
    void wyswietlWszystkichAdresatow();
    bool sprawdzCzyUzytkownikJestZalogowany(); //nie ma
    bool sprawdzCzyWpisanoAdresatow(); //nie ma
    void wylogujUzytkownika();
   void ustawIdZalogowanegoUzytkownikaNaZero(); //nie ma
    int pobierzIdZalogowanegoUzytkownika(); //nie ma
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif

