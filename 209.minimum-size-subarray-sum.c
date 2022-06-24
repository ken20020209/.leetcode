    /*
 * @lc app=leetcode id=209 lang=c
 *
 * [209] Minimum Size Subarray Sum
 */
#include "header\leetcode.h"

@lc code=start
#define MIN(a,b) (((a)<(b))?(a):(b))
// int mmin(int a, int b)
// {
//     return a < b ? a : b;
// }
// int minSubArrayLen(int target, int* nums, int numsSize)
// {
//     // int *preSum= (int*)malloc(numsSize * sizeof(int));
//     int *preSum=nums;
//     int min=INT_MAX;
//     for (int i=1;i<numsSize;i++)preSum[i]=nums[i]+preSum[i-1];
//     if(preSum[numsSize-1]<target)return 0;
//     int left=0;
//     for (int i=0;i<numsSize;i++)
//     {
//         if(preSum[i]>=target)
//         {
//             // printf("%d ",preSum[i]);
//             min=mmin(min,i+1);
//             for(;left<i;left++)
//             {
//                 if(preSum[i]-preSum[left]>=target)
//                 {
//                     min=mmin(min,i-left);
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
//     }
//     return min;
// }
int minSubArrayLen(int target, int* nums, int numsSize){
    
    int min=INT_MAX;
    int left=0;
    int right=0;
    int sum=0;
    while (right<numsSize)
    {
        sum=sum+nums[right];
        while(sum>=target)
        {
            min=MIN(min,right-left+1);
            sum=sum-nums[left];
            left++;
        }
        right++;
    }
    return min == INT_MAX ? 0 : min;
}
// @lc code=end
#include "header\readtestcase.h"
int main(int argc, char* argv[])
{
    char **str=readtestcase();
    int target;
    int *nums;
    int numsSize;
    target=stoi(str[0]);
    nums=stoia(str[1],&numsSize);
    int temp=minSubArrayLen(target,nums,numsSize);
    printf("\nans:%d\n",temp);
    return 0;

}