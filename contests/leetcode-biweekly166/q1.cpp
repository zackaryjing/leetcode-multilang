// problem: https://leetcode.cn/problems/majority-frequency-characters/description/
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> cnt(26);
        for (auto ch: s) {
            cnt[ch - 'a']++;
        }
        unordered_map<int, int> groups;
        unordered_map<int, string> group_char;
        for (int i = 0; i < 26; ++i) {
            auto num = cnt[i];
            if (num != 0) {
                groups[num] += 1;
                group_char[num] += static_cast<char>(i + 'a');
            }
        }
        int max_k = -1;
        int res = -1;

        for (auto [k, v]: groups) {
            // cout << k << " : " << v << endl;
            if (v >= res) {
                if (v == res and k < max_k) {
                    continue;
                }
                res = v;
                max_k = k;
            }
        }

        // for (auto [k, v]: group_char) {
        //     cout << k << " : "  << v << endl;
        // }


        return group_char[max_k];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.majorityFrequencyGroup("pfpfgi") << endl;
    cout << test.majorityFrequencyGroup("aaabbbccdddde") << endl;
}

//
// Created By Zackary At 2025-09-27 23:23
//
