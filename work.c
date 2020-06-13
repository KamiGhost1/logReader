#include "work.h"

int mainCycle (char *name, int mode){
    Log *this;
    this = readFile(name);
    if(!this){
        printf("error\n");
        return 3;
    }
    printf("%d\n",ipIterator(this,mode));
    return 0;
};

int ipIterator(Log *this,int mode){
    int f = 0;
    Date *time;
    char *def, *v;
    time = dateParser(this);
    def = dateReturn(time,mode);
    while(1){
        if(this){
            time = dateParser(this);
            v = dateReturn(time,mode);
            if(!strcmp(def,v)){
                f++;
                if(this->pre){
                    this=this->pre;
                }else{
                    break;
                }
            }else{
                break;
            }
        }else{
            break;
        };
    };
    return f;
};

char *dateReturn(Date *time, int mode){
    char *ptr;
    switch(mode){
        case 0:
            ptr = time->day;
            break;
        case 1:
            ptr =  time->month;
            break;
        case 2:
            ptr = time->year;
            break;
        case 3:
            ptr = time->hour;
            break;
        case 4:
            ptr = time->minute;
            break;
        default:
            return NULL;
    };
    return ptr;
};

Date *dateParser(Log *this){
    Log *node;
    Date *ptr;
    char sep[]="/:";
    node = (Log*)malloc(sizeof(Log));
    memcpy(node,this,sizeof(Log));
    ptr = (Date*)malloc(sizeof(Date));
    if(!ptr){
        printf("no RAM!\n");
        exit(1);
    }
    strcpy(ptr->day,strtok(node->date,sep));
    strcpy(ptr->month,strtok(NULL,sep));
    strcpy(ptr->year,strtok(NULL,sep));
    strcpy(ptr->hour,strtok(NULL,sep));
    strcpy(ptr->minute,strtok(NULL,sep));
    free(node);
    return ptr;
};

int iterator(Log *this){
    int f = 0;
    while(1){
        f++;
        if(this->pre){
            this = this->pre;
        }else{
            break;
        };
    };
    return f;
};

Log *readFile(char *fileName){
    FILE *in;
    Log *pre, *this;
    in = fopen(fileName, "r");
    if(!in){
        printf("file not found!\n");
        exit(2);
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
            this = (Log*)malloc(sizeof(Log));
            this->pre = NULL;
        }
        fgets(st,strBuf,in);
        this = createNode(st,this);
    }
    fclose(in);
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

void checkNode(Log *el){
    printf("%s\n", el->ip);
    printf("%s\n", el->date);
    printf("%s\n", el->type);
    printf("%s\n", el->url);
    printf("%s\n", el->http);
    printf("%s\n", el->code);
    printf("%s\n", el->length);
}