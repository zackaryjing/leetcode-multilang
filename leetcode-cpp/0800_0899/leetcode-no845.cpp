// problem: https://leetcode.cn/problems/longest-mountain-in-array/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <deque>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution2 {
public:
    int longestMountain(vector<int> &arr) {
        const size_t n = arr.size();
        vector<int> lengthList(n);
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                lengthList[i] = lengthList[i - 1] + 1;
            } else {
                lengthList[i] = 0;
            }
        }
        int res = 0;
        int curLength = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                curLength++;
                if (curLength > 0 and lengthList[i] > 0) {
                    res = max(res, curLength + lengthList[i] + 1);
                }
            } else {
                curLength = 0;
            }
        }
        return res >= 3 ? res : 0;
    }
};


class Solution {
public:
    // much faster...
    int longestMountain(vector<int> &arr) {
        const size_t n = arr.size();
        int i = 1;
        int res = 0;
        while (i < n) {
            int starti = i;
            int up = 0;
            while (i < n and arr[i - 1] < arr[i]) {
                up++;
                i++;
            }
            int down = 0;
            while (i < n and arr[i - 1] > arr[i]) {
                down++;
                i++;
            }
            if (up > 0 and down > 0) {
                res = max(res, up + down + 1);
            }
            if (i == starti) {
                i++;
            }
        }
        return res >= 3 ? res : 0;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.longestMountain(temp_vector({9, 8, 7, 6, 5, 4, 3, 2, 1, 0})) << " e0" << endl;
    cout << test.longestMountain(temp_vector({0, 2, 0, 2, 1, 2, 3, 4, 4, 1})) << " e3" << endl;
    cout << test.longestMountain(temp_vector({2, 1, 4, 7, 3, 2, 5})) << " e5" << endl;
    cout << test.longestMountain(temp_vector({2, 2, 2})) << " e0" << endl;
    cout << test.longestMountain(temp_vector({2, 3})) << " e0" << endl;
    cout << test.longestMountain(temp_vector({3, 2})) << " e0" << endl;
    cout << test.longestMountain(temp_vector({1, 2, 3, 4, 5, 6, 7, 8, 9})) << " e0" << endl;
}

//
// Created By jing At 2025-10-25 21:44
//
