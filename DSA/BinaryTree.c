typedef struct BinaryTreeNode
{
    const void *key;
    void *val;
    BinaryTreeNode *parent;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

} BinaryTreeNode;
typedef struct BinaryTree
{
    int depth;
    int size;
    BinaryTree *root;
} BinaryTree;
BinaryTree *BinaryTree_New()
{
    BinaryTree *tree = (BinaryTree *)calloc(1, sizeof(BinaryTree));
    return tree;
}