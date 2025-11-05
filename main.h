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
int InputFromFile(const char* filee_name, list_t* list);
void CheckFile(const char* filee_name);
void FillList(list_t* list);
void OutputForCheck(list_t* list, FILE* filee, int counter);
void DestroyList(list_t* list);
void EnterElementAfterIndex(list_t* list, int element, int position, int* counter, FILE* filee);
void DeleteNextElement(list_t* list, int index, int* counter, FILE* filee);
void Outputhtml(int fun_counter);