//
// Created by fer on 1/9/24.
//

#ifndef NDEBUG
#define FROM_FILE
#endif

#include "bajan.h"

int getfile(char *inititems) {
#ifdef FROM_FILE
    const char *fil = "../historic2024.html";
    FILE *fe = fopen(fil, "r");
    if (fe == NULL) {
        perror("failed to open historic2024.html:\n");
        return EXIT_FAILURE;
    }

    char data[180000];
    size_t count = 179000;
    fread(data, sizeof(char), count, fe);
    fclose(fe);
    memcpy(inititems, data, 179000);
#else
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;
#ifdef __linux__
    char* myconfig="/home/fer/.config/.triseratopl";
#elifndef _UWIN
    char* myconfig="c:/Users/ibane/.myconfig/.triseratopl.txt";
#endif

    char bufi[250];
    FILE *fi= fopen(myconfig, "r");
    if(fi== NULL){
        fprintf(stderr,"No file named .triseratopl.txt\n");
        exit(0);
    }
    fgets(bufi,249,fi);
    fclose(fi);
    printf("%s", bufi);
#ifdef __linux__
    char *bufinew = malloc( strlen( bufi ? bufi : "\n" ) );
    if( bufi )
        strcpy( bufinew, bufi );
    bufinew[strlen(bufinew)-1]='\0';
    free(bufinew);
    bajarch(&chunk, bufinew);
#elifndef _UWIN
    bajarch(&chunk, bufi);
#endif
    memcpy(inititems, chunk.memory, chunk.size);

    free(chunk.memory);
#endif
}

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("not enough memory(realloc returned null\n");
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

int bajarch(struct MemoryStruct *chunk, char *bufi) {
    CURL *curl_handle;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, bufi);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, chunk);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    res = curl_easy_perform(curl_handle);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easyperform() failed %s\n", curl_easy_strerror(res));
    } else {

    }
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    return EXIT_SUCCESS;
}