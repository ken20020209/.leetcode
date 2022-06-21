/*
 * @lc app=leetcode id=1603 lang=c
 *
 * [1603] Design Parking System
 */

#include "header/common.h"
// @lc code=start



typedef struct {
    int carType[4];
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* obj = malloc(sizeof(ParkingSystem));
    obj->carType[1] = big;
    obj->carType[2] = medium;
    obj->carType[3] = small;
    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if(obj->carType[carType]==0) return false;
    obj->carType[carType]--;
    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/
// @lc code=end

