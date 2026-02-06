// problem: https://leetcode.cn/problems/restore-the-array-from-adjacent-pairs/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution3 {
public:
    vector<int> restoreArray(vector<vector<int> > &adjacentPairs) {
        auto times = unordered_map<int, int>();
        auto pairs = unordered_map<int, pair<int, int> >();
        for (auto pair: adjacentPairs) {
            const int first = pair[0], second = pair[1];
            if (times[first]) pairs[first].second = second;
            else pairs[first].first = second;
            if (times[second]) pairs[second].second = first;
            else pairs[second].first = first;
            times[first]++;
            times[second]++;
        }
        int start = 0;
        for (auto [k,v]: times) {
            if (v == 1) {
                start = k;
                break;
            }
        }
        const int n = static_cast<int>(adjacentPairs.size()) + 1;
        auto res = vector<int>(n);
        auto cur = INT_MAX;
        pairs[cur] = {start, start};
        for (int i = 0; i < n; ++i) {
            const auto nxt = pairs[cur].first;
            res[i] = nxt;
            if (pairs[nxt].first == cur)
                pairs[nxt].first = pairs[nxt].second;
            cur = nxt;
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> restoreArray(vector<vector<int> > &adjacentPairs) {
        auto times = unordered_map<int, int>();
        auto pairs = unordered_map<int, pair<int, int> >();
        for (auto pair: adjacentPairs) {
            if (times[pair[0]]) {
                pairs[pair[0]].second = pair[1];
            } else {
                pairs[pair[0]].first = pair[1];
            }
            if (times[pair[1]]) {
                pairs[pair[1]].second = pair[0];
            } else {
                pairs[pair[1]].first = pair[0];
            }
            times[pair[0]]++;
            times[pair[1]]++;
        }
        int start = 0;
        for (auto [k,v]: times) {
            if (v == 1) {
                start = k;
                break;
            }
        }
        int n = static_cast<int>(adjacentPairs.size()) + 1;
        auto res = vector<int>(n);
        res[0] = start;
        auto cur = start;

        auto used = unordered_set<int>({start});
        for (int i = 1; i < n; ++i) {
            if (used.contains(pairs[cur].first)) {
                res[i] = pairs[cur].second;
            } else {
                res[i] = pairs[cur].first;
            }
            cur = res[i];
            used.insert(cur);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> restoreArray(vector<vector<int> > &adjacentPairs) {
        constexpr int size = 200000 + 2, offset = 100000;
        auto times = vector<unsigned char>(size);
        auto pairs = vector<pair<int, int> >(size);
        for (auto pair: adjacentPairs) {
            const int first = pair[0] + offset, second = pair[1] + offset;
            if (times[first]) pairs[first].second = second;
            else pairs[first].first = second;
            if (times[second]) pairs[second].second = first;
            else pairs[second].first = first;
            times[first]++;
            times[second]++;
        }
        int start = 0;
        for (int i = 0; i < size; ++i)
            if (times[i] == 1) {
                start = i;
                break;
            }
        const int n = static_cast<int>(adjacentPairs.size()) + 1;
        auto res = vector<int>(n);
        int cur = 200001;
        pairs[cur] = {start, start};
        for (int i = 0; i < n; ++i) {
            const auto nxt = pairs[cur].first;
            res[i] = nxt - offset;
            if (pairs[nxt].first == cur)
                pairs[nxt].first = pairs[nxt].second;
            cur = nxt;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    auto a = temp_vector<vector<int> >({{2, 1}, {3, 4}, {3, 2}});
    show_vector(test.restoreArray(temp_vector<vector<int> >({{2, 1}, {3, 4}, {3, 2}})));
    show_vector(test.restoreArray(temp_vector<vector<int> >({{4, -2}, {1, 4}, {-3, 1}})));
}

//
// Created By ASUS At 2026-02-06 14:24
//
