// problem: https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/
#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups) {
        int n = words.size();
        vector<int> jump_vec(n);
        int last_index = -1;
        jump_vec[0] = -1;
        for (int i = 1; i < n; ++i) {
            const auto group = groups[i];
            if (group != groups[i - 1]) {
                jump_vec[i] = i - 1;
                last_index = i - 1;
            } else {
                jump_vec[i] = last_index;
            }
        }

        auto validate = [&](string &word1, string &word2)-> bool {
            int n1 = word1.size();
            int n2 = word2.size();
            if (n1 != n2) {
                return false;
            } else {
                bool diff_once = false;
                for (int j = 0; j < n1; ++j) {
                    if (word1[j] != word2[j]) {
                        if (diff_once) {
                            return false;
                        } else {
                            diff_once = true;
                        }
                    }
                }
                return true;
            }
        };

        vector<int> dp(n, 0);
        vector<int> from(n);
        int max_pos = 0;
        int max_val = -1;
        for (int i = 0; i < n; ++i) {
            auto rb = jump_vec[i];
            from[i] = -1;
            for (; rb >= 0; rb--) {
                if (not(not validate(words[i], words[rb]) or groups[i] == groups[rb])) {
                    if (dp[rb] + 1 > dp[i]) {
                        dp[i] = dp[rb] + 1;
                        from[i] = rb;
                    }
                }
            }
            if (dp[i] > max_val) {
                max_pos = i;
                max_val = dp[i];
            }
        }
        vector<string> res;
        res.reserve(max_val);
        while (true) {
            res.push_back(words[max_pos]);
            max_pos = from[max_pos];
            if (max_pos < 0) {
                break;
            }
        }
        ranges::reverse(res);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.getWordsInLongestSubsequence(temp_vector<string>({"bab", "dab", "cab"}),
                                                  temp_vector<int>({1, 2, 2})));

    show_vector(test.getWordsInLongestSubsequence(temp_vector<string>({"a", "b", "c", "d"}),
                                                  temp_vector<int>({1, 2, 3, 4})));
    show_vector(test.getWordsInLongestSubsequence(temp_vector<string>({"bab", "bdd", "bca", "dab"}),
                                                  temp_vector<int>({2, 4, 1, 2})));
    show_vector(test.getWordsInLongestSubsequence(
            temp_vector<string>({"cb", "dc", "ab", "aa", "ac", "bb", "ca", "bcc", "cdd", "aad", "bba", "bc", "ddb"}),
            temp_vector<int>({12, 6, 10, 11, 4, 8, 9, 11, 2, 11, 3, 2, 5})));
    cout << "" << endl;
}

//
// Created By Zackary At 2025-05-12 18:44:03
//
