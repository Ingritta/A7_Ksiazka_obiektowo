#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Contact.h"
#include "FileWithContacts.h"

using namespace std;

class ContactManager {
    const int LOGGED_USER_ID;
    vector <Contact> contacts;
    FileWithContacts fileWithContacts;
    int amountOfContacts;
    string dataOfContactSeparatedByPipes;

    Contact giveDataOfNewContact();
    void printDataOfContact(Contact adresat);
    void setNumberOfContacts(int newNumberOfContacts);
    char selectOptionFromEditMenu();

public:
    ContactManager(string nameOfFileWithContacts, int loggedUserId) : LOGGED_USER_ID(loggedUserId), fileWithContacts(nameOfFileWithContacts)  {
        loggedUserId = 0;
        contacts = fileWithContacts.readContactsOfLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addContact();
    void readContactsOfLoggedUserFromFile();
    bool checkIfContactsAreWritten();
    char selectOptionFromUserMenu();
    int getContactId();
    void printAllContacts();
    void searchContactByName();
    void searchContactBySurname();
    void printNumberOfFoundContacts();
    void removeContact();
    void changeDetailsOfContact();
};

#endif
