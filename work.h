#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stringSize 1024
#define strBuf 2048


typedef struct{
    char ip[16];
    char date[26];
    char type[6];
    char url[1024];
    char http[10];
    char code[4];
    char length[10];
    struct Log *pre, *next;
}Log;


typedef struct{
    char day[3];
    char month[4];
    char year[5];
    char hour[3];
    char minute[3];
}Date;

Log *readFile(char *fileName);
Log *createNode(char *str, Log *this);
int mainCycle (char *name, int mode);
int ipIterator(Log *this, int mode);
Date *dateParser(Log *this);
char *dateReturn(Date *time, int mode);
int iterator(Log *this);
void checkNode(Log *el);