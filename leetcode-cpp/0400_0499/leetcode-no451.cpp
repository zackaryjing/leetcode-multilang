// problem: https://leetcode.cn/problems/sort-characters-by-frequency/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <bits/ranges_algo.h>
#include <iostream>
#include <memory>
#include <ranges>
#include <vector>


using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128);
        for (auto ch: s) {
            freq[ch] += 1;
        }
        auto freqPairs = freq | views::enumerate |
                         views::transform([](auto p) { return pair<int, int>{get<1>(p), get<0>(p)}; }) |
                         ranges::to<vector<pair<int, int>>>();
        ranges::sort(freqPairs, [](const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first; });
        string res;
        for (auto [k, v]: freqPairs) {
            res += string(k, static_cast<char>(v));
        }
        return res;
    }
};


class Solution2 {
public:
    string frequencySort(string s) {
        vector<int> freq(128);
        for (auto ch: s) {
            freq[ch] += 1;
        }
        ranges::sort(s, [&](const char &a, const char &b) { return (freq[a] << 7) + a > (freq[b] << 7) + b; });
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.frequencySort("treebb") << endl;
    cout << test.frequencySort("cccaaa") << endl;
    cout << test.frequencySort("cacaca") << endl;
    cout << test.frequencySort("Aabb") << endl;
}

//
// Created By jing At 2025-10-23 20:45
//
