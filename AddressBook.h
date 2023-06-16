#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "ContactManager.h"
#include "User.h"
#include "TextFile.h"

using namespace std;

class AddressBook {
    UserManager userManager;
    ContactManager *contactManager;
    const string NAME_OF_FILE_WITH_CONTACTS;

public:
    AddressBook(string nameOfFileWithUsers, string nameOfFileWithContacts) :  userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_CONTACTS(nameOfFileWithContacts) {
        contactManager = NULL;
    };
    ~AddressBook() {
        delete contactManager;
        contactManager = NULL;
    };
    void userRegistration();
    void readUsersFromFile();
    void changePasswordOfLoggedUser();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void addContact();
    void readContactsOfLoggedUserFromFile();
    void printAllContacts();
    bool checkIfUserIsLogged();
    bool checkIfContactsAreWritten();
    void userLogout();
    int getLoggedUserId();
    void userLogin();
    void showAllUsers();
    void searchContactByName();
    void searchContactBySurname();
    void removeContact();
    void changeDetailsOfContact();
};

#endif

