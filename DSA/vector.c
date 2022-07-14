typedef struct
{
    int capacity;
    int size;
    void **data;
} MyVector;
MyVector *vector_create(int size)
{
    MyVector *v = (MyVector *)malloc(sizeof(MyVector));
    v->data = (void **)malloc(sizeof(void *) * size);
    v->size = 0;
    v->capacity = size;
    return v;
}
