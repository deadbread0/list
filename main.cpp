#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

#include "main.h"

int main(const int argc, const char* argv[])
{
    list_t list = {};
    InitList(&list);
    FILE* filee = fopen("dump.txt", "w");

    const char* filee_name = argc > 0? argv[1]: "";
    CheckFile(filee_name);
    InputFromFile(filee_name, &list);
    FillList(&list);
    int fun_counter = 0;

    OutputForCheck(&list, filee, fun_counter);
    DeleteNextElement(&list, 5, &fun_counter, filee);
    // EnterElementAfterIndex(&list, 1112, 3, &fun_counter, filee);
    DeleteNextElement(&list, 5, &fun_counter, filee);
    Outputhtml(fun_counter);
    DestroyList(&list);

    return 0;
}



