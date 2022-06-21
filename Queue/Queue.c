#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "/home/anton/HomeworkC/LinkedList/LinkedList.h"
#include "/home/anton/HomeworkC/LinkedList/LinkedList.c"

//  В половине случаев выводит ошибку:
//  malloc(): unaligned tcache chunk detected
//  Aborted (core dumped)


int main()
{
    LinkedList List;
    db_init(&List);
    
    printf ("%d\n", db_get_size(&List));

    srand(time(NULL));

    for(int j = 0; j < 50; ++j)
    {
        if(rand()%2 == 0) db_insert_at_begin(&List, rand(), "Human");
        if(rand()%2 == 0 && db_get_size(&List) > 0) db_remove_last(&List);
    }

    printf ("%d\n", db_get_size(&List));
}