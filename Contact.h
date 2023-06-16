#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

using namespace std;

class Contact {
    int id;
    int userId;
    string name;
    string surname;
    string phoneNumber;
    string email;
    string address;

public:
    Contact (int id = 0, int userId = 0, string name = "", string surname = "", string phoneNumber = "", string email = "", string address = "") {
        this -> id = id;
        this -> userId = userId;
        this -> name = name;
        this -> surname = surname;
        this -> phoneNumber = phoneNumber;
        this -> email = email;
        this -> address = address;
    }

    int getId();
    int getUserId();
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getEmail();
    string getPassword();
    string getAddress();
    void setId(int newId);
    void setLoggedUserId(int newLoggedUserId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setAddress(string newAddress);
};

#endif
