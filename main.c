#include "work.h"

int main(int C, char **V){
    FILE *in = fopen("access.log","r");
    Log ptr;
    ptr.pre = NULL;
    ptr.next = NULL;
    fscanf(in,"%s - - [%s +0300] \"%s %s %s\" %d $d",ptr.ip, ptr.date,ptr.type,ptr.url,ptr.http,&ptr.code,&ptr.length);
    fclose(in);
    printf("%s %s %d\n", ptr.type, ptr.url, ptr.code);
    return 0;
}