// problem: https://leetcode.cn/problems/design-parking-system/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class ParkingSystem {
public:
    vector<int> cnts;
    ParkingSystem(int big, int medium, int small) {
        cnts = {0, big, medium, small};
    }
    bool addCar(int carType) {
        return cnts[carType] > 0 ? --cnts[carType], true : false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main(int argc, char *argv[]) {
    ParkingSystem test(1, 2, 3);
    cout << test.addCar(1) << endl;
    cout << test.addCar(1) << endl;
}

//
// Created By jing At 2026-05-28 17:22
//
