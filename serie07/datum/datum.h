//
// Created by ida on 24.11.20.
//

#ifndef EPROG_DATUM_H
#define EPROG_DATUM_H

struct _Date_ {
    int day;
    int month;
    int year;
} Date;

Date* newDate(int d, int m, int y);

Date* delDate(Date* date);


#endif //EPROG_DATUM_H
