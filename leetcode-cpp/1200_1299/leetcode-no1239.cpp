// problem:
// https://leetcode.cn/problems/maximum-length-of-a-concatenated-string-with-unique-characters/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxLength(vector<string> &arr) {
        int n = arr.size();
        vector<int> chrs, sizes;
        chrs.reserve(n);
        sizes.reserve(n);
        for (auto &s: arr) {
            int mark = 0;
            bool valid = true;
            for (char c: s) {
                int dist = c - 'a';
                if (mark & (1 << dist)) {
                    valid = false;
                    break;
                }
                mark |= 1 << dist;
            }
            if (valid) {
                chrs.push_back(mark);
                sizes.push_back(s.size());
            }
        }
        int m = chrs.size();
        int mx = 0;
        const auto dfs = [&](this auto &&dfs, int cur, int pos, int size) -> void {
            mx = max(mx, size);
            if (pos < m) {
                if (not(cur & chrs[pos])) {
                    dfs(cur | chrs[pos], pos + 1, size + sizes[pos]);
                }
                dfs(cur, pos + 1, size);
            }
        };
        dfs(0, 0, 0);
        return mx;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxLength(temp_vector({"un", "iq", "ue"})) << endl;
    cout << test.maxLength(temp_vector({"aa", "bb"})) << endl;
    cout << test.maxLength(temp_vector(
            {"ab", "ba", "cd", "dc", "ef", "fe", "gh", "hg", "ij", "ji", "kl", "lk", "mn", "nm", "op", "po"}))
         << endl;
}

//
// Created By jing At 2026-06-03 18:55
//
