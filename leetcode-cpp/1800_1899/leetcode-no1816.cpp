// problem: https://leetcode.cn/problems/truncate-sentence/description/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                cnt++;
                if (cnt == k) {
                    s.resize(i);
                    break;
                }
            }
        }
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.truncateSentence("Hello how are you Contestant", 4) << endl;
}

//
// Created By ASUS At 2026-03-23 14:12
//
