#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"


struct LinkedListNode * _get_new_node(int aValue)
{
    struct LinkedListNode *res;
    res = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    res->value = aValue;
    res->pNext = NULL;
    return res;
}

//------------------------------------------------------------------------------
void db_init(LinkedList *apList)
{
    apList->pHead = NULL;
    apList->size  = 0;
}
//------------------------------------------------------------------------------
void db_free(LinkedList *apList)
{
    struct LinkedListNode *next = apList->pHead;
    struct LinkedListNode *tmp;
    while(next)
    {
        tmp = next->pNext;
        free(next);
        next = tmp;
    }
    apList->pHead = NULL;
    apList->size  = 0;
}
//------------------------------------------------------------------------------
int db_is_empty(LinkedList *apList)
{
    return (apList->pHead == NULL);
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_insert_at_end(LinkedList *apList, int aValue)
{
    struct LinkedListNode *next = apList->pHead;
    if (next == NULL)
    {
        apList->pHead = _get_new_node(aValue);
        apList->size++;
        return apList->pHead;
    }

    while(next->pNext)
        next = next->pNext;

    next->pNext = _get_new_node(aValue);
    apList->size++;
    return next->pNext;
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_insert_at_begin(LinkedList *apList, int aValue)
{
    if (apList->pHead == NULL)
        return db_insert_at_end(apList, aValue);

    struct LinkedListNode *tmp;
    struct LinkedListNode *new_element;

    tmp = apList->pHead;

    new_element          = _get_new_node(aValue);
    apList->pHead        = new_element;
    apList->pHead->pNext = tmp;
    apList->size++;
    return new_element;
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_insert_by_index(LinkedList *apList, unsigned aIndex, int aValue)
{
    if (aIndex >= apList->size)
        return NULL;

    unsigned i = 0;
    struct LinkedListNode *next = apList->pHead;
    struct LinkedListNode *tmp;
    struct LinkedListNode *new_element;

    while(i++ < aIndex)
        next = next->pNext;

    new_element        = _get_new_node(aValue);
    tmp                = next->pNext;
    next->pNext        = new_element;
    new_element->pNext = tmp;
    apList->size++;
    return new_element;
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_insert_by_pointer(LinkedList *apList, struct LinkedListNode *apNode, int aValue)
{
    unsigned i = 0;
    struct LinkedListNode *current;
    struct LinkedListNode *next;
    struct LinkedListNode *new_element;

    new_element         = _get_new_node(aValue);
    current             = apNode;
    next                = apNode->pNext;
    new_element->pNext  = next;
    current->pNext      = new_element;
    apList->size++;
    return new_element;
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_remove_first(LinkedList *apList)
{
    if (apList->pHead == NULL)
        return NULL;

    struct LinkedListNode *tmp;
    tmp = apList->pHead->pNext;
    free(apList->pHead);
    apList->pHead = tmp;
    apList->size--;
    return apList->pHead;
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_remove_last(LinkedList *apList)
{
    if (apList->pHead == NULL)
        return NULL;

    struct LinkedListNode *last;
    struct LinkedListNode *prev;

    last = apList->pHead;
    prev = last;
    while (last->pNext)
    {
        prev = last;
        last = last->pNext;
    }

    free(last);
    prev->pNext = NULL;
    apList->size--;

    if (apList->size == 0)
        apList->pHead = NULL;

    return NULL;
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_remove_by_index(LinkedList *apList, unsigned aIndex)
{
    if (aIndex >= apList->size)
        return NULL;

    if (aIndex == 0)
        return db_remove_first(apList);

    if (aIndex == (apList->size - 1))
        return db_remove_last(apList);

    unsigned i = 0;
    struct LinkedListNode *current;
    struct LinkedListNode *prev;

    current = apList->pHead;
    prev    = current;
    while (i++ < aIndex)
    {
        prev    = current;
        current = current->pNext;
    }

    prev->pNext = current->pNext;
    free(current);
    apList->size--;
    return prev->pNext;
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_remove_by_pointer(LinkedList *apList, struct LinkedListNode *apNode)
{
    if (apNode == NULL || apList->size == 0)
        return NULL;

    unsigned i = 0;
    struct LinkedListNode *next = apList->pHead;

    while (next != apNode)
    {
        next = next->pNext;
        ++i;
    }

    return db_remove_by_index(apList, i);
}
//------------------------------------------------------------------------------
struct LinkedListNode * db_find(LinkedList *apList, int aValue)
{
    struct LinkedListNode *cur = apList->pHead;

    unsigned i = 0;
    while (cur)
    {
        if (cur->value == aValue)
            return cur;
        cur = cur->pNext;
        ++i;
    }
    return NULL;
}
//------------------------------------------------------------------------------
struct LinkedListNode *db_first(LinkedList *apList)
{
    return apList->pHead;
}
//------------------------------------------------------------------------------
struct LinkedListNode *db_last(LinkedList *apList)
{
    struct LinkedListNode *next = apList->pHead;
    while (next->pNext)
        next = next->pNext;
    return next;
}
//------------------------------------------------------------------------------
struct LinkedListNode *db_next(struct LinkedListNode *apNode)
{
    if (apNode == NULL)
        return NULL;
    
    if (apNode->pNext != NULL)
        return apNode->pNext;
    return NULL;
}
//------------------------------------------------------------------------------
void db_sort(LinkedList *apList)
{
    struct LinkedListNode *i;
    struct LinkedListNode *j;

    i = apList->pHead;
    while (i)
    {
        for (j = i->pNext; j && i->value <= j->value; j = j->pNext)
            ;

        if (j != NULL)
        {
            int tmp;
            tmp = j->value;
            j->value = i->value;
            i->value = tmp;
        }
        else
            i = i->pNext;
    }
}
//------------------------------------------------------------------------------
void db_sort_custom(LinkedList *apList, db_pfsort apfSort)
{
    struct LinkedListNode *i;
    struct LinkedListNode *j;

    i = apList->pHead;
    while (i)
    {
        for (j = i->pNext; j && apfSort(i->value, j->value); j = j->pNext)
            ;

        if (j != NULL)
        {
            int tmp;
            tmp = j->value;
            j->value = i->value;
            i->value = tmp;
        }
        else
            i = i->pNext;
    }
}

//------------------------------------------------------------------------------

void db_print(LinkedList *apList)
{
    struct LinkedListNode *next = apList->pHead;
    while(next)
    {
        printf("%i ", next->value);
        next = next->pNext;
    }
    printf("\n");
}

int main(){

    LinkedList list;
    db_init(&list);
    db_insert_at_end(&list, 8);
    db_print(&list);

}