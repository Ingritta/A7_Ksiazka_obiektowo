#include <iostream>

#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook addressBook ("Users.txt", "Contacts.txt");

    char choice;

    while (true) {
        if (addressBook.checkIfUserIsLogged()) {

            choice = addressBook.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                addressBook.userRegistration();
                break;
            case '2':
                addressBook.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            choice = addressBook.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                addressBook.addContact();
                break;
            case '2':
                addressBook.searchContactByName();
                break;
            case '3':
                addressBook.searchContactBySurname();
                break;
            case '4':
                addressBook.printAllContacts();
                break;
            case '5':
                addressBook.removeContact();
                break;
            case '6':
                addressBook.changeDetailsOfContact();
                break;
            case '7':
                addressBook.changePasswordOfLoggedUser();
                break;
            case '8':
                addressBook.userLogout();
                break;
            }
        }
    }
    return 0;
}


