#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stringSize 1024
#define strBuf 2048


typedef struct{
    char ip[15];
    char date[26];
    char type[6];
    char url[1024];
    char http[8];
    int code;
    int length;
    struct Log *pre, *next;
}Log;

Log *readFile(FILE *input);
