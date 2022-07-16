#define EXTENDSIZE 2
typedef struct
{
    int capacity;
    int size;
    void **data;
} Vector;
Vector *vector_create(int size)
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (void **)malloc(sizeof(void *) * size);
    v->size = 0;
    v->capacity = size;
    return v;
}
void vector_extend(Vector *v)
{
    v->capacity *= EXTENDSIZE;
    v->data = (void **)realloc(v->data, v->capacity * sizeof(void *));
}
void vecotr_add(Vector *v, void *data)
{
    if (v->size == v->capacity)
        vector_extend(v);
    v->data[v->size++] = data;
}
int main()
{
    Vector *v = vector_create(2);
    for (int i = 0; i < 100; i++)
    {
        vecotr_add(v, (void *)i);
    }
    return 0;
}