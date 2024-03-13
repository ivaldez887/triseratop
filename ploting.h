//
// Created by fer on 1/10/24.
//

#ifndef TRISERATOP_PLOTING_H
#define TRISERATOP_PLOTING_H

#include <plplot/plplot.h>
#include <sys/stat.h>
#include "utils.h"

int getname(char *name, char *num, int cuantos);

void doplot(VECTS listvects[], int v);

void ploting(LISMYNU *lismynu, VECTS *vects, char *num, int muchos);

#endif //TRISERATOP_PLOTING_H
