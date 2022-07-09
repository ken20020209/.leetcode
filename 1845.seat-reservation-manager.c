/*
 * @lc app=leetcode id=1845 lang=c
 *
 * [1845] Seat Reservation Manager
 */
#include "header\leetcode.h"

// @lc code=start

// here may use binary tree of red black tree to otimizaion
typedef struct
{
    int front;
    int rear;
    int *queue;
} SeatManager;

SeatManager *seatManagerCreate(int n)
{
    SeatManager *obj = (SeatManager *)malloc(sizeof(SeatManager));
    obj->front = 0;
    obj->rear = n - 1;
    obj->queue = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        obj->queue[i] = i + 1;
    }
    return obj;
}

int seatManagerReserve(SeatManager *obj)
{
    if (obj->front > obj->rear)
        return NULL;
    return obj->queue[obj->front++];
}

void seatManagerUnreserve(SeatManager *obj, int seatNumber)
{
    int pos = obj->front - 1;
    // line serch
    //  for (int i = obj->front; i <= obj->rear; i++)
    //  {
    //      if (seatNumber > obj->queue[i])
    //          pos = i;
    //      else
    //          break;
    //  }

    // BS
    int high = obj->rear;
    int low = obj->front;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (seatNumber < obj->queue[mid])
        {
            high = mid - 1;
        }
        else
        {
            pos = mid;
            low = mid + 1;
        }
    }

    obj->front--;
    // printf("setNumber:%d obj->front = %d pos:%d \n", seatNumber, obj->front, pos);
    for (int i = obj->front; i < pos; i++)
    {
        obj->queue[i] = obj->queue[i + 1];
    }
    obj->queue[pos] = seatNumber;
}

void seatManagerFree(SeatManager *obj)
{
    free(obj->queue);
    free(obj);
}

/**
 * Your SeatManager struct will be instantiated and called as such:
 * SeatManager* obj = seatManagerCreate(n);
 * int param_1 = seatManagerReserve(obj);

 * seatManagerUnreserve(obj, seatNumber);

 * seatManagerFree(obj);
*/
// @lc code=end
