/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */
#include "header\leetcode.h"
// @lc code=start
#define status int
typedef struct
{
    int top;
    int size;
    int *data;
}MyStack;
void stack_realloc(MyStack *stack,int size)
{
    stack->size=size;
    stack->data =(int*)realloc(stack->data,size*sizeof(int));
}

status stack_init(MyStack *stack)
{
    if(stack==NULL)return 0;
    stack->top=-1;
    return 1;
}
void stack_free(MyStack *stack)
{
    free(stack->data);
    free(stack);
}
status stack_push(MyStack *stack, int value)
{
    stack->top++;
    if (stack->top==stack->size)
    {
        stack_realloc(stack, (stack->size)*2);
    } 
    stack->data[stack->top] = value;
    return 1;
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
status stack_is_empty(MyStack *stack)
{
    if(stack->top==-1)return 1;
    return 0;
}
int stack_pop(MyStack *stack)
{
    if (stack_is_empty(stack))return -1;
    stack->top--;
    return stack->data[stack->top+1];
}
int stack_get(MyStack *stack)
{
    if (stack_is_empty(stack))return -1;
    return stack->data[stack->top];
}




bool isValid(char * s)
{
    int map[256];
    map['(']=1;
    map[')']=1;
    map['{']=2;
    map['}']=2;
    map['[']=3;
    map[']']=3;
    int flag=true;
    int len=strlen(s);
    MyStack *stack=stack_create(10);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]== '{')stack_push(stack,map[s[i]]);
        else 
        {
            if(stack_pop(stack)!=map[s[i]])
            {
                flag=false;
                break;
            }
        }
    }
    if (stack_is_empty(stack)==0)flag=false;
    free(stack);
    return flag;
}
// @lc code=end

