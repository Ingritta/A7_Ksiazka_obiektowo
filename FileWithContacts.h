#ifndef FILEWITHCONTACTS_H
#define FILEWITHCONTACTS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "Contact.h"
#include "SupportiveMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithContacts : public TextFile {
    int idOfLastContact;
    string dataOfSingleContactSeparatedByPipes;
    string dataOfContactSeparatedByPipes;

    int getUserIdFromDataSeparatedByPipes(string dataOfSingleContactSeparatedByPipes);
    int getContactIdFromDataSeparatedByPipes(string dataOfLastContactInFile);
    Contact getDataOfContact(string dataOfContactSeparatedByPipes);

public:
    FileWithContacts(string nameOfFile) : TextFile(nameOfFile) {
        idOfLastContact = 0;
    };
    int getLastContactId();
    vector <Contact> readContactsOfLoggedUserFromFile(int loggedUserId);
    void addContactToFile (Contact contact);
    void removeContactFromFile(int IdOfRemovingContact);
    void editChoosenLineInFile(string lineWithContactData, int IdOfEditingContact);
    string convertContactDataToLinesWithDataSeparatedByPipes(Contact contact);
};

#endif
