// problem:
#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

#include "../utils/vector_helper.h"
using namespace std;

// time spent 55:27

class Solution {
public:
    long long maximumTotalDamage(vector<int> &power) {
        ranges::sort(power);
        int n = power.size();
        vector dpMax = vector(n, 0LL);
        vector dpChosenMax = vector(n, 0LL);
        dpMax[0] = power[0];
        dpChosenMax[0] = power[0];
        for (int i = 1; i < n; ++i) {
            dpChosenMax[i] = power[i];
            dpMax[i] = max(dpMax[i - 1], dpChosenMax[i]);
            const long long cur = power[i];
            for (int j = i - 1; j >= 0; --j) {
                const long long last = power[j];
                if (cur - last > 2 or cur == last) {
                    if (cur == last) {
                        dpChosenMax[i] = dpChosenMax[j] + power[i];
                    } else {
                        dpChosenMax[i] = max(dpChosenMax[i], dpMax[j] + power[i]);
                    }
                    dpMax[i] = max(dpMax[i], dpChosenMax[i]);
                    break;
                }
            }
        }
        return dpMax[n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumTotalDamage(temp_vector({1, 1, 3, 4})) << " 6" << endl;
    cout << test.maximumTotalDamage(temp_vector({7, 1, 6, 6})) << " 13" << endl;
    cout << test.maximumTotalDamage(temp_vector({7, 1, 6, 3})) << " 10" << endl;
    cout << test.maximumTotalDamage(temp_vector({5, 9, 2, 10, 2, 7, 10, 9, 3, 8})) << " 31" << endl;
}

//
// Created By Zackary At 2025-06-08 21:06:05
//
