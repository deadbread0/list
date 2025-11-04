struct list_t {
    int* data;
    int* next;
    int* prev;
    int free;
    int size;
    int capacity;
};

void CheckFile(const char* filee_name);
void CheckNewMemory(int* memory);