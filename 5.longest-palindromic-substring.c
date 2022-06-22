/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */
#include "header\leetcode.h"

// @lc code=start
char *init(char *s,int* clen)
{
    int len = strlen(s);
    int nlen=2*len+4;
    *clen=nlen;
    char *ret = (char *)malloc((nlen)* sizeof(char));
    int ret_pos=2;
    ret[0] = '$';
    ret[1] = '#';
    for (int i = 0; i < len; i++)
    {
        ret[ret_pos++] = s[i];
        ret[ret_pos++] = '#';
    }
    ret[nlen-2] = '^';
    ret[nlen-1] = '\0';
    return ret;
}
char *Manacher(char *s)
{
    int len;
    char *temp = init(s,&len);
    int *dp=(int *)calloc(len, sizeof(int));
    int pos=-1;
    int id=0;
    int mx=0;
    int max=INT_MIN;
    for (int i = 1; i < len-1; i++)
    {
        if(i<mx)
        {
            dp[i]=fmin(dp[id*2-i],mx-i);
        }
        else
        {
            dp[i]==1;
        }
        while (temp[i-dp[i]]==temp[i+dp[i]])dp[i]++;
        if(i+dp[i]>mx)
        {
            id=i;
            mx=i+dp[i];
        }
        if(dp[i]>max)
        {
            pos=i;
            max=dp[i];
        }
    }
    
    // printf("len:%d\n", len);
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%-3c",temp[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%-3d",dp[i]);
    // }
    // printf("\n");
    // printf("max: %d\n",max);
    // printf("pos: %d\n",pos);
    // for (int i = pos-max+1; i < pos+max-1; i++)
    // {
    //     if(temp[i]!='#')
    //     {
    //         *s=temp[i];
    //         // printf("%c",*s);
    //         s++;
    //     }
    // }

    // *s='\0';
    // s-=(max-1);
    pos=pos-(max-1);
    if(temp[pos]=='#')pos++;
    pos=pos/2-1;
    s+=pos; 
    s[max-1]='\0';
    free(temp);
    return s;
}
char *longestPalindrome(char *s)
{
    return Manacher(s);
}
// @lc code=end
