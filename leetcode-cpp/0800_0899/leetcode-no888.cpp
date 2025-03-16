// problem: fair-candy-swap
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
        pmr::unordered_set<int> bob(bobSizes.begin(), bobSizes.end());
        int atotal = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int btotal = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (atotal - btotal) / 2;

        for (auto a: aliceSizes) {
            if (bob.contains(a - delta)) {
                return {a, a - delta};
            }
        }
        return {};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1 = {1, 1};
    vector<int> eg2 = {2, 2};
    show_vector(test.fairCandySwap(eg1, eg2));
}


//
// Created by ASUS on 2025/3/14.
//
