#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    for(int i = 0; i < 20; i++){
    usleep(300000);
        for(int j = 0; j < 25; j++){
            printf("%d ", rand()%10);
        }
    printf("\n");
    }
return 0;
}