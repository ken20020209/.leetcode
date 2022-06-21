/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

  struct ListNode 
  {
      int val;
      struct ListNode *next;
 };
 #include "header/leetcode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{

   struct ListNode *i=l1,*j=l2,*p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->next=NULL;
    struct ListNode *result=p;
    int a,b,sum,carry=0;
    while(i||j){
        a=i?i->val:0;
        b=j?j->val:0;
        sum=a+b+carry;
        carry=sum/10;
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->next=NULL;
        p->val=sum%10;
        if(i)
        i=i->next;
        if(j)
        j=j->next;
    }
    if(carry){
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=1;
        p->next=NULL;
    }
    return result->next;

}


// @lc code=end

