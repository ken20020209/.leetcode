/*
 * @lc app=leetcode id=303 lang=c
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start



typedef struct {
    int size;
    int *data;
    int *dp;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* array = malloc(sizeof(NumArray));
    array->size = numsSize;
    array->data = malloc(array->size * sizeof(int));
    array->dp = calloc(array->size , sizeof(int));
    array->dp[0]=nums[0];
    array->data[0] = nums[0];
    //printf("dp[%d] = %d\n", 0, array->dp[0]);
    for (int i = 1; i < numsSize; i++)
    {
        array->data[i] = nums[i];
        array->dp[i] +=array->dp[i-1]+nums[i];
        //printf("dp[%d] = %d\n", i, array->dp[i]);
    }
    return array;   // return array created by numArrayCreate() function
}

int numArraySumRange(NumArray* obj, int left, int right) 
{
  int sum = 0;
  left--;
  sum= obj->dp[right] - (left<0?0:obj->dp[left]);
  /*
  for (int i = left; i <= right; i++)  
  {
    sum += obj->data[i];
  }
  */
  return sum; // return sum 
}

void numArrayFree(NumArray* obj) 
{
    free(obj->data);
    free(obj->dp);
    free(obj);    
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
// @lc code=end

