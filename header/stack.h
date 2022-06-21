typedef struct
{
    int top;
    int size;
    int *data;
}MyStack;
int stack_init(MyStack *stack);
void stack_realloc(MyStack *stack,int size);
void stack_free(MyStack *stack);
int stack_is_empty(MyStack *stack);
int stack_push(MyStack *stack, int value);
int stack_pop(MyStack *stack);
MyStack *stack_create(int size);
int stack_get(MyStack *stack);