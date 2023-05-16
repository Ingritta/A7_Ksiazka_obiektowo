#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
/*
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
*/
void KsiazkaAdresowa::logowanieUzytkownika() {
    int idZalogowanegoUzytkownika = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wczytajUzytkownikowZPliku() {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownikaNaZero();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    return uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    return adresatMenedzer.wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    adresatMenedzer.wylogujUzytkownika();
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownikaNaZero();
}

bool KsiazkaAdresowa::sprawdzCzyWpisanoAdresatow() {
    return adresatMenedzer.sprawdzCzyWpisanoAdresatow();
}

bool KsiazkaAdresowa::sprawdzCzyUzytkownikJestZalogowany() {
    return uzytkownikMenedzer.sprawdzCzyUzytkownikJestZalogowany();
}
