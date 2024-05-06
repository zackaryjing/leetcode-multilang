#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = ceil((-1 + sqrt(8L * target + 1)) / 2.0);
        return (((n * (n + 1) / 2 - target) % 2 == 0) ? n : n + 1 + n % 2);
    }
};

int main(){
    Solution test;
    cout << test.reachNumber(-1000000000) << endl;
}
//
// Created by ASUS on 2023/9/2.
//
