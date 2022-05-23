#include <stdlib.h>
#include <stdio.h>

typedef struct DataBaseList{

    int index; 
    char *Value; // Let it be 10 chars

    struct DataBaseList *next;
} list;

list *create_node(int set_index, char *set_value){

    list *node = (list *)malloc(sizeof(list));

    node -> index = set_index;
    node -> Value = set_value;
    node -> next = NULL;
    
    return node;
}

void database_insert(list **db, int set_index, char *set_value){

//Insert at the end

    list *new_element = create_node(set_index, set_value);

    new_element -> next = *db;
    *db = new_element;
}

void database_read(list *db, int id){

    int counter = 0; //This counter uses for printing Error in case there was no matching index
    while(db != NULL){
        if((db -> index) == id){
            printf("%s\n", db -> Value);
        }
    db = db -> next;
    }
    if(counter == 0) puts ("NoSuchIndexException");
}
int main(){

    list *db = create_node(0, "Bob");
    database_insert(&db, -1, "Anton");
    database_insert(&db, 1, "Aaaaa");
    database_insert(&db, -1, "Atttt");
    database_read(db, 2);

    while (db != NULL){
        printf("index is %d, value is %s.\n", db -> index, db -> Value);
        db = db -> next;
    }

    return 0;
}