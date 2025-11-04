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

void EnterElementAfterIndex(list_t* list, int element, int position);
void DeleteNextElement(list_t* list, int index);
void AddMemory(list_t* list);