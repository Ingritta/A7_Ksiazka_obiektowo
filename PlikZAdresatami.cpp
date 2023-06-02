#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "AdresatMenedzer.h"

vector <Adresat>  PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;

    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out |ios::app);
    plikTekstowy.close();

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good()) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

bool PlikZAdresatami::czyPlikJestPusty() {
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    plikTekstowy.seekg(0, ios::end);
    return plikTekstowy.tellg() == 0;
}

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    fstream plikTekstowy;
    string liniaZDanymiAdresata = "";
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good()) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty()) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata;
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    idOstatniegoAdresata++;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));

    return idAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdZalogowanegoUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idZalogowanegoUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idZalogowanegoUzytkownika;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunAdresataZPliku() {
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1, numerUsuwanejLinii = 0, idUsuwanegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "", liniaZDanymiAdresata = "";
    fstream ksiazkaAdresowa, tymczasowaKsiazkaAdresowa;
    char znak;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = MetodyPomocnicze::podajIdWybranegoAdresata();

    ksiazkaAdresowa.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowaKsiazkaAdresowa.open("TymczasowaKsiazkaAdresowa.txt", ios::out | ios::app);

    if (ksiazkaAdresowa.good() && tymczasowaKsiazkaAdresowa.good() && idUsuwanegoAdresata != 0) {

        while(getline(ksiazkaAdresowa, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idUsuwanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                czyIstniejeAdresat = true;
                cout << endl << "Potwierdz naciskajac klawisz 't': ";
                znak = MetodyPomocnicze::wczytajZnak();

                if (znak == 't') {
                    numerUsuwanejLinii = numerLiniiWPlikuTekstowym;
                    cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                    system("pause");

                } else {
                    cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                    system("pause");
                }
            } else if (numerLiniiWPlikuTekstowym == numerUsuwanejLinii) {}
            else if (numerLiniiWPlikuTekstowym == 1 && numerLiniiWPlikuTekstowym != numerUsuwanejLinii) {
                tymczasowaKsiazkaAdresowa << daneJednegoAdresataOddzielonePionowymiKreskami;
            } else if (numerLiniiWPlikuTekstowym == 2 && numerUsuwanejLinii == 1) {
                tymczasowaKsiazkaAdresowa << daneJednegoAdresataOddzielonePionowymiKreskami;
            } else if (numerLiniiWPlikuTekstowym > 2 && numerUsuwanejLinii == 1) {
                tymczasowaKsiazkaAdresowa << "\n" << daneJednegoAdresataOddzielonePionowymiKreskami;
            } else if (numerLiniiWPlikuTekstowym > 1 && numerUsuwanejLinii != 1) {
                tymczasowaKsiazkaAdresowa << "\n" << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            numerLiniiWPlikuTekstowym++;
        }

        if (czyIstniejeAdresat == false) {
            tymczasowaKsiazkaAdresowa.close();
        }
        ksiazkaAdresowa.close();
        tymczasowaKsiazkaAdresowa.close();
        remove("Adresaci.txt");
        rename("TymczasowaKsiazkaAdresowa.txt", "Adresaci.txt");

    } else {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    }
}

void PlikZAdresatami::edytujWybranaLinieWPliku(string liniaZDanymiAdresata, int idEdytowanegoAdresata) {
    fstream ksiazkaAdresowa, tymczasowaKsiazkaAdresowa;
    string liniaZDanymiAdresataOddzielonePionowymiKreskami = "", wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    ksiazkaAdresowa.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowaKsiazkaAdresowa.open("TymczasowaKsiazkaAdresowa.txt", ios::out | ios::app);

    if (ksiazkaAdresowa.good() && tymczasowaKsiazkaAdresowa.good() && idEdytowanegoAdresata != 0) {

        while(getline(ksiazkaAdresowa, wczytanaLinia)) {

            if(idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)) {

                if (numerWczytanejLinii == 1) {
                    tymczasowaKsiazkaAdresowa << liniaZDanymiAdresata;
                } else if (numerWczytanejLinii > 1) {
                    tymczasowaKsiazkaAdresowa << "\n" << liniaZDanymiAdresata;
                }
            } else {
                if (numerWczytanejLinii == 1) {
                    tymczasowaKsiazkaAdresowa << wczytanaLinia;

                } else if (numerWczytanejLinii > 1) {
                    tymczasowaKsiazkaAdresowa << "\n" << wczytanaLinia;
                }
            }
            numerWczytanejLinii++;
        }
        ksiazkaAdresowa.close();
        tymczasowaKsiazkaAdresowa.close();
        remove("Adresaci.txt");
        rename("TymczasowaKsiazkaAdresowa.txt", "Adresaci.txt");

    } else {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    }
}
