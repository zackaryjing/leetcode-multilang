// problem:
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int findBestValue(vector<int> &arr, int target) {
        ranges::sort(arr);
        views::zip(arr, )
        inclusive_scan(arr.begin(), arr.end(), arr.begin(), [](auto acc, auto c) { return acc + c; }, 0);
        show_vector(arr);
        lower_bound();
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    test.findBestValue(temp_vector({4, 9, 3}), 10);
}

//
// Created By ASUS At 2026-02-14 21:21
//
