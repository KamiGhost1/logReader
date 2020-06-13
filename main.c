#include "work.h"

int main(int C, char **V){
    if (C==1){
        printf("hello, u in log reader for apache\n");
        printf("for more information use key -h or --help\n\n");
        printf("by kamiGhost1 github.com:kamighost1/logReader\n");
        return 0;
    };
    if (C==3){
        mainCycle(V[1],V[2]);
        return 0;
    };
}