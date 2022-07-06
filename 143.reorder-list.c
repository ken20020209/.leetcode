/*
 * @lc app=leetcode id=143 lang=c
 *
 * [143] Reorder List
 */
#include "header\leetcode.h"
struct ListNode
{
    int val;
    struct ListNode *next;
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode *head)
{

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    // find midle node
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // reveser half after midle
    struct ListNode *midleNode = slow;
    struct ListNode *preNode = NULL;
    struct ListNode *curNode = slow->next;
    struct ListNode *nextNode = curNode;
    while (curNode != NULL)
    {
        nextNode = nextNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
    curNode = preNode;
    midleNode->next = NULL;
    // while (curNode != NULL)
    // {
    //     printf("%d\n", curNode->val);
    //     curNode = curNode->next;
    // }
    
    // merge two link list
    struct ListNode *firstpart = head;
    struct ListNode *prefirstpart = head;

    struct ListNode *secondPart = curNode;
    struct ListNode *presecondPart = curNode;

    while (firstpart != NULL && secondPart != NULL)
    {
        // printf("test\n");
        firstpart = firstpart->next;
        secondPart = secondPart->next;

        prefirstpart->next = presecondPart;
        presecondPart->next = firstpart;

        prefirstpart = firstpart;
        presecondPart = secondPart;
    }
}
// @lc code=end
