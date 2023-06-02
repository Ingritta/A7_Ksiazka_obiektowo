#include "Adresat.h"

void Adresat::ustawId(int noweId) {
    if (noweId >= 0) {
        this -> id = noweId;
    }
}

void Adresat::ustawIdZalogowanegoUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA) {
    if (idUzytkownika >= 0) {
        this -> idUzytkownika = ID_ZALOGOWANEGO_UZYTKOWNIKA;
    }
}

void Adresat::ustawImie(string noweImie) {
    this -> imie = noweImie;
}

void Adresat::ustawNazwisko(string noweNazwisko) {
    this -> nazwisko = noweNazwisko;
}

void Adresat::ustawNumerTelefonu(string nowyNumerTelefonu) {
    this -> numerTelefonu = nowyNumerTelefonu;
}

void Adresat::ustawEmail(string nowyEmail) {
    this -> email = nowyEmail;
}

void Adresat::ustawAdres(string nowyAdres) {
    this -> adres = nowyAdres;
}

int Adresat::pobierzId() {
    return this -> id;
}

int Adresat::pobierzIdUzytkownika() {
    return this -> idUzytkownika;
}

string Adresat::pobierzImie() {
    return this -> imie;
}

string Adresat::pobierzNazwisko() {
    return this -> nazwisko;
}

string Adresat::pobierzNumerTelefonu() {
    return this -> numerTelefonu;
}

string Adresat::pobierzEmail() {
    return this -> email;
}

string Adresat::pobierzAdres() {
    return this -> adres;
}

