/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// O(n^2) time O(1) space
/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int i =0;
    int j=0;
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {

            if(!(target-nums[i]-nums[j]))
               {
                   numsSize=-1;
               }
        }
    }
    *returnSize=2;
    int *result = malloc(sizeof(*result) * 2);
    result[0]=i-1;
    result[1]=j-1;
    return result;
}
*/

// Hash O(n) time O(n) spacce

#define hash_table_size 500
#define abs(a) a<0?-a:a
struct hash_node{
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
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    struct hash_map *table=hash_map_create();;
    *returnSize=2;
    int *ret=malloc(sizeof(int)*(*returnSize));
    //printf("table=%d\n",table);
    for(int i=0;i<numsSize;i++)
    {
        int sum=target-nums[i];
        
        /*debug
        printf("i=%d\n",i);
        printf("nums[i]=%d\n",nums[i]);
        printf("sum=%d\n",sum);
        printf("\n");
        */
        
        if(hash_map_serch(table,sum)==1)
        {
            printf("IN\n");
            ret[0]=hash_map_get_address(table,sum);
            ret[1]=i;
            break;
        }
        else
        {
            hash_map_put(table,nums[i],i);
        }
        hash_map_put(table,nums[i],i);
        
    }
    return ret;
  
}
//printf("test\n");
// @lc code=end

