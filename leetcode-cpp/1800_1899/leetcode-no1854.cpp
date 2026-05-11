// problem: https://leetcode.cn/problems/maximum-population-year/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>> &logs) {
        auto years = vector<int>(101);
        for (auto people: logs) {
            years[people[0] - 1950]++;
            years[people[1] - 1950]--;
        }
        int mx = years[0], res = 1950;
        for (int i = 1; i < 101; ++i) {
            years[i] = years[i] + years[i - 1];
            if (years[i] > mx) {
                res = i + 1950;
                mx = years[i];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumPopulation(temp_vector({temp_vector({1993, 1999}), temp_vector({2000, 2010})})) << endl;
}

//
// Created By jing At 2026-05-11 21:39
//
