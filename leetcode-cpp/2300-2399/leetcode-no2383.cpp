// problem:
// https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience) {
        int hours = 0;
        hours += max(accumulate(energy.begin(), energy.end(), 0) - initialEnergy + 1, 0);
        for (const auto exp: experience) {
            if (initialExperience <= exp) {
                hours += exp - initialExperience + 1;
                initialExperience = exp + 1;
            }
            initialExperience += exp;
        }
        return hours;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minNumberOfHours(5, 3, temp_vector({1, 4, 3, 2}), temp_vector({2, 6, 3, 1})) << endl;
    cout << test.minNumberOfHours(100, 100, temp_vector({1, 2, 3, 4, 5, 6, 7, 8, 9}),
                                  temp_vector({1, 2, 3, 1, 2, 3, 1, 2, 10}))
         << endl;
}

//
// Created By jing At 2026-05-23 21:58
//
