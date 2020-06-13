#include "work.h"

int mainCycle (char *name){
    Log *this;
    this = readFile(name);
    if(!this){
        printf("error\n");
        return 3;
    }
    
};

void iterator(Log *this){
    int f = 0;
    while(1){
        f++;
        printf("%d\n",f);
        if(this->pre){
            this = this->pre;

        }else{
            printf("end\n");
            break;
        };
    };
};

Log *readFile(char *fileName){
    FILE *in;
    Log *pre, *this;
    in = fopen(fileName, "r");
    if(!in){
        printf("file not found!\n");
        return 2;
    };
    this = NULL;
    char st[strBuf];
    while(!feof(in)){
        if(this != NULL){
            pre = this;
            this = (Log*)malloc(sizeof(Log));
            pre->next = this;
            this->pre = pre;
        }else{
            printf("first\n");
            this = (Log*)malloc(sizeof(Log));
            this->pre = NULL;
        }
        fgets(st,strBuf,in);
        this = createNode(st,this);
    }
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
    this->next = NULL;
    return this;
};

void test(){
    FILE *in = fopen("access.log","r");
    char st[strBuf];
    char sep[]=" []\"";
    fgets(st,strBuf,in);
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