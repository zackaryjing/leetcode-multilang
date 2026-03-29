// problem: https://leetcode.cn/problems/minimum-number-of-people-to-teach/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <climits>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {
        int m = languages.size();
        vector canSpeak = {bitset<512>()};
        canSpeak.reserve(m);
        for (int i = 0; i < m; ++i) {
            auto abaility = bitset<512>();
            for (auto l: languages[i]) {
                abaility.set(l);
            }
            canSpeak.push_back(abaility);
        }

        auto res = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            int cur = 0;
            auto mask = bitset<512>();
            for (auto friends: friendships) {
                if (not(canSpeak[friends[0]] & canSpeak[friends[1]]).any()) {
                    cur += (not canSpeak[friends[0]][i] and not mask[friends[0]]) +
                           (not canSpeak[friends[1]][i] and not mask[friends[1]]);
                    mask.set(friends[0]);
                    mask.set(friends[1]);
                }
            }
            res = min(res, cur);
        }
        return res;
    }
};


class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {
        int m = languages.size();
        vector canSpeak = {bitset<512>()};
        canSpeak.reserve(m);
        for (int i = 0; i < m; ++i) {
            auto abaility = bitset<512>();
            for (auto l: languages[i]) {
                abaility.set(l);
            }
            canSpeak.push_back(abaility);
        }

        vector<int> times(512);
        int cnt = 0;
        bitset<512> mask;
        for (int i = 0; i < friendships.size(); ++i) {
            if (auto friends = friendships[i]; not(canSpeak[friends[0]] & canSpeak[friends[1]]).any()) {
                if (not mask[friends[0]]) {
                    for (auto l: languages[friends[0] - 1])
                        times[l]++;
                    cnt++;
                    mask.set(friends[0]);
                }
                if (not mask[friends[1]]) {
                    for (auto l: languages[friends[1] - 1])
                        times[l]++;
                    cnt++;
                    mask.set(friends[1]);
                }
            }
        }
        auto res = INT_MAX;
        for (const auto time: times) {
            res = min(res, cnt - time);
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumTeachings(2, temp_vector({{1}, {2}, {1, 2}}), temp_vector({{1, 2}, {1, 3}, {2, 3}})) << endl;
    cout << test.minimumTeachings(3, temp_vector({{2}, {1, 3}, {1, 2}, {3}}),
                                  temp_vector({{1, 4}, {1, 2}, {3, 4}, {2, 3}}))
         << endl;
}

//
// Created By jing At 2025-12-26 23:44
//
