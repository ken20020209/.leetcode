typedef struct
{
    int front;
    int back;
    int capacity;
    int *data;
}MyDequeue;
int dequeue_init(MyDequeue *dequeue);
void dequeue_realloc(MyDequeue *dequeue,int size);
void dequeue_free(MyDequeue *dequeue);
int dequeue_size(MyDequeue *dequeue);
int dequeue_is_empty(MyDequeue *dequeue);
int dequeue_push_front(MyDequeue *dequeue, int value);
int dequeue_push_back(MyDequeue *dequeue, int value);
int dequeue_pop_front(MyDequeue *dequeue);
int dequeue_pop_back(MyDequeue *dequeue);
MyDequeue *dequeue_create(int size);
int dequeue_get_back(MyDequeue *dequeue);
int dequeue_get_front(MyDequeue *dequeue);
