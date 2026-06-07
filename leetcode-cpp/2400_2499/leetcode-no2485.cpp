// problem: https://leetcode.cn/problems/find-the-pivot-integer/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int inner = n * (n + 1) / 2;
        int k = std::sqrt(inner);
        if (k * k != inner) {
            return -1;
        }
        return k;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.pivotInteger(8) << endl;
}

//
// Created By jing At 21:38
//
