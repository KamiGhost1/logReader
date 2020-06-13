#include "work.h"

int main(int C, char **V){
    if (C==1){
        printf("hello, u in log reader for apache\n");
        printf("for more information use key -h or --help\n\n");
        printf("by kamiGhost1 github.com:kamighost1/logReader\n");
        return 0;
    };
    if (C==3){
        int mode = atoi(V[2]);
        if (mode > 4){
            printf("Sorry, max 4.\n");
            exit(10);
        }
        mainCycle(V[1], mode);
        return 0;
    };
}