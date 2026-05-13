// problem: https://leetcode.cn/problems/longest-string-chain/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <c++/14/unordered_map>
#include <iostream>
#include <map>
#include <ranges>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int longestStrChain(vector<string> &words) {
        map<int, vector<int>> dict;
        for (int i = 0; i < words.size(); ++i) dict[words[i].size()].push_back(i);
        const auto check = [&](const string &a, const string &b, int n) -> bool {
            for (int i1 = 0, i2 = 0, diff = 0; i1 < n; ++i1, ++i2)
                if (a[i1] != b[i2] and (diff++ or a[i1] != b[++i2])) return false;
            return true;
        };
        unordered_map<int, int> len;
        int res = 1;
        for (const auto &[k, v]: dict)
            for (int w1: v)
                for (int w2: dict[k + 1])
                    if (check(words[w1], words[w2], k))
                        len[w2] = max(len.contains(w1) ? len[w1] + 1 : 2, len[w2]), res = max(len[w2], res);
        return res;
    }
};


class Solution2 {
public:
    int longestStrChain(vector<string> &words) {
        map<int, vector<int>> dict;
        for (int i = 0; i < words.size(); ++i) {
            dict[words[i].size()].push_back(i);
        }
        unordered_map<int, vector<int>> graph;
        const auto check = [&](int w1, int w2, int n) -> bool {
            int i1 = 0, i2 = 0;
            bool diff = false;
            string &a = words[w1], &b = words[w2];
            for (int i = 0; i < n; ++i) {
                if (a[i1] != b[i2]) {
                    if (diff) return false;
                    i2++;
                    if (a[i1] != b[i2]) return false;
                    diff = true;
                }
                i1++, i2++;
            }
            return true;
        };
        unordered_map<int, int> len;
        int res = 1;
        for (const auto &[k, v]: dict) {
            for (int w1: v) {
                for (int w2: dict[k + 1]) {
                    if (check(w1, w2, k)) {
                        if (len.contains(w1)) {
                            len[w2] = max(len[w1] + 1, len[w2]);
                        } else {
                            len[w2] = max(2, len[w2]);
                        }
                        res = max(len[w2], res);
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.longestStrChain(temp_vector({"a", "b", "ba", "bca", "bda", "bdca"})) << endl;
    cout << test.longestStrChain(temp_vector({"a", "b", "ab", "bac"})) << endl;
    cout << test.longestStrChain(temp_vector({"a", "ab", "ac", "bd", "abc", "abd", "abdd"})) << endl;
}

//
// Created By jing At 2026-05-13 02:54
//
