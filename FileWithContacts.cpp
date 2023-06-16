#include "FileWithContacts.h"
#include "SupportiveMethods.h"
#include "ContactManager.h"

void FileWithContacts::addContactToFile (Contact contact) {
    fstream textFile;
    string lineWithContactData = "";

    textFile.open(NAME_OF_FILE.c_str(), ios::out | ios::app);

    if (textFile.good()) {
        lineWithContactData = convertContactDataToLinesWithDataSeparatedByPipes(contact);

        if (TextFile::checkIfFileIsEmpty()) {
            textFile << lineWithContactData;
        } else {
            textFile << endl << lineWithContactData;
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    textFile.close();
    idOfLastContact++;
}

int FileWithContacts::getContactIdFromDataSeparatedByPipes(string dataOfSingleContactSeparatedByPipes) {
    int beginOfContactIdPosition = 0;
    int contactId = SupportiveMethods::convertStringToInt(SupportiveMethods::getNumber(dataOfSingleContactSeparatedByPipes, beginOfContactIdPosition));

    return contactId;
}

Contact FileWithContacts::getDataOfContact(string dataOfContactSeparatedByPipes) {
    string singleDataOfContact = "";
    int numberOfsingleDataOfContact = 1;
    Contact contact;

    for (size_t signPosition = 0; signPosition < dataOfContactSeparatedByPipes.length(); signPosition++) {
        if (dataOfContactSeparatedByPipes[signPosition] != '|') {
            singleDataOfContact += dataOfContactSeparatedByPipes[signPosition];
        } else {
            switch(numberOfsingleDataOfContact) {
            case 1:
                contact.setId(atoi(singleDataOfContact.c_str()));
                break;
            case 2:
                contact.setLoggedUserId(atoi(singleDataOfContact.c_str()));
                break;
            case 3:
                contact.setName(singleDataOfContact);
                break;
            case 4:
                contact.setSurname(singleDataOfContact);
                break;
            case 5:
                contact.setPhoneNumber(singleDataOfContact);
                break;
            case 6:
                contact.setEmail(singleDataOfContact);
                break;
            case 7:
                contact.setAddress(singleDataOfContact);
                break;
            }
            singleDataOfContact = "";
            numberOfsingleDataOfContact++;
        }
    }
    return contact;
}

int FileWithContacts::getUserIdFromDataSeparatedByPipes(string dataOfSingleContactSeparatedByPipes) {
    int beginOfUserIdPosition = dataOfSingleContactSeparatedByPipes.find_first_of('|') + 1;
    int loggedUserId = SupportiveMethods::convertStringToInt(SupportiveMethods::getNumber(dataOfSingleContactSeparatedByPipes, beginOfUserIdPosition));

    return loggedUserId;
}

string FileWithContacts::convertContactDataToLinesWithDataSeparatedByPipes(Contact contact) {
    string lineWithContactData = "";

    lineWithContactData += SupportiveMethods::convertIntToString(contact.getId()) + '|';
    lineWithContactData += SupportiveMethods::convertIntToString(contact.getUserId()) + '|';
    lineWithContactData += contact.getName() + '|';
    lineWithContactData += contact.getSurname() + '|';
    lineWithContactData += contact.getPhoneNumber() + '|';
    lineWithContactData += contact.getEmail() + '|';
    lineWithContactData += contact.getAddress() + '|';

    return lineWithContactData;
}

int FileWithContacts::getLastContactId() {
    return idOfLastContact;
}

void FileWithContacts::removeContactFromFile(int IdOfRemovingContact) {
    int numerOfLineInTextFile = 1, numerOfRemovingLine = 0;
    string dataOfSingleContactSeparatedByPipes = "", lineWithContactData = "";
    fstream addressBook, temporaryAddressBook;

    addressBook.open(NAME_OF_FILE.c_str(), ios::in);
    temporaryAddressBook.open("TemporaryAddressBook.txt", ios::out | ios::app);

    if (addressBook.good() && temporaryAddressBook.good() && IdOfRemovingContact != 0) {

        while(getline(addressBook, dataOfSingleContactSeparatedByPipes)) {
            if(IdOfRemovingContact == getContactIdFromDataSeparatedByPipes(dataOfSingleContactSeparatedByPipes)) {
                numerOfRemovingLine = numerOfLineInTextFile;
            } else if (numerOfLineInTextFile == numerOfRemovingLine) {}
            else if (numerOfLineInTextFile == 1 && numerOfLineInTextFile != numerOfRemovingLine) {
                temporaryAddressBook << dataOfSingleContactSeparatedByPipes;
            } else if (numerOfLineInTextFile == 2 && numerOfRemovingLine == 1) {
                temporaryAddressBook << dataOfSingleContactSeparatedByPipes;
            } else if (numerOfLineInTextFile > 2 && numerOfRemovingLine == 1) {
                temporaryAddressBook << "\n" << dataOfSingleContactSeparatedByPipes;
            } else if (numerOfLineInTextFile > 1 && numerOfRemovingLine != 1) {
                temporaryAddressBook << "\n" << dataOfSingleContactSeparatedByPipes;
            }
            numerOfLineInTextFile++;
        }
        temporaryAddressBook.close();
        addressBook.close();
        temporaryAddressBook.close();
        remove("Contacts.txt");
        rename("TemporaryAddressBook.txt", "Contacts.txt");

    } else {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    }
}

void FileWithContacts::editChoosenLineInFile(string lineWithContactData, int IdOfEditingContact) {
    fstream addressBook, temporaryAddressBook;
    string dataOfContactSeparatedByPipes = "", loadedLine  = "";
    int numberOfloadedLine  = 1;

    addressBook.open(NAME_OF_FILE.c_str(), ios::in);
    temporaryAddressBook.open("TemporaryAddressBook.txt", ios::out | ios::app);

    if (addressBook.good() && temporaryAddressBook.good() && IdOfEditingContact != 0) {

        while(getline(addressBook, loadedLine )) {

            if(IdOfEditingContact == getContactIdFromDataSeparatedByPipes(loadedLine )) {
                if (numberOfloadedLine  == 1) {
                    temporaryAddressBook << lineWithContactData;

                } else if (numberOfloadedLine  > 1) {
                    temporaryAddressBook << "\n" << lineWithContactData;
                }
            } else {
                if (numberOfloadedLine  == 1) {
                    temporaryAddressBook << loadedLine ;

                } else if (numberOfloadedLine  > 1) {
                    temporaryAddressBook << "\n" << loadedLine ;
                }
            }
            numberOfloadedLine ++;
        }
        addressBook.close();
        temporaryAddressBook.close();
        remove("Contacts.txt");
        rename("TemporaryAddressBook.txt", "Contacts.txt");

    } else {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    }
}

vector <Contact>  FileWithContacts::readContactsOfLoggedUserFromFile(int loggedUserId) {
    Contact contact;

    vector <Contact> contacts;
    string dataOfSingleContactSeparatedByPipes = "";
    string dataOfLastContactInFile = "";
    fstream textFile;

    textFile.open(NAME_OF_FILE.c_str(), ios::out |ios::app);
    textFile.close();

    textFile.open(NAME_OF_FILE.c_str(), ios::in);

    if (textFile.good()) {
        while (getline(textFile, dataOfSingleContactSeparatedByPipes)) {
            if(loggedUserId == getUserIdFromDataSeparatedByPipes(dataOfSingleContactSeparatedByPipes)) {
                contact = getDataOfContact(dataOfSingleContactSeparatedByPipes);
                contacts.push_back(contact);
            }
        }
        dataOfLastContactInFile = dataOfSingleContactSeparatedByPipes;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    textFile.close();

    if (dataOfLastContactInFile != "") {
        idOfLastContact = getContactIdFromDataSeparatedByPipes(dataOfLastContactInFile);
    }
    return contacts;
}
