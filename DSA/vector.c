typedef struct
{
    int capacity;
    int size;
    int *data;
}MyVector;
MyVector* vector_create(int size)
{
    MyVector* v= (MyVector *)malloc(sizeof(MyVector));
    v->data= (int*)malloc(sizeof(int)*size);
    v->size=0;
    v->capacity=size;
    return v;
}
