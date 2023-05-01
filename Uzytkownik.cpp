#include "Uzytkownik.h"

void Uzytkownik::ustawId(int noweId) {
    if (noweId >= 0)
        id = noweId;
}

void Uzytkownik::ustawLogin(string nowyLogin) {
    login = nowyLogin;
}

void Uzytkownik::ustawHaslo(string noweHaslo) {
    haslo = noweHaslo;
}

int Uzytkownik::pobierzId() {
    cout << "ID Uzytkownika w Uzytkownik::pobierzId :" << id << endl;
    system ("pause");
    return id;
}

string Uzytkownik::pobierzLogin() {
    return login;
}

string Uzytkownik::pobierzHaslo() {
    return haslo;
}
