#include "../header/leetcode.h"

#define abs(a) (((a) >= 0) ? (a) : -(a))
typedef struct HashNode
{
    int val;
    int key;
    struct HashNode *pre;
    struct HashNode *next;
} HashNode;
typedef struct HashTableHead
{
    int length;
    struct HashNode *node;
} HashTableHead;
typedef struct HashTable
{
    int size;
    int loadfactor;
    int capacity;
    int NeedReHash;
    struct HashTableHead **head; // data link list
} HashTable;
int BKDhash(char *str)
{
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++)
        hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}
HashNode *HashNodeCreate()
{
    HashNode *node = (HashNode *)calloc(1, sizeof(HashNode));
    return node;
}
void HashNodeFree(HashNode *node)
{
    free(node);
}
void HashLinkListFree(HashTableHead *head)
{
    int len = head->length;
    for (int i = 0; i < len; i++)
    {
        HashNode *node = head->node->next;
        free(head->node);
        head->node = node;
    }
}
HashTable *HashTableCreate(int capacity)
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    if (ht == NULL)
        return NULL;
    ht->size = 0;
    ht->capacity = capacity;
    ht->loadfactor = 0;
    ht->NeedReHash = 0;
    ht->head = (HashTableHead **)calloc(capacity, sizeof(HashTableHead *));
    if (ht->head == NULL)
    {
        free(ht);
        return NULL;
    }
    return ht;
}
void HashTableFree(HashTable *table)
{
    for (int i = 0; i < table->capacity; i++)
    {
        if (table->head[i] != NULL)
        {
            if (table->head[i]->length == 0)
            {
                free(table->head[i]);
            }
            else
            {
                HashLinkListFree(table->head[i]);
                free(table->head[i]);
            }
        }
    }
    free(table->head);
    free(table);
}

int HashTableInsert(HashTable *table, int key, int value)
{
    int address = key % table->capacity;
    address = abs(address);
    if (table->head[address] == 0)
    {
        table->head[address] = (HashTableHead *)malloc(sizeof(HashTableHead));
        table->head[address]->length = 1;
        table->head[address]->node = HashNodeCreate();
        table->head[address]->node->val = value;
        table->head[address]->node->key = key;
        table->size++;
    }
    else if (table->head[address]->length == 0)
    {
        table->head[address]->length = 1;
        table->head[address]->node = HashNodeCreate();
        table->head[address]->node->val = value;
        table->head[address]->node->key = key;
        table->size++;
    }
    else
    {
        table->head[address]->length++;
        table->head[address]->node->pre = HashNodeCreate();
        table->head[address]->node->pre->next = table->head[address]->node;
        table->head[address]->node = table->head[address]->node->pre;
        table->head[address]->node->val = value;
        table->head[address]->node->key = key;
        table->size++;
    }
    return 1;
}
// return 0 cant fine
// return address
HashNode *HashTableSerch(HashTable *table, int key)
{
    int address = key % table->capacity;
    address = abs(address);
    if (table->head[address] == NULL)
        return 0;
    if (table->head[address]->length == 0)
        return 0;
    HashNode *node = table->head[address]->node;
    while (node != NULL)
    {
        if (node->key == key)
            return node;
        node = node->next;
    }
    return 0;
}
// return deleted elements
int HashTableRM(HashTable *table, int key)
{
    int address = key % table->capacity;
    address = abs(address);
    int len = table->head[address]->length;
    int ret = 0;
    if (len == 0)
        return 0;
    HashNode *node = table->head[address]->node;
    HashNode *temp;
    while (node != NULL)
    {
        if (node->key == key)
        {
            if (node->pre == NULL)
            {
                table->head[address]->node = node->next;
                table->head[address]->node->pre = NULL;
                table->head[address]->length--;
                temp = node->next;
                HashNodeFree(node);
                node = temp;
                ret++;
            }
            else
            {
                node->pre->next = node->next;
                table->head[address]->length--;
                temp = node->next;
                HashNodeFree(node);
                node = temp;
                ret++;
            }
        }
        else
        {
            node = node->next;
        }
    }
    return ret;
}
// return get data size;
// 0 no data
//-1 cant save every data
int HashTableDataGet(HashTable *table, int key, int *arr, int size)
{
    int address = key % table->capacity;
    address = abs(address);
    if (table->head[address] == NULL)
        return 0;
    int len = table->head[address]->length;
    HashNode *node = table->head[address]->node;
    if (len == 0)
        return 0;
    if (len > size)
        return -1;
    for (int i = 0; i < len; i++)
    {
        arr[i] = node->val;
        node = node->next;
    }
    return len;
}
int HashTablePrintf(HashTable *table, int key)
{
    int address = key % table->capacity;
    address = abs(address);
    printf("key:%d\n", key);
    if (table->head[address] == NULL || table->head[address]->length == 0)
    {
        printf("There is no data\n");
        return 0;
    }
    HashNode *node = table->head[address]->node;
    for (int i = 0; i < table->head[address]->length; i++)
    {
        printf("LinkList%d:%d\n", i + 1, node->val);
        node = node->next;
    }
    return 1;
}
int main()
{
    HashTable *ht = HashTableCreate(1000);
    HashTableInsert(ht, 20, 100);
    HashTableInsert(ht, 20, 1000);
    HashTableInsert(ht, 20, 1000);
    HashTableInsert(ht, 20, 1000);
    HashTableInsert(ht, 20, 1000);
    HashTableInsert(ht, 20, 1000);
    HashTableInsert(ht, 20, 1000);
    int arr[100] = {0};
    int size = HashTableDataGet(ht, 20, arr, 100);
    HashTableFree(ht);
    return 0;
}