#include <stdio.h>
#include <assert.h>

#include "verification.h"

void CheckFile(const char* filee_name)
{
    if (filee_name == nullptr)
    {
        printf("file %s didn't open\n", filee_name);
        exit(1);
    }
}

void CheckNewMemory(int* memory)
{
    if (memory == nullptr)
    {
        printf("Memory allocation memory\n");
        exit(1);
    }
}