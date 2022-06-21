#include "../header/leetcode.h"
#define hash_table_size 500
struct hash_node
{
    int val;
    int len;
    int address;
    //struct hash_node*next;
};
struct hash_map{
    int size;
    struct hash_node*data;
};
int hash_key(int key)
{
    //printf("key=%d\n",key);
    return abs(key%hash_table_size);
}
struct hash_map *hash_map_create()
{
    //printf("%d\n",sizeof(struct hash_map*));
    struct hash_map* table=malloc(sizeof(struct hash_map));
    table->size=hash_table_size;
    //printf("%d\n",table->size);
    table->data=calloc(table->size,sizeof(struct hash_node));
    return table;
}
void hash_map_put(struct hash_map *table,int val,int address)
{
    int key=hash_key(val);
    table->data[key].val=val;
    table->data[key].len++;
    table->data[key].address=address;
}
int hash_map_get_address(struct hash_map *table,int val)
{
    int key=hash_key(val);
    if(table->data[key].len==0)return -1;
    return table->data[key].address;
}
int hash_map_serch(struct hash_map *table,int val)
{
    int key=hash_key(val);
    //printf("key=%d\n",key);
    if(table->data[key].len==0)return -1;
    if(table->data[key].val==val)return 1;
    return 0;
}
void hash_map_free(struct hash_map *table)
{
    free(table->data);
    free(table);
}