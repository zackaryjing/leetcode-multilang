// problem:  https://leetcode.cn/problems/number-of-beautiful-pairs/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countBeautifulPairs(vector<int> &nums) {
        int n = nums.size();
        vector<int> first(n);
        vector<int> second(n);
        for (int i = 0; i < n; ++i) {
            first[i] = nums[i] % 10;
            int copy = nums[i];
            while (copy >= 10) copy /= 10;
            second[i] = copy;
        }
        const vector coprime = {
        0,          0b1111111110, 0b1010101010, 0b110110110, 0b1010101010, 0b1111011110,
        0b10100010, 0b1101111110, 0b1010101010, 0b110110110,
        };
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if ((coprime[second[j]] >> first[i] & 1) == 1) res++;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countBeautifulPairs(temp_vector({2, 5, 1, 4})) << endl;
}

//
// Created By ASUS At 2026-06-20 19:54
//
