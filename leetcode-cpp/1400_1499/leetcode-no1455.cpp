// problem:
// https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto pos = sentence.find(searchWord);
        while (pos != 0 and pos < sentence.size() and sentence[pos - 1] != ' ') {
            pos = sentence.find(searchWord, pos + 1);
        }
        int res = 1;
        if (pos == string::npos) return -1;
        for (int i = 0; i < pos; ++i) {
            if (sentence[i] == ' ') {
                res += 1;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isPrefixOfWord("i love eating burger", "burg") << endl;
    cout << test.isPrefixOfWord("hellohello hellohellohello", "ell") << endl;
}

//
// Created By jing At 2026-05-27 19:50
//
