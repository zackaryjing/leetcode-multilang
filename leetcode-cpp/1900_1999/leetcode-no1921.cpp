// problem: https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
  public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    int n = dist.size();
    vector<int> cnt(n);
    for (int i = 0; i < dist.size(); ++i) {
      int temp = (dist[i] - 1) / speed[i];
      if (temp < n) {
        cnt[temp]++;
      }
    }
    int needkill = 0;
    for (int i = 0; i < n; ++i) {
      needkill += cnt[i];
      if (needkill > i + 1) {
        return i + 1;
      }
    }
    return n;
  }
};

class Solution2 {
  public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    auto out = views::zip(dist, speed) | views::transform([](auto &&p) {
                 auto [x, y] = p;
                 return static_cast<float>(x) / y;
               }) |
               ranges::to<vector<float>>();
    ranges::sort(out);
    int res = 0;
    for (int i = 0; i < out.size(); ++i) {
      if (out[i] > static_cast<float>(i))
        res++;
      else
        break;
    }
    return res;
  }
};

class Solution3 {
  public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    auto out = views::zip(dist, speed) | views::transform([](auto &&p) {
                 auto [x, y] = p;
                 return static_cast<float>(x) / y;
               }) |
               ranges::to<priority_queue<float, vector<float>, greater<float>>>();
    int res = 0, n = out.size();
    for (int i = 0; i < n; ++i) {
      if (out.top() > static_cast<float>(i)) {
        out.pop(), res++;
      } else
        break;
    }
    return res;
  }
};


int main(int argc, char *argv[]) {
  Solution3 test;
  cout << test.eliminateMaximum(temp_vector({1, 3, 4}), temp_vector({1, 1, 1})) << endl;
  cout << test.eliminateMaximum(temp_vector({1, 1, 2, 3}), temp_vector({1, 1, 1, 1})) << endl;
  cout << test.eliminateMaximum(temp_vector({3, 2, 4}), temp_vector({5, 3, 2})) << endl;
  cout << test.eliminateMaximum(temp_vector({3, 5, 7, 4, 5}), temp_vector({2, 3, 6, 3, 2})) << endl;
}

//
// Created By ASUS At 2026-02-13 23:26
//
