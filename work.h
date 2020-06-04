#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stringSize 1024


typedef struct{
    char ip[15];
    char day[2];
    char month[3];
    char year[4];
    char hour[2];
    char minut[2];
    char second[2];
    char msg[stringSize];
    char code[3];
    char length[10];
    struct Log *pre, *next;
}Log;