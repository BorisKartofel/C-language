#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H



struct LinkedListNode
{
    struct LinkedListNode *pNext;
    int                value;
};

typedef struct
{
    struct LinkedListNode *pHead;
    unsigned           size;
}LinkedList;

typedef int(*db_pfsort)(int, int);

/*
void   db_init(LinkedList *);
void   db_free(LinkedList *);
int    db_is_empty(LinkedList *);
struct LinkedListNode *db_insert_at_end(LinkedList *, int);
struct LinkedListNode *db_insert_at_begin(LinkedList *, int);
struct LinkedListNode *db_insert_by_index(LinkedList *, unsigned, int);
struct LinkedListNode *db_insert_by_pointer(LinkedList *, struct LinkedListNode *, int);
struct LinkedListNode *db_remove_first(LinkedList *);
struct LinkedListNode *db_remove_last(LinkedList *);
struct LinkedListNode *db_remove_by_index(LinkedList *, unsigned);
struct LinkedListNode *db_remove_by_pointer(LinkedList *, struct LinkedListNode *);
struct LinkedListNode *db_find(LinkedList *, int);
struct LinkedListNode *db_first(LinkedList *);
struct LinkedListNode *db_last(LinkedList *);
struct LinkedListNode *db_next(struct LinkedListNode *);
void   db_print(LinkedList *);
*/


/*
+---------+
|  pHead  | = NULL
+---------+
|  pList  | = NULL
+---------+
|  size   | = 0
+---------+
*/
void db_init(LinkedList *);

/*
while !NULL
    next = current->next
    free(current)
    next = current
*/
void db_free(LinkedList *);

int db_is_empty(LinkedList *);

/*
                              +---------+
                              |  value  |
                              +---------+
                              |         |
                              +---------+
+---------+    +---------+
|  value  |    |  value  |
+---------+ .->+---------+
|  pNext  |-.  |   NULL  |
+---------+    +---------+
after append
                               +---------+
                               |  value  |
                            .->+---------+
                            |  |   NULL  |
                            |  +---------+
+---------+    +---------+  |
|  value  |    |  value  |  |
+---------+ .->+---------+  |
|  pNext  |-.  |   pNext |--.
+---------+    +---------+
*/
struct LinkedListNode * db_insert_at_end(LinkedList *, int);

/*
                 +---------+
                 |  value  |
                 +---------+
                 |         |
                 +---------+
+---------+      +---------+      +---------+
|  value  |      |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
|  pNext  |--.   |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+
after insert (insert after index or pointer)
                 +---------+
                 |  value  |
            .--->+---------+
            |    |  pNext  |--.
            |    +---------+  |
            |                 |
            |  .--------------.
+---------+ |  |  +---------+      +---------+
|  value  | |  |  |  value  |      |  value  |
+---------+ |  .->+---------+  .-->+---------+
|  pNext  |-.     |  pNext  |--.   |   NULL  |
+---------+       +---------+      +---------+
*/
struct LinkedListNode * db_insert_at_begin(LinkedList *, int);
struct LinkedListNode * db_insert_by_index(LinkedList *, unsigned, int);
struct LinkedListNode * db_insert_by_pointer(LinkedList *, struct LinkedListNode *, int);

/*
+---------+      +---------+      +---------+
|  value  |      |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
|  pNext  |--.   |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+
after remove
free(first)
pHead = -----.
             |
+---------+  |   +---------+      +---------+
| REMOVED |  |   |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
| REMOVED |      |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+
*/
struct LinkedListNode * db_remove_first(LinkedList *);

/*
+---------+      +---------+      +---------+
|  value  |      |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
|  pNext  |--.   |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+
after remove
free(last)
+---------+     +---------+    +---------+
|  value  |     |  value  |    | REMOVED |
+---------+  .->+---------+    +---------+
|  pNext  |--.  |   NULL  |    | REMOVED |
+---------+     +---------+    +---------+
*/
struct LinkedListNode * db_remove_last(LinkedList *);

/*
+---------+      +---------+      +---------+
|  value  |      |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
|  pNext  |--.   |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+
after remove (remove by index or pointer)
             .---------------.
+---------+  |  +---------+  |  +---------+
|  value  |  |  | REMOVED |  |  |  value  |
+---------+  |  +---------+  .->+---------+
|  pNext  |--.  | REMOVED |     |   NULL  |
+---------+     +---------+     +---------+
*/
struct LinkedListNode * db_remove_by_index(LinkedList *, unsigned);
struct LinkedListNode * db_remove_by_pointer(LinkedList *, struct LinkedListNode *);

struct LinkedListNode * db_find(LinkedList *, int);

struct LinkedListNode *db_first(LinkedList *);
struct LinkedListNode *db_last(LinkedList *);
struct LinkedListNode *db_next(struct LinkedListNode *);

void db_sort(LinkedList *);
void db_sort_custom(LinkedList *, db_pfsort);

void db_print(LinkedList *);

#endif // SINGLE_LIST_H