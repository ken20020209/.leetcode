/*
    #define MAX(a,b) (((a)>(b))?(a):(b))
    #define MIN(a,b) (((a)<(b))?(a):(b))
*/
//#define abs(a) (((a)<0)?-(a):(a))
#define true 1
#define false 0
#define bool int
#define status int

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

//#include "readtestcase.h"
//#include "stack.h"
//#include "dequeue.h"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct ListNode
{
    int val;
    struct ListNode *next;
}