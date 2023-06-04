#include "PlikTekstowy.h"
#include "PlikZUzytkownikami.h"

bool PlikTekstowy::czyPlikJestPusty() {
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::out | ios::app);

    plikTekstowy.seekg(0, ios::end);
    return plikTekstowy.tellg() == 0;
}

string PlikTekstowy::pobierzNazwePliku() {
    return NAZWA_PLIKU;
}

