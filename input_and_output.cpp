#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "input_and_output.h"

void InputFromFile(const char* filee_name, list_t* list)
{
    assert(filee_name != nullptr);
    assert(list != nullptr);

    FILE* filee = fopen(filee_name, "r");
    int num = 0;
    char ch = 0; 

    while (ch != EOF)
    {
        ch = fgetc(filee);
        if (isdigit(ch))
        {
            num = (int)ch - '0';
            while (isdigit(ch = fgetc(filee)))
                num = num * 10 + (int)ch - '0';
        }
        list->data[list->size] = num;
        list->size++;
    }
    //list->size = i;
    list->prev[0] = list->size - 1;
}


void OutputForCheck(list_t* list, FILE* filee)
{
    assert(list != nullptr);
    assert(filee != nullptr);

    int size = list->size;

    fprintf(filee, "digraph {\n");
    fprintf(filee, "%d [shape=Mrecord; style = filled; fillcolor = \"#c0f2f2ff\"; color = \"#4682B4\"; label = \"{<f1> prev %d }|{ index %d }| {<f0> next %d} | value %d | free %d\"];\n", 0, list->prev[0], 0, list->next[0], list->data[0], list->free);

    int k = 0;
    for (int i = 1; i < list->size; i++)
    {
        fprintf(filee, "%d [shape=Mrecord; style = filled; fillcolor = \"#c0f2f2ff\"; color = \"#4682B4\"; label = \"{<f1> prev %d }|{ index %d }| {<f0> next %d} | value %d | free %d\"];\n", i, list->prev[i], i, list->next[i], list->data[i], list->free);
    }

    fprintf(filee, "rankdir = \"LR\"\n");
    fprintf(filee, "edge[weight=100, color = white];\n");
    int last = 0;
    for (int i = 1; i < list->size; i++)
    {
        fprintf(filee, "%d -> ", i);
        last = i;
    }
    fprintf(filee, "%d\n",last);

    fprintf(filee, "edge[weight=0, color = green];\n");
    // fprintf(filee, "%d: <f0> -> ", 0);

    for (int i = 0; list->next[i] != 0; i = list->next[i])//стрелки next
    {
        fprintf(filee, "%d: <f0> -> ", i);
        last = i;
    }
    fprintf(filee, "%d\n", list->next[last]);

    fprintf(filee, "edge[weight=1, color = red];\n");
    //fprintf(filee, "%d: <f1> -> %d: <f1> -> ", 0, list->prev[1]);

    for (int i = list->prev[0]; list->prev[i] != 0; i = list->prev[i])//стрелки prev
    {
        fprintf(filee, "%d: <f1> -> ", i);
        last = i;
    }
    fprintf(filee, "%d\n", list->prev[last]);

    fprintf(filee, "}\n");
    // sprintf
}



