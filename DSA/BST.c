#include <stdio.h>
#include <stdlib.h>
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
BSTNode *BST_Search(BST *tree, void *key)
{
    int cmp;
    BSTNode *node = tree->root;
    while (node != NULL)
    {
        cmp = tree->compare_fn(key, node->key);
        if (cmp == 0)
            return node;
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
    while (treeNode != NULL)
    {
        depth++;
        pretreeNode = treeNode;
        cmp = tree->compare_fn(node->key, treeNode->key);
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
    tree->size++;
    node->parent = pretreeNode;
    if (pretreeNode == NULL)
        tree->root = node;
    else if (tree->compare_fn(node->key, pretreeNode->key) > 0)
        pretreeNode->right = node;
    else
        pretreeNode->left = node;
}
BSTNode *BSTmax(BSTNode *node)
{
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}
BSTNode *BSTmin(BSTNode *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
static void BSTNode_transplant(BST *tree, BSTNode *node1, BSTNode *node2)
{
    if (node1->parent == NULL)
        tree->root = node2;
    else if (node1 == node1->parent->left)
        node1->parent->left = node2;
    else if (node1 == node1->parent->right)
        node1->parent->right = node2;
    if (node2 != NULL)
        node2->parent = node1->parent;
}
BSTNode *BST_delete(BST *tree, void *key)
{
    BSTNode *node = BST_Search(tree, key);
    if (node == NULL)
        return NULL;
    if (node->left == NULL)
        BSTNode_transplant(tree, node, node->right);
    else if (node->right == NULL)
        BSTNode_transplant(tree, node, node->left);
    else
    {
        BSTNode *min = BSTmin(node->right);
        if (min->parent != node)
        {
            BSTNode_transplant(tree, min, min->right);
            min->right = node->right;
            min->right->parent = min;
        }
        BSTNode_transplant(tree, node, min);
        min->left = node->left;
        min->left->parent = min;
    }
    node->parent = NULL;
    node->right = NULL;
    node->left = NULL;
    return node;
}
void BST_Inorder(BSTNode *root)
{
    if (root == NULL)
        return;
    BST_Inorder(root->left);
    printf(" %ld ", (long)root->key);
    BST_Inorder(root->right);
}
void BST_Print_2d(BSTNode *node, int space)
{
    if (node == NULL)
        return;
    space += 10;
    printf("\n");
    BST_Print_2d(node->right, space);
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%ld\n", (long)node->key);
    BST_Print_2d(node->left, space);
}
void BST_Print(BST *tree)
{
    BST_Print_2d(tree->root, 0);
}
int cmp(void *a, void *b)
{
    return (int)a - (int)b;
}
int main()
{
    BST *tree = BST_New(cmp);

    // BST_Print(tree);
    BST_Inorder(tree->root);
    return 0;
}