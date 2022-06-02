List of all funcions you can interact with:

db_init(LinkedList *);
db_free(LinkedList *);
db_is_empty(LinkedList *);
db_insert_at_end(LinkedList *, int);
db_insert_at_begin(LinkedList *, int);
db_insert_by_index(LinkedList *, unsigned, int);
db_insert_by_pointer(LinkedList *,  LinkedListNode *, int);
db_remove_first(LinkedList *);
db_remove_last(LinkedList *);
db_remove_by_index(LinkedList *, unsigned);
db_remove_by_pointer(LinkedList *,  LinkedListNode *);
db_find(LinkedList *, int);
db_first(LinkedList *);
db_last(LinkedList *);
db_next( LinkedListNode *);
db_print(LinkedList *);
db_put_file(LinkedList *apList);
db_scan_file(LinkedList *apList);