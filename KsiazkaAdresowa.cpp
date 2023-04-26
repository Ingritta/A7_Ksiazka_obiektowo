#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
/*
int KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    //adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}
*/
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wczytajUzytkownikowZPliku() {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    adresatMenedzer.wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

int KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer.dodajAdresata();
}

int KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

bool KsiazkaAdresowa::sprawdzCzyUzytkownikJestZalogowany() {
    uzytkownikMenedzer.sprawdzCzyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    adresatMenedzer.wylogujUzytkownika();
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika();
}

bool KsiazkaAdresowa::sprawdzCzyWpisanoAdresatow() {
    adresatMenedzer.sprawdzCzyWpisanoAdresatow();
}

int KsiazkaAdresowa::ustawIdZalogowanegoUzytkownika() {
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
