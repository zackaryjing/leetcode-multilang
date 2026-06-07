// problem:  https://leetcode.cn/problems/find-if-array-can-be-sorted/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    bool canSortArray(vector<int> &nums) {
        auto copy = nums;
        ranges::sort(copy);
        int n = nums.size();
        unordered_set<int> group;
        unordered_set<int> target;
        int index = 0;
        while (index < n) {
            int cnt = popcount((unsigned) nums[index]);
            group.insert(nums[index]);
            target.insert(copy[index]);
            while (index + 1 < n and popcount((unsigned) nums[index + 1]) == cnt) {
                group.insert(nums[index + 1]);
                target.insert(copy[index + 1]);
                index++;
            }
            if (group != target) {
                return false;
            }
            group.clear();
            target.clear();
            index++;
        }
        return true;
    }
};


class Solution3 {
public:
    bool canSortArray(vector<int> &nums) {
        auto copy = nums;
        ranges::sort(copy);
        int n = nums.size();
        int index = 0;
        bitset<257> target;
        bitset<257> group;
        while (index < n) {
            int cnt = popcount((unsigned) nums[index]);
            target.set(copy[index]);
            group.set(nums[index]);
            while (index + 1 < n and popcount((unsigned) nums[index + 1]) == cnt) {
                group.set(nums[index + 1]);
                target.set(copy[index + 1]);
                index++;
            }
            if (group != target) {
                return false;
            }
            index++;
        }
        return true;
    }
};



class Solution {
public:
    bool canSortArray(vector<int> &nums) {
        auto copy = nums;
        int n = nums.size();
        int index = 0;
        int lastMax = 0;
        while (index < n) {
            int cnt = popcount((unsigned) nums[index]);
            if (nums[index] < lastMax) return false;
            int curMax = nums[index];
            while (index + 1 < n and popcount((unsigned) nums[index + 1]) == cnt) {
                if (nums[index + 1] < lastMax) return false;
                curMax=  max(curMax,nums[index + 1]);
                index++;
            }
            lastMax = curMax;
            index++;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canSortArray(temp_vector({8, 4, 2, 30, 15})) << endl;
    cout << test.canSortArray(temp_vector({75, 34, 30})) << endl;
}

//
// Created By jing At 2026-06-02 20:21
//
