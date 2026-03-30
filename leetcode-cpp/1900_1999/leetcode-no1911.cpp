// problem: https://leetcode.cn/problems/maximum-alternating-subsequence-sum/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
  public:
  long long maxAlternatingSum(vector<int> &nums) {
    long long even = 0, odd = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      even = max(odd - nums[i], even);
      odd = max(even + nums[i], odd);
    }
    return max(even, odd);
  }
};

int main(int argc, char *argv[]) {
  Solution test;
  cout << test.maxAlternatingSum(temp_vector({4, 2, 5, 3})) << endl;
  cout << test.maxAlternatingSum(temp_vector({5, 6, 7, 8})) << endl;
  cout << test.maxAlternatingSum(temp_vector({6, 2, 1, 2, 4, 5})) << endl;
}

//
// Created By ASUS At 2026-02-13 23:11
//
