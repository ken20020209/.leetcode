#include "../header/leetcode.h"

typedef (*KeyCompare)(const void *, const void *);
typedef (*hashCode)(const void *);
typedef struct HashNode
{
    void *key;
    void *val;
    struct HashNode *pre;
    struct HashNode *next;
} HashNode;
typedef struct HashTableHead
{
    int length;
    struct HashNode *head;
} HashTableHead;
typedef struct HashTable
{
    int size;
    int loadfactor; // size/capacity
    int capacity;
    KeyCompare key_eq;
    hashCode hash;
    HashTableHead **buckets;
} HashTable;

HashTable *HashTableCreate(int size, KeyCompare key_eq, hashCode hash)
{
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = 0;
    table->loadfactor = 0;
    table->capacity = size;
    table->key_eq = key_eq;
    table->hash = hash;
    table->buckets = (HashTableHead **)calloc(size, sizeof(HashTableHead *));
    for (int i = 0; i < size; i++)
        table->buckets[i] = (HashTableHead *)calloc(1, sizeof(HashTableHead));
    return table;
}
int HashTableAddress(HashTable *table, void *key)
{
    int address = table->hash(key) % table->capacity;
    return address < 0 ? -address : address;
}
// return val was update
void *HashTableInsert(HashTable *table, void *key, void *val)
{
    int address = HashTableAddress(table, key);
    HashNode *node = table->buckets[address]->head;
    for (int i = 0; i < table->buckets[address]->length; i++)
    {
        int cmp = table->key_eq(node->key, key);
        if (cmp == 0)
        {
            void *ret = node->val;
            node->val = val;
            return ret;
        }
        node = node->next;
    }
    table->buckets[address]->length++;
    node = (HashNode *)malloc(sizeof(HashNode));
    node->val = val;
    node->key = key;
    node->next = table->buckets[address]->head;
    node->pre = NULL;
    if (node->next != NULL)
        node->next->pre = node;
    table->buckets[address]->head = node;
    return NULL;
}
void *HashTableFind(HashTable *table, void *key)
{
    int address = HashTableAddress(table, key);
    HashNode *node = table->buckets[address]->head;
    for (int i = 0; i < table->buckets[address]->length; i++)
    {
        int cmp = table->key_eq(node->key, key);
        if (cmp == 0)
        {
            return node->val;
        }
        node = node->next;
    }
    return NULL;
}
// call back function
int BKDhash(char *key)
{
    int hashCode = 0;
    while (*key++)
        hashCode = hashCode * 31 + *key;
    return hashCode;
}
int keystrcmp(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}
int inthash(void *key)
{
    return (int)key;
}
int key_cmp(void *a, void *b)
{
    return (int)a - (int)b;
}
int main()
{
    // HashTable *table = HashTableCreate(100, (KeyCompare)key_cmp, (hashCode)inthash);
    HashTable *table = HashTableCreate(100, (KeyCompare)keystrcmp, (hashCode)BKDhash);
    char buf[100];
    for (int i = 0; i < 1001; i++)
    {
        sprintf(buf, "%d\0", i);
        char *key = (char *)malloc((strlen(buf) + 1) * sizeof(char));
        strcpy(key, buf);
        HashTableInsert(table, key, (void *)i);
    }
    HashTableInsert(table, "absd", (void *)999);
    printf("val:%d\n", (int)HashTableFind(table, "absd"));
    return 0;
}