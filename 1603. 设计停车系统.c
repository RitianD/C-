// https://leetcode.cn/problems/design-parking-system/description/


typedef struct {
    int parking[4];
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem * sys = malloc(sizeof(ParkingSystem));
    sys->parking[1] = big;
    sys->parking[2] = medium;
    sys->parking[3] = small;
    return sys;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (obj->parking[carType] > 0) {
        obj->parking[carType]--;
        return true;
    }
    return false;
}

void parkingSystemFree(ParkingSystem* obj) {
    
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/