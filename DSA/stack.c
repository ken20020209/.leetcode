#include "../header/leetcode.h"
typedef struct
{
    int top;
    int size;
    int *data;
}MyStack;
int stack_init(MyStack *stack)
{
    if(stack==NULL)return 0;
    stack->top=-1;
    return 1;
}
void stack_realloc(MyStack *stack,int size)
{
    stack->size=size;
    stack->data =(int*)realloc(stack->data,size*sizeof(int));
}
void stack_free(MyStack *stack)
{
    free(stack->data);
    free(stack);
}
int stack_is_empty(MyStack *stack)
{
    if(stack->top==-1)return 1;
    return 0;
}
int stack_push(MyStack *stack, int value)
{
    stack->top++;
    if (stack->top==stack->size)
    {
        stack_realloc(stack, (stack->size)*2);
    } 
    stack->data[stack->top] = value;
    return 1;
}
int stack_pop(MyStack *stack)
{
    if (stack_is_empty(stack))return -1;
    stack->top--;
    return stack->data[stack->top+1];
}
MyStack *stack_create(int size)
{ 
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    if (stack==NULL)return NULL;
    stack->size=size;
    stack->top=-1;
    stack->data=(int *)malloc(sizeof(int) * stack->size);
    return stack;
}

int stack_get(MyStack *stack)
{
    if (stack_is_empty(stack))return -1;
    return stack->data[stack->top];
}
//test_stack

// int main(int argc,char **argv)
// {
//     MyStack *stack=stack_create(10);
//     if (stack==NULL)
//     {
//         printf("stack init failed\n");
//     }
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,99);
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,33);
//     stack_push(stack,888);
//     stack_init(stack);
//     int temp=stack_pop(stack);
//     printf("stack %d",temp);
//     free(stack);
//     return 0;
// }

