#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        double five_sq = pow(5, 0.5);
        return round((1 / five_sq) * (pow((1 + five_sq) / 2, n) - pow((1 - five_sq) / 2, n)));
    }
};

int main() {
    Solution test;
    cout << test.tribonacci(5) << endl;

}

//
// Created by ASUS on 2024/7/15.
//
