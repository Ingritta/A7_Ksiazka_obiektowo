#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wczytajUzytkownikowZPliku() {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownikaNaZero();
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
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownikaNaZero();
}

bool KsiazkaAdresowa::sprawdzCzyWpisanoAdresatow() {
    adresatMenedzer.sprawdzCzyWpisanoAdresatow();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
