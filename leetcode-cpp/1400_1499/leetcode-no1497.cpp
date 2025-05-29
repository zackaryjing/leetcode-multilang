// problem: https://leetcode.cn/problems/check-if-array-pairs-are-divisible-by-k/
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;


// time spent 27:13
class Solution {
public:
    // [Pass] can do better.
    bool canArrange(vector<int> &arr, int k) {
        vector<int> cnts(k);
        for (auto t: arr) {
            cnts[(t % k + k) % k]++;
        }
        for (int j = 1; j<= k / 2; ++j) {
            if (cnts[j] != cnts[k - j]) {
                return false;
            }
        }
        return not (cnts[0] & 1);
    }
};

class Solution2 {
public:
    // [Pass] can do better.
    bool canArrange(vector<int> &arr, int k) {
        int temp = 1000000000;
        int base = ((temp / k) + 1) * k;
        int n = static_cast<int>(arr.size());
        if (n & 1) {
            return false;
        }
        vector<int> cnts(k);
        for (auto t: arr) {
            cnts[(t + base) % k]++;
        }
        if (cnts[0] & 1 or (not k & 1 and cnts[k / 2] & 1)) {
            return false;
        }
        for (int j = 1; j <= k / 2; ++j) {
            if (cnts[j] != cnts[k - j]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canArrange(temp_vector<int>({1, 2, 3, 4, 5, 10, 6, 7, 8, 9}), 5) << endl;
    cout << test.canArrange(temp_vector<int>({1, 2, 3, 4, 5, 6}), 7) << endl;
    cout << test.canArrange(temp_vector<int>({1, 2, 3, 4, 5, 6}), 10) << endl;
    cout << test.canArrange(temp_vector<int>({-1, 1, -2, 2, -3, 3, -4, 4}), 3) << endl;
    cout << test.canArrange(temp_vector<int>({-1, -1, -1, -1, 2, 2, -2, -2}), 3) << endl;
    cout << "" << endl;
}

//
// Created By Zackary At 2025-05-28 16:53:54
//
