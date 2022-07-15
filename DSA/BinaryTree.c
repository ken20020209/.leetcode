#include <stdio.h>

typedef (*BST_compare_fn)(void *key1, void *key2);
typedef struct BSTNode
{
    void *key;
    void *val;
    struct BSTNode *parent;
    struct BSTNode *left;
    struct BSTNode *right;

} BSTNode;
typedef struct BST
{
    int depth;
    int size;
    BST_compare_fn compare_fn;
    BSTNode *root;
} BST;
BSTNode *BSTNode_New(void *key, void *val)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->key = key;
    node->val = val;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}
BST *BST_New(BST_compare_fn compare_fn)
{
    BST *tree = (BST *)malloc(sizeof(BST));
    tree->depth = 0;
    tree->size = 0;
    tree->compare_fn = compare_fn;
    tree->root = NULL;
    return tree;
}
void *BST_Search(BST *tree, void *key)
{
    int cmp;
    BSTNode *node = tree->root;
    while (node != NULL)
    {
        cmp = tree->compare_fn(node->key, key);
        if (cmp == 0)
            return node->val;
        else if (cmp > 0)
            node = node->right;
        else
            node = node->left;
    }
    return NULL;
}
void BST_Insert(BST *tree, BSTNode *node)
{
    int cmp;
    int depth = 1;
    BSTNode *pretreeNode = NULL;
    BSTNode *treeNode = tree->root;
    while (node != NULL)
    {
        depth++;
        pretreeNode = treeNode;
        cmp = tree->compare_fn(treeNode->key, node->key);
        if (cmp > 0)
            treeNode = treeNode->right;
        else if (cmp < 0)
            treeNode = treeNode->left;
        else
        {
            treeNode->val = node->val;
            free(node);
            return;
        }
    }
    tree->depth = depth > tree->depth ? depth : tree->depth;
    node->parent = pretreeNode;
    if (pretreeNode == NULL)
        tree->root = node;
    else if (tree->compare_fn(pretreeNode->key, node->key) > 0)
        pretreeNode->right = node;
    else
        pretreeNode->left = node;
}
void BST_Print(BST *tree)
{
    printf("Tree depth: %d\n", tree->depth);
}
int cmp(void *a, void *b)
{
    return (long)a - (long)b;
}
int main()
{
    BST *tree = BST_New(cmp);
    BST_Insert(tree, BSTNode_New(1, 1));
    BST_Insert(tree, BSTNode_New(2, 2));
    BST_Insert(tree, BSTNode_New(3, 3));
    BST_Print(tree);
    return 0;
}