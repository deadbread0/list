#include <stdio.h>
#include "operations_with_list_for_user.h"

void EnterElementAfterIndex(list_t* list, int element, int position, int* counter, FILE* filee)
{
    list->size++;
    AddMemory(list);

    list->next[list->free] = list->next[position];
    list->next[position] = list->free;
    list->data[list->free] = element;
    list->prev[list->next[position]] = position; 
    list->prev[list->next[list->next[position]]] = list->free;

    list->free = list->next[list->free];
    (*counter)++;
    OutputForCheck(list, filee, *counter);
    
}

void DeleteNextElement(list_t* list, int index, int* counter, FILE* filee)
{
        list->prev[list->next[index]] = 0;
        list->prev[list->next[list->next[index]]] = index;
        int prm_for_delete_next_index = list->next[list->next[index]];
        list->next[list->next[index]] = list->free > index + 1 ? list->free : list->next[list->free];
        list->free = list->free > index + 1 ? index + 1 : list->free;
        list->next[index] = prm_for_delete_next_index;
        (*counter)++;
        OutputForCheck(list, filee, *counter);
}