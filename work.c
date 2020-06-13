#include "work.h"

int iterator(Log *this){
    int f = 0;
    while(1){
        if(this->pre > 0){
            this = this->pre;
            f++;
            printf("%d\n",f);
        }else{
            printf("end\n");
            break;
        }
    };
    return 0;
};

Log *readFile(char *fileName){
    FILE *in;
    Log *pre, *this;
    in = fopen(fileName, "r");
    if(!in){
        printf("file not found!\n");
        return 2;
    }
    char st[strBuf];
    while(!feof(in)){
        if(this){
            pre = this;
            this = (Log*)malloc(sizeof(Log));
            pre->next = this;
            this->pre = pre;
        }else{
            this = (Log*)malloc(sizeof(Log));
            this->pre = 0;
        }
        fgets(st,strBuf,in);
        this = createNode(st,this);
    }
    this->next = 0;
    // checkNode(this);
    return this;
};

Log *createNode(char *str, Log *this){
    char sep[]=" []\"\0";
    strcpy(this->ip,strtok(str,sep));
    strtok(NULL,sep);
    strtok(NULL,sep);
    strcpy(this->date,strtok(NULL,sep));
    strtok(NULL,sep);
    strcpy(this->type,strtok(NULL,sep));
    strcpy(this->url,strtok(NULL,sep));
    strcpy(this->http,strtok(NULL,sep));
    strcpy(this->code,strtok(NULL,sep));
    strcpy(this->length,strtok(NULL,sep));
    return this;
};

void test(){
    FILE *in = fopen("access.log","r");
    // fscanf(in,"%s - - [%s +0300] \"%s %s %s\" %d $d",ptr.ip, ptr.date,ptr.type,ptr.url,ptr.http,&ptr.code,&ptr.length);
    // fclose(in);
    // printf("%s %s %d\n", ptr.type, ptr.url, ptr.code);
    char st[strBuf];
    char sep[]=" []\"";
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
}

void checkNode(Log *el){
    printf("%s\n", el->ip);
    printf("%s\n", el->date);
    printf("%s\n", el->type);
    printf("%s\n", el->url);
    printf("%s\n", el->http);
    printf("%s\n", el->code);
    printf("%s\n", el->length);
}