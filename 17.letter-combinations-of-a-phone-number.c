/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter Combinations of a Phone Number
 */
#include "header\leetcode.h"

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char num[9][4]={"abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
void combin(char *digits,int *returnSize,char **res,char *temp,int tsize)
{
    int dlen=strlen(digits);
    if(dlen==0)
    {
        memcpy(res[*returnSize],temp,dlen);
        *returnSize=*returnSize+1;
        return;
    }
    if(*digits==2||*digits==7)
    {
        for (int i = 0; i < 4; i++)
        {
            temp[tsize-dlen]=num[*digits][i];
            combin(digits+1,returnSize,res,temp,tsize);
        }
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            temp[tsize-dlen]=num[*digits][i];
            combin(digits+1,returnSize,res,temp,tsize);
        }
        
    }
    
}
char ** letterCombinations(char * digits, int* returnSize)
{
    int dlen=strlen(digits);
    char **res=(char**)malloc(pow(3,dlen)*sizeof(char*));
    char *temp=(char*)malloc(dlen*sizeof(char));
    *returnSize=0;
    for(int i=0; i<dlen; i++)
    {
        digits[i]-='2';
    }
    combin(digits,returnSize,res,temp,dlen);
    return res;
}
// @lc code=end
int main()
{
    char a[3]="23\0";
    int s=0;
    letterCombinations(a,&s);
    return 0;

}
