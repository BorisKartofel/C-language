#include <stdlib.h>
#include <stdio.h>

//Declaration of the LinkedList structure
typedef struct DataBaseList{

    int index; 
    char *Value; // Let it be 10 chars

    struct DataBaseList *next;
} list;

//Creates an element (node) of LinkedList
list *create_node(int set_index, char *set_value){

    list *node = (list *)malloc(sizeof(list));

    node -> index = set_index;
    node -> Value = set_value;
    node -> next = NULL;
    
    return node;
}

//Inserts forward
void insert_fwd(list **db, int set_index, char *set_value){

    list *new_element = create_node(set_index, set_value);

    new_element -> next = *db;
    *db = new_element;
}

//Inserts backwards
void insert_bkwd(list **db, int set_index, char *set_value){

    list *new_element = create_node(set_index, set_value);

    list *temp = *db;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = new_element;
}

//Finds and prints Values of LinkedList elements by their index
void database_read(list *db, int id){

    int counter = 0; //This counter uses for printing Error in case there was no matching index

    while((db != NULL) && (db -> index <= id)){
        if((db -> index) == id){
            printf("%s\n", db -> Value);
        }
    db = db -> next;
    }

    if(counter == 0) puts ("NoSuchIndexException");
}

int main(){

    list *db = create_node(0, "Name");

    insert_fwd(&db, -1, "Anton");
    insert_fwd(&db, 1, "Aaaaa");
    insert_fwd(&db, -1, "Atttt");

    insert_bkwd(&db, 2, "Fjjjj");
    insert_bkwd(&db, 2, "Foooo");
    insert_bkwd(&db, 0, "Frrrr");

    database_read(db, 2);

    while (db != NULL){
        printf("index is %d, value is %s.\n", db -> index, db -> Value);
        db = db -> next;
    }

    return 0;
}