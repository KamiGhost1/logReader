#include "work.h"

int main(int C, char **V){
    FILE *in = fopen("access.log","r");
    Log *ptr;
    

    // fscanf(in,"%s - - [%s +0300] \"%s %s %s\" %d $d",ptr.ip, ptr.date,ptr.type,ptr.url,ptr.http,&ptr.code,&ptr.length);
    // fclose(in);
    // printf("%s %s %d\n", ptr.type, ptr.url, ptr.code);
    char st[strBuf];
    char sep[]=" []-\"\0";
    fgets(st,strBuf,in);
    // printf("%s\n",sep);
    // printf("%s\n",strtok(st," "));
    // printf("%s\n",strtok(NULL," - - ["));
    // printf("%s\n",strtok(NULL," +0300]"));
    // printf("%s\n",strtok(NULL," "));
    // printf("%s\n",strtok(st,sep));
    printf("%s\n",strtok(st,sep));
    printf("%s\n",strtok(NULL,sep));
    printf("%s\n",strtok(NULL,sep));
    printf("%s\n",strtok(NULL,sep));
    printf("%s\n",strtok(NULL,sep));
    printf("%s\n",strtok(NULL,sep));
    printf("%s\n",strtok(NULL,sep));
    printf("%s\n",strtok(NULL,sep));
    // strcpy(ptr->ip,strtok(st,sep));
    // strtok(NULL,sep);
    // strtok(NULL,sep);
    // strcpy(ptr->date,strtok(NULL,sep));
    // strtok(NULL,sep);
    // strcpy(ptr->type,strtok(NULL,sep));
    // strcpy(ptr->url,strtok(NULL,sep));
    // strcpy(ptr->http,strtok(NULL,sep));
    // strcpy(ptr->code,strtok(NULL,sep));
    return 0;
}