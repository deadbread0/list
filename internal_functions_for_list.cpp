#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "internal_functions_for_list.h"

void InitList(list_t* list)
{
    assert(list != nullptr);

    int* data = (int*)calloc(INITIAL_SIZE, sizeof(int));///////
    CheckNewMemory(data);
    list->data = data;

    int* next = (int*)calloc(INITIAL_SIZE, sizeof(int));///////
    CheckNewMemory(next);

    next[0] = 1;
    for (int i = 1; i < INITIAL_SIZE; i++)
        next[i] = 0;

    list->next = next;

    int* prev = (int*)calloc(INITIAL_SIZE, sizeof(int));////////realloc
    CheckNewMemory(prev);

    for (int i = 1; i < INITIAL_SIZE; i++)
        prev[i] = 0;

    list->prev = prev;

    list->free = 1;
    list->capacity = INITIAL_SIZE;
    list->size = 1;
}

void FillList(list_t* list)
{
    assert(list != nullptr);
    int size = list->size;

    for (int i = 1; i < list->capacity; i++)
    {
        list->next[i] = i + 1;
    }

    for (int i = 1; i < size - 1; i++)
    {
        
        list->prev[i] = i - 1;
    }

    list->next[size - 1] = 0;
    list->prev[size - 1] = size - 2;
    list->free = size;
}

void DestroyList(list_t* list)
{
    assert(list != nullptr);

    free(list->next);
    free(list->data);
    free(list->prev);
}

void AddMemory(list_t* list)
{
    assert(list != nullptr);
    int capacity = list->capacity;
    
    if (list->size >= capacity - 1)
    {
        int* new_data = (int*)realloc(list->data, (2 * capacity) * sizeof(int));
        CheckNewMemory(new_data);
        list->data = new_data;

        int* new_next = (int*)realloc(list->next, (2 * capacity) * sizeof(int));
        CheckNewMemory(new_next);
        list->next = new_next;

        int* new_prev = (int*)realloc(list->prev, (2 * capacity) * sizeof(int));
        CheckNewMemory(new_prev);
        list->prev = new_prev;

        list->capacity = 2 * capacity;
    }
}
