// problem: longest-common-prefix-of-k-strings-after-removal
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <bits/ranges_algo.h>
#include "../utils/vector_helper.h"


using namespace std;


class Solution {
    // 开始借鉴
public:
    int calc_lcp(string &s, string &t) {
        int len = min(s.size(), t.size());
        for (int i = 0; i < len; i++) {
            if (s[i] != t[i]) {
                return i;
            }
        }
        return len;
    }

    vector<int> longestCommonPrefix(vector<string> &words, int k) {
        int n = words.size();
        if (k >= n) {
            return vector<int>(n);
        }
        vector<int> idx(n);
        ranges::iota(idx, 0);
        ranges::sort(idx, {}, [&](int i) {
            return words[i];
        });
        int mx = -1, mx2 = -1, mx_i = -1;
        for (int i = 0; i <= n - k; i++) {
            int lcp = calc_lcp(words[idx[i]], words[idx[i + k - 1]]);
            if (lcp > mx) {
                mx2 = mx;
                mx = lcp;
                mx_i = i;
            } else if (lcp > mx2) {
                mx2 = lcp;
            }
        }
        vector<int> ans(n, mx);
        for (int i: ranges::subrange(idx.begin() + mx_i, idx.begin() + mx_i + k)) {
            ans[i] = mx2;
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    // vector<string> eg1 = {"abc", "abc", "abe", "def", "deh", "dgk", "fij"};
    // show_vector(test.longestCommonPrefix(eg1, 2));
    vector<string> eg2 = {"jump", "run", "run", "jump", "run"};
    show_vector(test.longestCommonPrefix(eg2, 2));
    // vector<string> eg3 = {"ccd","adc","dba","bff","cbfae","fcae","cbbc"};
    // show_vector(test.longestCommonPrefix(eg3, 3));
}

class Solution2 {
    // 效率不行（内存占用高），卡在了最后一个用例
public:
    vector<string> _words;
    int _k;
    unordered_map<string, int> prefix_cnts;

    void add_prefix(int left, int right, int level) {
        int i = left;
        // cout << "l: " << left << " , r: " << right << " , l: " << level << endl;
        while (i <= right) {
            char ch = _words[i][level];
            int times = 0;
            int start_index = i;
            bool start_index_not_found = true;
            while (i <= right and _words[i][level] == ch) {
                if (start_index_not_found and _words[i].length() - 1 > level) {
                    start_index = i;
                    start_index_not_found = false;
                }
                times++;
                i++;
            }

            if (times >= _k) {
                prefix_cnts[_words[i - 1].substr(0, level + 1)] = times;
            }

            if (not start_index_not_found) {
                add_prefix(start_index, i - 1, level + 1);
            }
        }
    }

    vector<int> longestCommonPrefix(vector<string> &words, int k) {
        _words = words;
        _k = k;
        ranges::sort(_words);
        int n = words.size();

        // show_vector(_words);

        add_prefix(0, n - 1, 0);
        vector<pair<string, int>> prefix_data(prefix_cnts.begin(), prefix_cnts.end());
        ranges::sort(prefix_data, [](const pair<string, int> &a, const pair<string, int> &b)-> bool {
            return a.first.size() != b.first.size() ? a.first.size() < b.first.size() : a.second < b.second;
        });

        // for (auto &[k,v]: prefix_data) {
        //     cout << k << ", " << v << endl;
        // }

        vector<int> res;
        for (const auto &word: words) {
            int cur = static_cast<int>(prefix_data.size()) - 1;
            bool found = false;
            while (cur >= 0) {
                bool same_prefix = word.starts_with(prefix_data[cur].first);
                if (same_prefix and prefix_data[cur].second - 1 >= k) {
                    res.push_back(static_cast<int>(prefix_data[cur].first.size()));
                    found = true;
                    break;
                }
                // cout << same_prefix << ", " << prefix_data[cur].first << ", " << prefix_data[cur].second << endl;
                if (not same_prefix and prefix_data[cur].second >= k) {
                    res.push_back(static_cast<int>(prefix_data[cur].first.size()));
                    found = true;
                    break;
                }
                cur--;
            }
            if (not found) {
                res.push_back(0);
            }
        }
        return res;
    }
};


//
// Created by ASUS on 2025/3/15.
//
