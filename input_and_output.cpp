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
    list->prev[0] = list->size - 1;
}


void OutputForCheck(list_t* list, FILE* filee, int counter)
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

    for (int i = 0; list->next[i] != 0; i = list->next[i])//стрелки next
    {
        fprintf(filee, "%d: <f0> -> ", i);
        last = i;
    }
    fprintf(filee, "%d\n", list->next[last]);

    fprintf(filee, "edge[weight=1, color = red];\n");

    for (int i = list->prev[0]; list->prev[i] != 0; i = list->prev[i])//стрелки prev
    {
        fprintf(filee, "%d: <f1> -> ", i);
        last = i;
    }
    fprintf(filee, "%d\n", list->prev[last]);

    fprintf(filee, "}\n");
}

void Outputhtml(int fun_counter)
{
    FILE* filee_html = fopen("HTML_FILE.htm", "w");////

    fprintf(filee_html, 
            "<!DOCTYPE html>\n"
            "<html lang=\"en\">\n"
            "<head>\n"
            "\t<meta charset=\"UTF-8\">\n"
            "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
            "\t<title>Struct of data: list</title>\n"
            "\t<style>\n"
            "\timg {\n"
            "\t\tmax-width: 100%%;\n"
            "\t\theight: auto;\n"
            "\t\tdisplay: block;\n"
            "\t}\n"
            "\t</style>\n"
            "</head>\n"
            "<body>\n"
            "\t<h1>Debug page</h1>\n");

    fprintf(filee_html, "\t\t<p>dump call: %d</p>\n", 1);
    fprintf(filee_html, "\t\t<img src=\"dump.txt.png\" alt=\"graph%d\" class=\"img\">\n", 1);
    for (int i = 2; i <= fun_counter + 1; i++)
    {
        fprintf(filee_html, "\t\t<p>dump call: %d</p>\n", i);
        fprintf(filee_html, "\t\t<img src=\"dump.txt.%d.png\" alt=\"graph%d\" class=\"img\">\n", i, i);
    }

    fprintf(filee_html, "</body>\n</html>\n");
    fclose(filee_html);
}



