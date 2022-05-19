#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>

int main(){
    char matrix[30][30];

    for(int i = 0; i<100; i++){
        matrix_update();
        matrux_sout();
        usleep(300);
    }

    free(matrix);
    return 0;
}