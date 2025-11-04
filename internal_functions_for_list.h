const int INITIAL_SIZE = 100;
const int MAX_SIZE_OF_STR = 10;

struct list_t {
    int* data;
    int* next;
    int* prev;
    int free;
    int size;
    int capacity;
};

void InitList(list_t* list);
void FillList(list_t* list);
void DestroyList(list_t* list);
void CheckNewMemory(int* memory);
void AddMemory(list_t* list);