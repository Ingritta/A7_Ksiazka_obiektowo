#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
   uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.sprawdzCzyUzytkownikJestZalogowany() == false)
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata() {
       adresatMenedzer -> dodajAdresata();
}

void KsiazkaAdresowa::wczytajUzytkownikowZPliku() {
    //uzytkownikMenedzer.ustawIdZalogowanegoUzytkownikaNaZero();
    //plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    return uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    return adresatMenedzer -> wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenedzer -> wyswietlWszystkichAdresatow();
}

bool KsiazkaAdresowa::sprawdzCzyWpisanoAdresatow() {
    return adresatMenedzer -> sprawdzCzyWpisanoAdresatow();
}

bool KsiazkaAdresowa::sprawdzCzyUzytkownikJestZalogowany() {
    return uzytkownikMenedzer.sprawdzCzyUzytkownikJestZalogowany();
}
