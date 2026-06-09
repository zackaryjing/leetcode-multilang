// problem:
// https://leetcode.cn/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <c++/15/unordered_set>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> ss;
        const int n = s.size();
        int res = 0;
        [&](this auto&& dfs, int pos, int cnts) -> void {
            if (pos == n) res = max(res, cnts);
            string cur;
            for (int i = pos; i < n; ++i) {
                const char c = s[i];
                cur.push_back(c);
                if (not ss.contains(cur)) {
                    ss.insert(cur);
                    dfs(i + 1, cnts + 1);
                    ss.erase(cur);
                }
            }
        }(0, 0);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxUniqueSplit("ababccc") << endl;
    cout << test.maxUniqueSplit("aba") << endl;
    cout << test.maxUniqueSplit("aa") << endl;
}

//
// Created By jing At 2026-06-09 22:25
//
