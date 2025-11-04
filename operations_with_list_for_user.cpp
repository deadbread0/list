#include <stdio.h>
#include "operations_with_list_for_user.h"

void EnterElementAfterIndex(list_t* list, int element, int position)
{
    list->size++;
    AddMemory(list);

    list->next[list->free] = list->next[position];
    list->next[position] = list->free;
    list->data[list->free] = element;
    list->prev[list->next[position]] = position; 
    list->prev[list->next[list->next[position]]] = list->free;

    list->free++;
}

void DeleteNextElement(list_t* list, int index)
{
        list->prev[list->next[index]] = 0;
        list->prev[list->next[list->next[index]]] = index;
        int prm_for_delete_next_index = list->next[list->next[index]];
        list->next[list->next[index]] = 0;
        list->next[index] = prm_for_delete_next_index;
}