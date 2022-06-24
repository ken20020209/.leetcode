/*
 * @lc app=leetcode id=459 lang=c
 *
 * [459] Repeated Substring Pattern
 */
#include "header\leetcode.h"

// @lc code=start


// bool repeatedSubstringPattern(char * s)
// {
//     int len=strlen(s);
//     char *temp=(char*)calloc(len+1,sizeof(char));
//     for (int i = 1; i < len/2+1; i++)
//     {
//         if(len%i==0)
//         {
//             int clen=len/i;
//             for(int j=0;j<clen;j++)
//             {
//                 memcpy(temp+(j*i),s,i);
//             }
//             if(strcmp(temp,s)==0)return true;
//         }
//     }
//     return false;
// }
bool repeatedSubstringPattern(char * s)
{
    int len=strlen(s);
    char*temp=(char*)calloc(len*2+1,sizeof(char));
    memcpy(temp,s,len);
    memcpy(temp+len,s,len);
    temp[2*len-1]=0;
    temp[0]='1';
    int res=strstr(temp,s);
    // printf("%s\n",temp);
    // printf("res:%d\n",res);
    free(temp);
    return res;
}
// @lc code=end

