#include "Contact.h"

void Contact::setId(int newId) {
    if (newId >= 0) {
        this -> id = newId;
    }
}

void Contact::setLoggedUserId(int LOGGED_USER_ID) {
    if (userId >= 0) {
        this -> userId = LOGGED_USER_ID;
    }
}

void Contact::setName(string newName) {
    this -> name = newName;
}

void Contact::setSurname(string newSurname) {
    this -> surname = newSurname;
}

void Contact::setPhoneNumber(string newPhoneNumber) {
    this -> phoneNumber = newPhoneNumber;
}

void Contact::setEmail(string newEmail) {
    this -> email = newEmail;
}

void Contact::setAddress(string newAddress) {
    this -> address = newAddress;
}

int Contact::getId() {
    return this -> id;
}

int Contact::getUserId() {
    return this -> userId;
}

string Contact::getName() {
    return this -> name;
}

string Contact::getSurname() {
    return this -> surname;
}

string Contact::getPhoneNumber() {
    return this -> phoneNumber;
}

string Contact::getEmail() {
    return this -> email;
}

string Contact::getAddress() {
    return this -> address;
}

