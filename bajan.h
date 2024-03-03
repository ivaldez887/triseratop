//
// Created by fer on 1/9/24.
//

#ifndef TRISERATOP_BAJAN_H
#define TRISERATOP_BAJAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct MemoryStruct
{
    char* memory;
    size_t size;
};

int getfile(char* inititems);

int bajarch(struct MemoryStruct *chunk, char* bufi);

#endif //TRISERATOP_BAJAN_H
