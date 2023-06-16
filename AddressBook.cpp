#include "AddressBook.h"

void AddressBook::userRegistration() {
    userManager.userRegistration();
}

void AddressBook::showAllUsers() {
    userManager.showAllUsers();
}

void AddressBook::userLogin() {
    userManager.userLogin();
    if (userManager.checkIfUserIsLogged () == false) {
        contactManager = new ContactManager(NAME_OF_FILE_WITH_CONTACTS, userManager.getLoggedUserId());
    }
}

void AddressBook::changePasswordOfLoggedUser() {
    userManager.changePasswordOfLoggedUser();
}

void AddressBook::userLogout() {
    userManager.userLogout();
    delete contactManager;
    contactManager = NULL;
}

void AddressBook::addContact() {
    contactManager -> addContact();
}

char AddressBook::selectOptionFromMainMenu() {
    return userManager.selectOptionFromMainMenu();
}

char AddressBook::selectOptionFromUserMenu() {
    return contactManager -> selectOptionFromUserMenu();
}

void AddressBook::printAllContacts() {
    contactManager -> printAllContacts();
}

bool AddressBook::checkIfContactsAreWritten() {
    return contactManager -> checkIfContactsAreWritten();
}

bool AddressBook::checkIfUserIsLogged () {
    return userManager.checkIfUserIsLogged ();
}

void AddressBook::searchContactByName() {
    contactManager -> searchContactByName();
}

void AddressBook::searchContactBySurname() {
    contactManager -> searchContactBySurname();
}

void AddressBook::removeContact() {
    contactManager -> removeContact();
}

void AddressBook::changeDetailsOfContact() {
    contactManager -> changeDetailsOfContact();
}
