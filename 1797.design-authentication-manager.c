/*
 * @lc app=leetcode id=1797 lang=c
 *
 * [1797] Design Authentication Manager
 */
#include "header\leetcode.h"

// @lc code=start
#define MAPSIZE 10000
typedef struct
{
    int id;
    int createTime;
    int endTime;
} token;
typedef struct
{
    int liveTime;
    token *map[MAPSIZE];

} AuthenticationManager;
int BKDhash(char *key)
{
    int seed = 31;
    int hash = 0;
    while (*key)
    {
        hash = hash * 31 + *key;
        key++;
    }
    return hash & 0x7fffffff;
}
AuthenticationManager *authenticationManagerCreate(int timeToLive)
{
    AuthenticationManager *obj = (AuthenticationManager *)calloc(1, sizeof(AuthenticationManager));
    obj->liveTime = timeToLive;
    return obj;
}

void authenticationManagerGenerate(AuthenticationManager *obj, char *tokenId, int currentTime)
{
    int id = BKDhash(tokenId);
    int address = id % MAPSIZE;
    // printf("new id:%d address:%d\n", id, address);
    while (obj->map[address] != NULL && obj->map[address]->id != id)
    {
        address = address + 1 % MAPSIZE;
    }
    // printf("address = %d\n", address);
    if (obj->map[address] == NULL)
    {
        obj->map[address] = (token *)malloc(sizeof(token));
        if (obj->map[address] == NULL)
            printf("error creating token\n");
    }
    obj->map[address]->createTime = currentTime;
    obj->map[address]->id = id;
    obj->map[address]->endTime = currentTime + obj->liveTime;
}

void authenticationManagerRenew(AuthenticationManager *obj, char *tokenId, int currentTime)
{
    int id = BKDhash(tokenId);
    int address = id % MAPSIZE;
    // printf("renew id:%d address:%d\n", id, address);
    while (obj->map[address] != NULL && obj->map[address]->id != id)
    {
        address = address + 1 % MAPSIZE;
    }
    if (obj->map[address] != NULL && obj->map[address]->id == id && obj->map[address]->endTime > currentTime)
    {
        obj->map[address]->createTime = currentTime;
        obj->map[address]->endTime = currentTime + obj->liveTime;
    }
}

int authenticationManagerCountUnexpiredTokens(AuthenticationManager *obj, int currentTime)
{
    int ret = 0;
    for (int i = 0; i < MAPSIZE; i++)
    {
        if (obj->map[i] != NULL)
        {
            if (obj->map[i]->endTime > currentTime)
            {
                ret++;
            }
            else if (obj->map[i]->endTime <= currentTime)
            {
                // printf("%d\n", obj->map[i]);
                free(obj->map[i]);
                obj->map[i] = NULL;
            }
        }
    }
    return ret;
}

void authenticationManagerFree(AuthenticationManager *obj)
{
    for (int i = 0; i < MAPSIZE; i++)
    {
        if (obj->map[i] != NULL)
        {

            free(obj->map[i]);
            obj->map[i] = NULL;
        }
    }
    free(obj);
}

/**
 * Your AuthenticationManager struct will be instantiated and called as such:
 * AuthenticationManager* obj = authenticationManagerCreate(timeToLive);
 * authenticationManagerGenerate(obj, tokenId, currentTime);

 * authenticationManagerRenew(obj, tokenId, currentTime);

 * int param_3 = authenticationManagerCountUnexpiredTokens(obj, currentTime);

 * authenticationManagerFree(obj);
*/
// @lc code=end
