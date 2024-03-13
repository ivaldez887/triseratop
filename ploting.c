//
// Created by fer on 1/10/24.
//

#include "ploting.h"

int getname(char *name, char *num, int cuantos) {
    time_t s, val = 1;
    struct tm *current;
    s = time(NULL);
    current = localtime(&s);
    int hour = current->tm_hour;
    int min = current->tm_min;

    if (cuantos != 0) {
        char mydir[100];

#ifdef _WIN64
        sprintf(mydir, "%s_%d-%d-%d-V_%d/", "c:/Users/ibane/Documents/myfiles/plots/", current->tm_year + 1900,
                current->tm_mon + 1, current->tm_mday, cuantos);
#endif
#ifdef __linux__
        sprintf(mydir, "%s_%d-%d-%d-V_%d/", "/home/fer/Documents/myfiles/plots/", current->tm_year + 1900,
                current->tm_mon + 1, current->tm_mday, cuantos);
#endif
#ifdef _WIN64  /* use in windows */
        mkdir(mydir);
#endif /* _WIN64 or _MINGW64 */
#ifdef __linux__
        mkdir(mydir, 0777);
#endif
        sprintf(name, "%s_%d-%d-%d-N_%s_.png", mydir, current->tm_year + 1900, current->tm_mon + 1, current->tm_mday,
                num);
    } else {
#ifdef _WIN64
        sprintf(name, "%s_%d-%d-%d-N_%s_.png", "c:/Users/ibane/Documents/myfiles/plots/", current->tm_year + 1900,
                current->tm_mon + 1, current->tm_mday, num);
#endif
#ifdef __linux__
        sprintf(name, "%s_%d-%d-%d-N_%s_.png", "/home/fer/Documents/myfiles/plots/", current->tm_year + 1900,
                current->tm_mon + 1, current->tm_mday, num);
#endif
    }
}

void ploting(LISMYNU *lismynu, VECTS *vects, char *num, int muchos) {
    PLFLT x[12];
    PLFLT y[20];

    PLCHAR_VECTOR device = "png";
    plsdev(device);

    char myname[100];
    if (muchos == 1) {
        getname(myname, num, lismynu->count);
    } else {
        getname(myname, num, 0);
    }
    plsfnam((PLCHAR_VECTOR) myname);
    plsori(0);
    plinit();
    plcol0(1);
    PLFLT xmin = 1., xmax = 12, ymin = 0., ymax = 8.;
    plenv(xmin, xmax, ymin, ymax, 1, 2);
    plcol0(4);
    char mesano[12];

    strcat(strcpy(mesano, "mes - "), lismynu->mynu[0].fecha + 6);
    pllab(mesano, "FREC", num);

    plwidth(3);
    plcol0(2);
    plline(12, vects->mes, vects->frec);

    plschr(0, 0.7);
    double prcnt = 1.;
    plcol0(3);
    for (int k = 0; k < lismynu->count; k++) {
        char fecnum[15] = {'\0'};
        strncpy(fecnum, lismynu->mynu[k].fecha, 5);
        strcat(strcat(fecnum, " "), lismynu->mynu[k].mynum);
        plmtex("lv", 0.0, prcnt, 0.0, fecnum);
        prcnt = prcnt - 0.05;

    }
    plend();

}

void doplot(VECTS listvects[], int veces) {

}
