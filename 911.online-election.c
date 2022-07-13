/*
 * @lc app=leetcode id=911 lang=c
 *
 * [911] Online Election
 */
#include "header\leetcode.h"

// @lc code=start

typedef struct
{
    int size;
    int *time;
    int *winer;
} TopVotedCandidate;

TopVotedCandidate *topVotedCandidateCreate(int *persons, int personsSize, int *times, int timesSize)
{
    TopVotedCandidate *obj = (TopVotedCandidate *)malloc(sizeof(TopVotedCandidate));
    int m = timesSize;
    obj->time = (int *)malloc(m * sizeof(int));
    obj->winer = (int *)malloc(m * sizeof(int));
    obj->size = m;
    memcpy(obj->time, times, m * sizeof(int));
    int *map = (int *)calloc(m, sizeof(int));
    int mostvotes = 0;
    int winer = persons[0];
    for (int i = 0; i < m; i++)
    {
        map[persons[i]]++;
        if (map[persons[i]] >= mostvotes)
        {
            mostvotes = map[persons[i]];
            winer = persons[i];
        }
        obj->winer[i] = winer;
    }
    free(map);
    return obj;
}

int topVotedCandidateQ(TopVotedCandidate *obj, int t)
{
    // for (int i = 0; i < obj->size; i++)
    // {
    //     printf("%d ", obj->time[i]);
    // }
    // printf("\n");
    int winer = -1;
    int high = obj->size - 1;
    int low = 0;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (t >= obj->time[mid])
        {
            winer = obj->winer[mid];
            // printf("    mid = %d\n", mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return winer;
}

void topVotedCandidateFree(TopVotedCandidate *obj)
{
    free(obj->time);
    free(obj->winer);
    free(obj);
}

/**
 * Your TopVotedCandidate struct will be instantiated and called as such:
 * TopVotedCandidate* obj = topVotedCandidateCreate(persons, personsSize, times, timesSize);
 * int param_1 = topVotedCandidateQ(obj, t);

 * topVotedCandidateFree(obj);
*/
// @lc code=end
