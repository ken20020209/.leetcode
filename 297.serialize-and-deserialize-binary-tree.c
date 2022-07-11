/*
 * @lc app=leetcode id=297 lang=c
 *
 * [297] Serialize and Deserialize Binary Tree
 */
#include "header\leetcode.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
struct string
{
    int capacity;
    int size;
    int next;
    char *data;
};
void preorder(struct TreeNode *node, struct string *buf)
{
    char temp[30];
    if (node == NULL)
    {
        if (buf->size + 20 >= buf->capacity)
        {
            buf->capacity *= 2;
            buf->data = (char *)realloc(buf->data, buf->capacity * sizeof(char));
        }
        sprintf(buf->data + buf->size, "# \0");
        buf->size += 2;
    }
    else
    {
        if (buf->size + 20 >= buf->capacity)
        {
            buf->capacity *= 2;
            buf->data = (char *)realloc(buf->data, buf->capacity * sizeof(char));
        }
        sprintf(temp, "%d \0", node->val);
        int len = strlen(temp);
        memcpy(buf->data + buf->size, temp, len + 1);
        buf->size += len;

        preorder(node->left, buf);
        preorder(node->right, buf);
    }
}
char *serialize(struct TreeNode *root)
{
    struct string *buf = (struct string *)malloc(sizeof(struct string));
    if (buf == NULL)
    {
        printf("cant allocate memory\n");
        return NULL;
    }
    buf->capacity = 100;
    buf->size = 0;
    buf->data = (char *)malloc(buf->capacity * sizeof(char));
    if (buf->data == NULL)
    {
        printf("cant allocate memory\n");
        return NULL;
    }
    preorder(root, buf);

    char *data = buf->data;
    data = (char *)realloc(data, (buf->size + 1) * sizeof(char));
    free(buf);
    // printf("%s\n", data);
    return data;
}

/** Decodes your encoded data to tree. */
void findnext(struct string *data)
{
    for (int i = data->next; i < data->capacity; i++)
    {
        if (*(data->data + i) == ' ')
        {
            data->next = i + 1;
            break;
        }
    }
}
struct TreeNode *decode(struct string *data)
{
    if (*(data->data + data->next) == '#')
    {
        findnext(data);
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = atoi(data->data + data->next);
    findnext(data);
    root->left = decode(data);
    root->right = decode(data);
    return root;
}
struct TreeNode *deserialize(char *data)
{
    struct string *buf = (struct string *)malloc(sizeof(struct string));
    buf->data = data;
    buf->next = 0;
    buf->size = strlen(buf->data);
    buf->capacity = buf->size + 1;
    struct TreeNode *root = decode(buf);
    free(buf);
    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
// @lc code=end
