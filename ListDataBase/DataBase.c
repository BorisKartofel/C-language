#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//Variable that keeps the size of LinkedList
int list_size = 0;


//Declaration of the LinkedList structure
typedef struct LinkedList{

    char *Value; // Let it be 6 chars

    struct LinkedList *next;
} list;     


//Creates an element (node) of LinkedList
list *create_node(char *set_value){

    list *node = (list *)malloc(sizeof(list));

    node -> Value = set_value;
    node -> next = NULL;
    
    list_size++;

    printf("Узелков у нас %d\n", list_size);
    return node;
}


//Inserts forwards
void insert_fwd(list **db, char *set_value){

    list *new_element = create_node(set_value);

    new_element -> next = *db;
    *db = new_element;
}


//Inserts backwards
void insert_bkwd(list **db, char *set_value){

    list *new_element = create_node(set_value);
    list *temp = *db;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = new_element;
}


//Inserts node in the middle of LinkedList
void insert_mdl(list **db, int id, char *set_value){

    //Inner variable for while cycle
    int i = 0;
    //Inner checkout
    bool is_alone = true;

    list *temp = *db;
    
    while (temp -> next != NULL && i <= id  &&  is_alone){

        if (i == id - 1){

            is_alone = false;
            list *new_element = create_node(set_value);
            new_element -> next = temp -> next;
            temp -> next = new_element;
        }

        i++;
        temp = temp -> next;
    }
}
/*
//Finds and prints Values of LinkedList elements by their index
void database_read(list **db, int id){

    //This counter uses for printing Error in case there was no matching index.
    //Counter is true if there is such index in list
    bool counter = false;

    for(int i = 0; (db != NULL) && (i <= id); i++){

        if(i == id) {

            printf("%s\n", db -> Value);
            db = db -> next;
            counter = true;
        }
    }

    if(counter) puts ("NoSuchIndexException");
}


void database_delete(list **db, int id){

    int counter = 0;

    while (db != NULL  &&  counter < id){
        

        db = db -> next;
        counter++;
    }
}
*/

void database_insert(list *db, int id, char *set_value){

    if(db == NULL){
        puts("ListNotCreatedException");
    }

    else if(id <= 0){
        insert_fwd(&db, set_value);
    }

    else if(id >= list_size){
        insert_bkwd(&db, set_value);
    }

    else insert_mdl(&db, id, set_value);
}


int main(){

    list *db = create_node("Name");

    insert_bkwd(&db, "Fjjjj");
    insert_bkwd(&db, "Frrrr");
    insert_fwd(&db, "Aaaaa");
    insert_fwd(&db, "Atttt");
    database_insert(db, -400000, "FRWRDS");
    insert_mdl(&db, 4, "MIDDLE");
    insert_mdl(&db, 1, "MIDDLE");
    database_insert(db, -400000, "FRWRDS");
    insert_fwd(&db, "FRONT");
    insert_fwd(&db, "FRONT");
    insert_fwd(&db, "FRONT");
    insert_bkwd(&db, "BACK");
    database_insert(db, -400000, "FRWRDS");
    insert_bkwd(&db, "BACK");
    insert_bkwd(&db, "BACK");

    database_insert(db, -3, "FRWRDS");  //ПО КАКОЙ-ТО ПРИЧИНЕ ВСТАВКА В НАЧАЛО СПИСКА НЕ РАБОТАЕТ. В ФУНКЦИЮ ЗАХОДИТ, УЗЕЛ СОЗДАЕТСЯ, НО ПОЛУЧИТЬ ЕГО Я НЕ МОГУ!!!
    database_insert(db, -400000, "FRWRDS");
    database_insert(db, 642052, "BCWDS");
    database_insert(db, -400000, "FRWRDS");
    database_insert(db, 2, "MIDDLE");
    database_insert(db, -400000, "FRWRDS");

    
    while (db != NULL){
        printf("Value is %s.\n", db -> Value);
        db = db -> next;
    }

    return 0;
}