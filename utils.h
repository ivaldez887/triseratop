//
// Created by fer on 1/9/24.
//

#ifndef TRISERATOP_UTILS_H
#define TRISERATOP_UTILS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>



typedef struct DIARIO{
    char fecha[11];
    char mdia[6];
    char delas3[6];
    char extra[6];
    char delas7[6];
    char classic[6];
}DIARIO;

typedef struct LOSITEMS{
    int step;
    int interv;
    int nitems;
    int start;
    struct DIARIO lositems[];
}LOSITEMS;

typedef struct  MYNUM{
    int sorteo;
    char mynum[6];
    char fecha[11];
}MYNUM;

typedef struct LISMYNU{
    int count;
    MYNUM mynu[];
}LISMYNU;

typedef struct VECTS{
    int count;
    char num[4];
    double mes[12];
    double frec[12];
}VECTS;

void getlistitems(LOSITEMS *lositemes, char *inititems);

size_t cuantoson(char *inicuenta);

void getlismynu(LOSITEMS* lositemes, LISMYNU *lismynu, char *mynum);

void getmyvectors(LISMYNU *lismynu, VECTS *vects);

void sortelnum(char *arr);

#endif //TRISERATOP_UTILS_H
