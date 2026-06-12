// problem: https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Tire {
public:
    vector<Tire *> child;
    int cnt = 0;
    Tire() {
        child.resize(26);
    }
};

class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = t.size();
        auto rt = new Tire();
        for (int i = 0; i < n; ++i) {
            auto cur = rt;
            for (int j = i; j < n; ++j) {
                int pos = t[j] - 'a';
                if (not cur->child[pos]) {
                    cur->child[pos] = new Tire();
                }
                cur = cur->child[pos];
                cur->cnt++;
            }
        }
        int m = s.size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                for (int k = i; k <= j; ++k) {
                    Tire *cur = rt;
                    for (int f = i; f < k; ++f) {
                        if (cur) cur = cur->child[s[f] - 'a'];
                       else {
                            break;
                        }
                    }
                    if (not cur) break;
                    vector<Tire *> all = cur->child;
                    all[s[k] - 'a'] = nullptr;
                    for (int f = k + 1; f <= j; ++f) {
                        for (int c = 0; c < 26; ++c) {
                            if (all[c]) {
                                all[c] = all[c]->child[s[f] - 'a'];
                            }
                        }
                    }
                    for (int c = 0; c < 26; ++c) {
                        if (all[c]) res += all[c]->cnt;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countSubstrings("aba", "baba") << " E: 6" << endl;
}

//
// Created By jing At 2026-06-12 17:10
//
