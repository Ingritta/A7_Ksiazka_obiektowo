#include <iostream>

#include "KsiazkaAdresowa.h"
#include "ListaKontaktow.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ListaKontaktow listaKontaktow ("Kontakty.txt");
    //listaKontaktow.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    return 0;
}
