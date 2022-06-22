#include "../header/leetcode.h"
#define hash_table_size 500
typedef struct HashNode
{
    int val;
    struct HashNode *pre;
    struct HashNode*next;
}HashNode;
typedef struct HashTableHead
{
    int length;
    struct HashNode *node;
}HashTableHead;
typedef struct HashTable
{
    int size;
    int loadfactor;
    int capacity;
    struct HashTableHead*data;
}HashTable;
int BKDhash(char* str)
{
    int seed=31,hash=0;
    for (int i = 0; str[i]; i++)hash=hash*seed+str[i];
    return hash&0x7fffffff;
    
}
HashTable* HashTableCreate(int capacity)
{
    HashTable* ht=(HashTable*)malloc(sizeof(HashTable));
    if(ht==NULL)return NULL;
    ht->size=0;
    ht->capacity=capacity;
    ht->loadfactor=0;
    ht->data=(HashTableHead*)malloc(capacity*sizeof(HashTableHead));
    if(ht->data==NULL)
    {
        free(ht);
        return NULL;
    }
    return ht;
    
}
void HashTableFree(HashTable* table)
{
    free(table->data);
    free(table);
}
int main()
{
    char str[2];
    str[1]=0;
    for (int i = 0; i < 256; i++)
    {
        str[0]=i;
        printf("%s:%x\n",str,BKDhash(str));
    }
    
}