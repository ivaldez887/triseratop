#include "bajan.h"
#include "utils.h"
#include "ploting.h"

#define clrscr() printf("\e[1;1H\e[2J")

#define N 30

static int selecting() {
    char c = 'q';
    int r = 0;
    while (1) {
        clrscr();
        printf("\n\n menu:\n");
        printf(" a.- Un numero de 3 digitos\n ");
        printf("     enter 'a';\n");
        printf(" b.- nums todos n veces en el año\n");
        printf("     enter 'b':\n");
        printf(" q.- enter q for exit\n");

        c = tolower(fgetc(stdin));
        if (c == 'a') {
            return 0;
        } else if (c == 'b') {
            return 1;
        } else if (c == 'q') {
            return 3;
        } else {
            clrscr();
            printf("\n\n\nPlease enter 'a', 'b', or 'q'\n");
        }
    }
    return r;
}

int main(int argc, char *argv[]) {
    char lisaux[1000][4];
    for (int i = 0; i < 999; i++) {
        strncpy(lisaux[i], "", 3);
    }
    int veces = 0;
    char mynumero[4];
    mynumero[3] = '\0';

    char *inititems = malloc(sizeof(char) * 150000);
    getfile(inititems);
    inititems = strstr(inititems, "<tbody>");
    int nitems = cuantoson(inititems);
    LOSITEMS *lositemes = malloc(sizeof(DIARIO) * nitems + sizeof(int) * 4);
    lositemes->nitems = nitems;
    getlistitems(lositemes, inititems);

    int r = selecting();
    int flagi=0;
    do {
        int nveces;
        char myneum[4];
        clrscr();
        if (r == 0) {
            printf("\n\n your especifico number 3 digitos\n");
            scanf("%s", myneum);

            sortelnum(myneum);
            LISMYNU *lismynu;
            lismynu = (LISMYNU *) malloc(sizeof(MYNUM) * 30 + sizeof(int));
            VECTS *vects = (VECTS *) malloc(sizeof(double) * 24 + sizeof(int) + sizeof(char) * 5);
            for (int k = 0; k < 12; k++) {
                vects->mes[k] = k + 1;
                vects->frec[k] = 0;
            }
            strcpy(vects->num, myneum);
            mynumero[3] = '\0';
            getlismynu(lositemes, lismynu, myneum);

            getmyvectors(lismynu, vects);

            ploting(lismynu, vects, myneum, 0);

            char nameview0[100];
            getname(nameview0, myneum, 0);
            char mycomand0[50];
            strcpy(mycomand0, "eog -f ");
            strcat(mycomand0, nameview0);
            system(mycomand0);

            free(lismynu);
            free(vects);

        } else if (r == 1) {
            printf("\n\nplease enter n: donde n = cuantas veces a\n");
            printf(" resultado con n veces en año\n");
            scanf("%i", &nveces);

            for (int i = 0; i < 1000; i++) {
                if (i < 10) {
                    mynumero[0] = '0';
                    mynumero[1] = '0';
                    sprintf(&mynumero[2], "%d", i);
                } else if (i < 100) {
                    mynumero[0] = '0';
                    sprintf(&mynumero[1], "%d", i);
                } else {
                    sprintf(mynumero, "%d", i);
                }
                sortelnum(mynumero);
                LISMYNU *lismynu;
                lismynu = (LISMYNU *) malloc(sizeof(MYNUM) * 30 + sizeof(int));

                VECTS *vects = (VECTS *) malloc(sizeof(double) * 24 + sizeof(int) + sizeof(char) * 5);
                for (int k = 0; k < 12; k++) {
                    vects->mes[k] = k + 1;
                    vects->frec[k] = 0;
                }
                vects->count = nveces;
                strcpy(vects->num, mynumero);

                mynumero[3] = '\0';
                getlismynu(lositemes, lismynu, mynumero);

                getmyvectors(lismynu, vects);

                int flag = 0;
                if (lismynu->count == nveces) {
                    for (int k = 0; k < 999; k++) {
                        if (!strcmp(mynumero, lisaux[k])) {
                            free(lismynu);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        strcpy(lisaux[i], mynumero);
                        veces += 1;

                        ploting(lismynu, vects, mynumero, 1);
                        if(flagi==0){
                            char nameview1[100];
                            getname(nameview1, mynumero, lismynu->count);
                            char mycomand1[50];
                            strcpy(mycomand1, "eog -f ");
                            strcat(mycomand1, nameview1);
                            system(mycomand1);
                            flagi=1;
                        }

                        free(lismynu);
                    }
                } else {
                    free(lismynu);
                }
                free(vects);
            }
        } else if (r == 3) {
            free(lositemes);
            exit(0);
        }
    } while ((r = selecting()) != 3);

    printf("\n ___listo___\n");

    return EXIT_SUCCESS;
}
