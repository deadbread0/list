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

    OutputForCheck(&list, filee);
    // EnterElementAfterIndex(&list, 1112, 8);
    // OutputForCheck(&list, filee);
    DeleteNextElement(&list, 7);
    OutputForCheck(&list, filee);
    //system("dot -Tpng -O dump.txt");
    DestroyList(&list);

    return 0;
}



