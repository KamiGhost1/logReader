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
    char http[10];
    char code[4];
    char length[10];
    struct Log *pre, *next;
}Log;

Log *readFile(char *fileName);
Log *createNode(char *str, Log *this);
void test();
void checkNode(Log *el);