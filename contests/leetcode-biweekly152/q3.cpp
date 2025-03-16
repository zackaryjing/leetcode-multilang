// problem: NAME
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <bits/ranges_algo.h>

using namespace std;


class Solution {
public:
    vector<string> _words;
    int _k;
    unordered_map<string, int> prefix_cnts;

    void add_prefix(int left, int right, int level) {
        int i = left;
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
        ranges::sort(words);
        int n = words.size();

        add_prefix(0, n - 1, 0);
        cout << 1 << endl;
        vector<pair<string, int> > prefix_data(prefix_cnts.begin(), prefix_cnts.end())
        ranges::sort(prefix_data, [](const pair<string, int> &a, const pair<string, int> &b)-> bool {
            return a.first.size() != b.first.size() ? a.first.size() < b.first.size() : a.second < b.second;
        });
        for (auto word : words) {
            
        }
        for (auto &[k,v]: prefix_cnts) {
            cout << k << ", " << v << endl;
        }

        return {};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<string> eg1 = {"abc", "abc", "abe", "def", "deh", "dgk", "fij"};
    test.longestCommonPrefix(eg1, 1);
}

//
// Created by ASUS on 2025/3/15.
//
