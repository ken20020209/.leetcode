/*
 * @lc app=leetcode id=138 lang=c
 *
 * [138] Copy List with Random Pointer
 */
#include "header\leetcode.h"
struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};
// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node *copyRandomList(struct Node *head)
{
    // printf("%d\n", head->next->random);
    int NodeCapacity = 2;
    int NodeSize = -1;
    int map[40000] = {0};

    int cnt = 0;
    struct Node *node = head;
    while (node != NULL)
    {
        // printf("%d\n", cnt);
        map[(int)node / 4] = cnt;
        cnt++;
        node = node->next;
    }
    NodeCapacity = cnt;
    if (cnt == 0)
    {
        return NULL;
    }
    struct Node **NodeList = (struct Node **)malloc(NodeCapacity * sizeof(struct Node *));
    // if (NodeList == NULL)
    // {
    //     printf("can't malloc NodeList\n");
    //     return 0;
    // }
    for (int i = 0; i < NodeCapacity; i++)
    {
        NodeList[i] = (struct Node *)malloc(1 * sizeof(struct Node));
        // if (NodeList[i] == NULL)
        // {
        //     printf("can't malloc Node\n");
        //     return 0;
        // }
    }

    node = head;
    while (node != NULL)
    {
        NodeSize++;
        // printf("%d\n", NodeSize);
        NodeList[NodeSize]->val = node->val;
        NodeList[NodeSize]->next = NodeSize + 1 < NodeCapacity ? NodeList[NodeSize + 1] : NULL;
        // printf("%d\n", NodeList[NodeSize]->next);
        NodeList[NodeSize]->random = node->random == NULL ? NULL : NodeList[map[(int)node->random / 4]];
        node = node->next;
    }
    return *NodeList;
}
// @lc code=end
