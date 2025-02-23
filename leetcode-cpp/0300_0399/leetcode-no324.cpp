#include <algorithm>
#include "../utils/vector_helper.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        for (int i = 0, j = (n - 1) / 2, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
        // show_vector(nums);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    test.wiggleSort(*make_unique<vector<int> >(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}));
    test.wiggleSort(*make_unique<vector<int> >(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}));
    test.wiggleSort(*make_unique<vector<int> >(vector<int>{1, 5, 1, 1, 6, 4}));
    test.wiggleSort(*make_unique<vector<int> >(vector<int>{1, 3, 2, 2, 3, 1}));
    test.wiggleSort(*make_unique<vector<int> >(vector<int>{2, 5, 5, 6}));
}


class Solution_mine {
    // 额，我一直在想是否存在不复制的交换方式，结论是太麻烦了，我想不出来 ，所以就老老实实的复制了。
public:
    void wiggleSort(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = (n + 1) / 2;
        int end = start * 2 - 1; // 不包含
        int times = end - start;
        for (int i = 0; i < times; i++) {
            swap(nums[i * 2 + 1], nums[start + i]);
        }
        show_vector(nums);
    }
};

//
// Created by ASUS on 2025/2/19.
//
