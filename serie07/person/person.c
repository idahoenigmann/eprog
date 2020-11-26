//
// Created by ida on 26.11.20.
//

#include "person.h"

Person* newPerson(char* firstname, char* surname, Address* address, Date* birthday) {
    Person* person = malloc(sizeof(Person));

    person->firstname = malloc(sizeof(char) * strlen(firstname));
    person->surname = malloc(sizeof(char) * strlen(surname));
    person->address = malloc(sizeof(Address));
    person->birthday = malloc(sizeof(Date));

    setFirstname(person, firstname);
    setSurname(person, surname);
    setAddress(person, address);
    setBirthday(person, birthday);

    return person;
}

Person* delPerson(Person* person) {
    free(person->firstname);
    free(person->surname);
    person->address = delAddress(person->address);
    person->birthday = delDate(person->birthday);

    free(person);
    return NULL;
}

void setFirstname(Person* person, char* firstname) {
    person->firstname = realloc(person, sizeof(char) * strlen(firstname));

    person->firstname = strcpy(person->firstname, firstname);
}

void setSurname(Person* person, char* surname) {
    person->surname = realloc(person, sizeof(char) * strlen(surname));

    person->surname = strcpy(person->surname, surname);
}

void setAddress(Person* person, Address* address) {
    person->address = address;
}

void setBirthday(Person* person, Date* birthday) {
    person->birthday->day = birthday->day;
    person->birthday->month = birthday->month;
    person->birthday->year = birthday->year;
}

char* getFirstname(Person* person){
    char* res;
    res = malloc(sizeof(char) * strlen(person->firstname));
    strcpy(res, person->firstname);
    return res;
}

char* getSurname(Person* person) {
    return person->surname;
}

Address* getAddress(Person* person) {
    return person->address;
}

Date* getBirthday(Person* person) {
    return person->birthday;
}

Person* whoIsOlder(Person* a, Person* b);