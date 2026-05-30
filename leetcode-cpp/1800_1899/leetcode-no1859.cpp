// problem: https://leetcode.cn/problems/sorting-the-sentence/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        istringstream ss(s);
        string word;
        unordered_map<int, string> data;
        int cnt = 0;
        while (ss >> word) {
            cnt++;
            int m = word.size();
            int pos = 0, end = 0;
            for (int i = 0, times = 1; i < m; ++i, times *= 10) {
                const char c = word[m - i - 1];
                if ('0' <= c and c <= '9')
                    pos += (c - '0') * times;
                else {
                    end = i;
                    break;
                }
            }
            data[pos] = word.substr(0, m - end);
        }
        string res;
        res.reserve(s.size());
        for (int i = 1; i <= cnt; ++i) {
            res.append(data[i]);
            if (i != cnt) {
                res.push_back(' ');
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.sortSentence("is2 sentence4 This1 a3") << endl;
}

//
// Created By jing At 2026-05-31 00:52
//
