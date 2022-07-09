/*
 * @lc app=leetcode id=173 lang=c
 *
 * [173] Binary Search Tree Iterator
 */
#include "header\leetcode.h"
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct
{
    int capacity;
    int size;
    int index;
    struct TreeNode **node;
} BSTIterator;
void inorder(struct TreeNode *node, BSTIterator *obj)
{
    if (node == NULL)
        return;
    inorder(node->left, obj);
    obj->node[obj->size] = node;
    obj->size++;
    if (obj->size == obj->capacity)
    {
        obj->capacity *= 2;
        obj->node = (struct TreeNode **)realloc(obj->node, obj->capacity * sizeof(struct TreeNode *));
    }
    inorder(node->right, obj);
}
BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{
    BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    obj->capacity = 2;
    obj->size = 0;
    obj->index = 0;
    obj->node = (struct TreeNode **)malloc(obj->capacity * sizeof(struct TreeNode *));
    inorder(root, obj);
    return obj;
}

int bSTIteratorNext(BSTIterator *obj)
{
    int ret = obj->node[obj->index]->val;
    obj->index++;
    return ret;
}

bool bSTIteratorHasNext(BSTIterator *obj)
{
    if (obj->index < obj->size)
        return true;
    return false;
}

void bSTIteratorFree(BSTIterator *obj)
{
    free(obj->node);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/
// @lc code=end
