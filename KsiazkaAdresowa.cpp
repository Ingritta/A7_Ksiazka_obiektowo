#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika() {
    idZalogowanegoUzytkownika = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
    cout << "idZalogowanegoUzytkownika w funkcji KsiazkaAdresowa::logowanieUzytkownika :" << idZalogowanegoUzytkownika << endl;
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    return idZalogowanegoUzytkownika;
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
