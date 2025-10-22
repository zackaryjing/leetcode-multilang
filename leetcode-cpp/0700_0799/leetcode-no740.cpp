// problem: https://leetcode.cn/problems/delete-and-earn/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        ranges::sort(nums);
        const int n = nums.size();
        int last = nums[0];
        vector<int> curList;
        int cur = 0;
        int res = 0;
        auto handleList = [&](const vector<int> &list) {
            const int m = list.size();
            int first = list[0];
            int second = first;
            if (m > 1) {
                second = max(list[1], first);
            }
            for (int j = 2; j < m; ++j) {
                int temp = second;
                second = max(first + list[j], second);
                first = temp;
            }
            return second;
        };
        for (int i = 0; i < n; ++i) {
            if (nums[i] == last) {
                cur += last;
            } else {
                curList.push_back(cur);
                if (nums[i] > last + 1) {
                    res += handleList(curList);
                    curList.clear();
                }
                cur = nums[i];
                last = cur;
            }
        }
        if (not curList.empty()) {
            curList.push_back(cur);
            res += handleList(curList);
        } else {
            res += cur;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.deleteAndEarn(temp_vector({3, 4, 2})) << endl;
    cout << test.deleteAndEarn(temp_vector({2, 2, 3, 3, 3, 4})) << endl;
    cout << test.deleteAndEarn(temp_vector({10, 8,  4,  2, 1, 3,  4, 8, 2,  9, 10, 4,  8, 5,  9,  1, 5, 1,  6, 8,  1,
                                            1,  6,  7,  8, 9, 1,  7, 6, 8,  4, 5,  4,  1, 5,  9,  8, 6, 10, 6, 4,  3,
                                            8,  4,  10, 8, 8, 10, 6, 4, 4,  4, 9,  6,  9, 10, 7,  1, 5, 3,  4, 4,  8,
                                            1,  1,  2,  1, 4, 1,  1, 4, 9,  4, 7,  1,  5, 1,  10, 3, 5, 10, 3, 10, 2,
                                            1,  10, 4,  1, 1, 4,  1, 2, 10, 9, 7,  10, 1, 2,  7,  5

            }))
         << endl;
}

//
// Created By jing At 2025-10-21 17:20
//
