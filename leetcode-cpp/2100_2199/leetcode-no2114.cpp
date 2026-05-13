// problem:
// https://leetcode.cn/problems/maximum-number-of-words-found-in-sentences/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string> &sentences) {
        int res = 0;
        for (auto sentence: sentences) {
            int temp = 1;
            for (char c: sentence) {
                if (c == ' ') {
                    temp++;
                }
            }
            res = max(res, temp);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.mostWordsFound(
            temp_vector({"alice and bob love leetcode", "i think so too", "this is great thanks very much"}))
         << endl;
}

//
// Created By jing At 2026-05-13 17:58
//
