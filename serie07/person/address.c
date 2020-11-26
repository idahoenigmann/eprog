//
// Created by ida on 26.11.20.
//

#include "address.h"


Address* newAddress(char* street, char* number, char* city, char* zip) {
    Address* address = malloc(sizeof(address));

    address->street = malloc(sizeof(char) * strlen(street));
    address->number = malloc(sizeof(char) * strlen(number));
    address->city = malloc(sizeof(char) * strlen(city));
    address->zip = malloc(sizeof(char) * strlen(zip));

    setStreet(address, street);
    setNumber(address, number);
    setCity(address, city);
    setZip(address, zip);

    return address;
}

Address* delAddress(Address* address) {
    free(address->street);
    free(address->number);
    free(address->city);
    free(address->zip);

    free(address);
    return NULL;
}

void setStreet(Address* address, char* street) {
    address->street = realloc(address->street, sizeof(char) * strlen(street));
    strcpy(address->street, street);
}

void setNumber(Address* address, char* number) {
    address->number = realloc(address->number, sizeof(char) * strlen(number));
    strcpy(address->number, number);
}

void setCity(Address* address, char* city) {
    address->city = realloc(address->city, sizeof(char) * strlen(city));
    strcpy(address->city, city);
}

void setZip(Address* address, char* zip) {
    address->zip = realloc(address->zip, sizeof(char) * strlen(zip));
    strcpy(address->zip, zip);
}


char* getStreet(Address* address) {
    return address->street;
}

char* getNumber(Address* address) {
    return address->number;
}

char* getCity(Address* address) {
    return address->city;
}

char* getZip(Address* address) {
    return address->zip;
}