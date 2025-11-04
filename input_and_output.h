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

void InputFromFile(const char* filee_name, list_t* list);
void OutputForCheck(list_t* list, FILE*);
void CheckFile(const char* filee_name);
