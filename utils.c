//
// Created by fer on 1/9/24.
//

#include "utils.h"


static void addtovect(VECTS *vects, char *mes){
    int m= atoi(mes);
    switch (m) {
        case 1:
            vects->frec[0] +=1;
            break;
        case 2:
            vects->frec[1] +=1;
            break;
        case 3:
            vects->frec[2] +=1;
            break;
        case 4:
            vects->frec[3] +=1;
            break;
        case 5:
            vects->frec[4] +=1;
            break;
        case 6:
            vects->frec[5] +=1;
            break;
        case 7:
            vects->frec[6] +=1;
            break;
        case 8:
            vects->frec[7] +=1;
            break;
        case 9:
            vects->frec[8] +=1;
            break;
        case 10:
            vects->frec[9] +=1;
            break;
        case 11:
            vects->frec[10] +=1;
            break;
        case 12:
            vects->frec[11] +=1;
            break;

    }
}

void getmyvectors(LISMYNU *lismynu, VECTS *vects) {
    char mes[3];
    int count = lismynu->count;
    for(int l = 0; l<count; l++){
        strncpy(mes, lismynu->mynu[l].fecha + 3, 2);
        addtovect(vects, mes);
    }
}

void sortelnum(char *arr){
    int counter = 3;
    for(int i=0; i < counter; i++){
        for (int j=i;j <counter;j++){
            if(arr[i] > arr[j]){
                char arrtemp;
                arrtemp = arr[i];
                arr[i] = arr[j];
                arr[j] = arrtemp;
            }
        }
    }
}

void getlismynu(LOSITEMS *lositemes, LISMYNU *lismynu, char *mynum){
    char aux1[4];
    char aux2[4];
    strcpy(aux1, mynum);
    aux1[3] = '\0';
    sortelnum(aux1);
    lismynu->count =0;

    int nitems = lositemes->nitems;
    for(int i=0; i<nitems; i++){
        strcpy(aux2, lositemes->lositems[i].mdia +2);
        aux2[3] = '\0';
        sortelnum(aux2);
        if(!strcmp(aux1, aux2)){
            strcpy(lismynu->mynu[lismynu->count].mynum, lositemes->lositems[i].mdia);
            strcpy(lismynu->mynu[lismynu->count].fecha, lositemes->lositems[i].fecha);
            lismynu->mynu[lismynu->count].sorteo = 1;
            lismynu->count +=1;
        }
        strcpy(aux2, lositemes->lositems[i].delas3 +2);
        sortelnum(aux2);
        if(!strcmp(aux1, aux2)){
            strcpy(lismynu->mynu[lismynu->count].mynum, lositemes->lositems[i].delas3);
            strcpy(lismynu->mynu[lismynu->count].fecha, lositemes->lositems[i].fecha);
            lismynu->mynu[lismynu->count].sorteo = 3;
            lismynu->count +=1;
        }
        strcpy(aux2, lositemes->lositems[i].extra +2);
        sortelnum(aux2);
        if(!strcmp(aux1, aux2)){
            strcpy(lismynu->mynu[lismynu->count].mynum, lositemes->lositems[i].extra);
            strcpy(lismynu->mynu[lismynu->count].fecha, lositemes->lositems[i].fecha);
            lismynu->mynu[lismynu->count].sorteo = 5;
            lismynu->count +=1;
        }
        strcpy(aux2, lositemes->lositems[i].delas7 +2);
        sortelnum(aux2);
        if(!strcmp(aux1, aux2)){
            strcpy(lismynu->mynu[lismynu->count].mynum, lositemes->lositems[i].delas7);
            strcpy(lismynu->mynu[lismynu->count].fecha, lositemes->lositems[i].fecha);
            lismynu->mynu[lismynu->count].sorteo = 7;
            lismynu->count +=1;
        }
        strcpy(aux2, lositemes->lositems[i].classic +2);
        sortelnum(aux2);
        if(!strcmp(aux1, aux2)){
            strcpy(lismynu->mynu[lismynu->count].mynum, lositemes->lositems[i].classic);
            strcpy(lismynu->mynu[lismynu->count].fecha, lositemes->lositems[i].fecha);
            lismynu->mynu[lismynu->count].sorteo = 9;
            lismynu->count +=1;
        }
    }
}

size_t cuantoson(char* inicuenta){
    size_t nitems;
    int numi = 0;
    while ((inicuenta = strstr(inicuenta, "<td c")) != NULL){
        inicuenta +=1;
        numi +=1;
    }
    nitems = numi / 6;
    return nitems;
}

void getlistitems(LOSITEMS *lositemes, char *inititems){
    size_t nites = lositemes->nitems;

    for (size_t i = 0; i < nites; ++i){
        DIARIO item;
        inititems = strstr(inititems,"ter\">") +5;
        strncpy(item.fecha, inititems, 10);
        item.fecha[10] = '\0';

        inititems = strstr(inititems,"ter\">") +5;
        strncpy(item.mdia, inititems, 5);
        item.mdia[5] = '\0';

        inititems = strstr(inititems,"ter\">") +5;
        strncpy(item.delas3, inititems, 5);
        item.delas3[5] = '\0';

        inititems = strstr(inititems,"ter\">") +5;
        strncpy(item.extra, inititems, 5);
        item.extra[5] = '\0';

        inititems = strstr(inititems,"ter\">") +5;
        strncpy(item.delas7, inititems, 5);
        item.delas7[5] = '\0';

        inititems = strstr(inititems,"ter\">") +5;
        strncpy(item.classic, inititems, 5);
        item.classic[5] = '\0';

        lositemes->lositems[i] = (DIARIO)item;
    }
}






