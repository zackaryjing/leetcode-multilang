// problem: https://leetcode.cn/problems/increasing-decreasing-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    string sortString(string s) {
        map<char, int> cnts;
        for (const auto c: s) {
            cnts[c]++;
        }
        int n = s.size();
        string res;
        res.reserve(n);
        while (not cnts.empty()) {
            for (auto it = cnts.begin(); it != cnts.end();) {
                res.push_back(it->first);
                if (--it->second != 0) {
                    it++;
                } else {
                    it = cnts.erase(it);
                }
            }
            for (auto it = cnts.end(); it != cnts.begin();) {
                --it;
                res.push_back(it->first);
                if (--it->second == 0) {
                    it = cnts.erase(it);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string sortString(string s) {
        vector<int> cnts(26);
        for (const auto c: s) {
            cnts[c - 'a']++;
        }
        int n = s.size();
        string res;
        res.reserve(n);
        while (res.size() < n) {
            for (int i = 0; i < 26; ++i) {
                if (cnts[i]-- > 0) {
                    res.push_back(i + 'a');
                }
            }
            for (int j = 25; j >= 0; --j) {
                if (cnts[j]-- > 0) {
                    res.push_back(j + 'a');
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string sortString(string s) {
        vector<pair<char, int>> cnts;
        ranges::sort(s);
        char cur = s[0];
        int cnt = 0;
        for (const auto c: s) {
            if (c == cur)
                cnt++;
            else {
                cnts.emplace_back(cur, cnt);
                cnt = 1;
                cur = c;
            }
        }
        cnts.emplace_back(cur, cnt);
        int n = s.size();
        string res;
        res.reserve(n);
        while (not cnts.empty()) {
            for (int i = 0; i < cnts.size(); ++i) {
                if (cnts[i].second-- > 0) {
                    res.push_back(cnts[i].first);
                }
            }
            for (int i = cnts.size() - 1; i >= 0; --i) {
                if (cnts[i].second-- > 0) {
                    res.push_back(cnts[i].first);
                }
                if (cnts[i].second <= 0) {
                    cnts.erase(cnts.begin() + i);
                }
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.sortString("rat") << endl;
    cout << test.sortString("aaaabbbbcccc") << endl;
}

//
// Created By jing At 2026-05-25 16:52
//
