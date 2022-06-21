#include "../header/leetcode.h"

/*----------------------------------------------------------------
1:done 0:nodone
1   int
1   int[]
1   int[][]
1   char
1   char[]
1   char[][]
0   float
0   float[]
0   float[][]
0   double
0   double[]
0   double[][]
----------------------------------------------------------------*/
int stoi(char *s)
{
    return atoi(s);
}
int* stoia(char *s,int *size)
{
    int *ret;
    int start=1;
    int end=1;
    int count=1;
    char temp[10]={0};
    for (int i = 0; i < strlen(s); i++)if(s[i]==',')count++;
    *size=count;
    ret=(int*)malloc(count*sizeof(int));
    for (int i = 0; i < count; i++)
    {
        while (s[end]>='0'&&s[end]<='9')end++;
        memcpy(temp,s+start,end-start);
        temp[end-start]=0;   
        ret[i]=stoi(temp);

        start=end+1;
        end=start;
    }
    return ret;
}
int** stoiaa(char *s,int *size,int **colsize)
{
    int **ret;
    int start=1;
    int end=1;
    int count=0;
    char *temp=(char*)calloc(strlen(s)+1,sizeof(char));
    for (int i = 1; i < strlen(s); i++)if(s[i]=='[')count++;
    *size=count;
    ret=(int**)malloc(count*sizeof(int**));
    *colsize=(int*)malloc(count*sizeof(int));
    for (int i = 0; i < count; i++)
    {
        while(s[end]!=']')end++;
        memcpy(temp,s+start,end-start+1);
        temp[end-start+1]=0;

        ret[i]=stoia(temp,&(*colsize)[i]);

        start=end+2;
        end=start;
    }
    free(temp);
    return ret;
}
char stoc(char *s)
{
    return *(s+1);
}
char* stoca(char *s)
{
    int len=strlen(s);
    if(s[len-1]=='\n')len--;
    len-=2;
    char *ret=(char*)calloc(len+1,sizeof(char));
    memcpy(ret,s+1,len);
    return ret;
}
char** stocaa(char *s,int *size)
{
    int count=0;
    int start=1;
    int end=2;
    char **ret;
    char *temp=(char*)calloc(strlen(s)+1,sizeof(char));
    for (int i = 0; i < strlen(s); i++)if(s[i]=='"')count++;
    count/=2;
    *size=count;
    ret=(char**)malloc(count*sizeof(char**));
    for (int i = 0; i < count; i++)
    {
        while(s[end]!='"')end++;
        memcpy(temp,s+start,end-start+1);
        temp[end-start+1]=0;
        ret[i]=stoca(temp);

        start=end+2;
        end=start+1;
    }
    return ret;
}
char **readtestcase()
{
    char **str;
    str=(char**)malloc(30*sizeof(char*));
    for (int i = 0; i < 10; i++)str[i]=(char*)calloc(1000000,sizeof(char));
    int line=0;
    FILE *fp=fopen("C:\\Users\\Ken\\.leetcode\\test\\testcase.txt","r");
    if(fp==NULL)
    {
        printf("cannot open testcase.txt\n");
        return 0;
    }
    while (!feof(fp))fgets(str[line++],1000000,fp);
    fclose(fp);
    return str;
}
/*
int main()
{

    char **str=readtestcase();
    
    return 0;
}
*/