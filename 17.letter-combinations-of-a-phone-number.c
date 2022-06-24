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
char num[9][4]={"123","abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
void combin(char *digits,int *returnSize,char **res,char *temp,int tsize)
{
    int dlen=strlen(digits);
    if(dlen==0)
    {
        res[*returnSize]=(char *)malloc((tsize+1)*sizeof(char));
        memcpy(res[*returnSize],temp,tsize);
        res[*returnSize][tsize]=0;
        *returnSize=*returnSize+1;
        return;
    }
    if(*digits==6||*digits==8)
    {
        for (int i = 0; i < 4; i++)
        {
            //printf("i:%d\n",i);
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
    char **res=(char**)calloc(pow(4,dlen),sizeof(char*));
    *returnSize=0;
    if(dlen==0)return NULL;
    char *temp=(char*)malloc(dlen*sizeof(char));
    
    for(int i=0; i<dlen; i++)
    {
        digits[i]-='1';
    }
    combin(digits,returnSize,res,temp,dlen);
    //printf("last\n");
    res=(char**)realloc(res,*returnSize*sizeof(char*));
    return res;
}
// @lc code=end
int main()
{
    char a[3]="7\0";
    int s=0;
    char **r=letterCombinations(a,&s);
    return 0;

}
