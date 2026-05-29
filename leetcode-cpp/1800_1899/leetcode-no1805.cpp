// problem:
// https://leetcode.cn/problems/number-of-different-integers-in-a-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> words;
        bool inword = false;
        string w = "";
        bool hasZero = false;
        bool realZero = false;
        for (const char c: word) {
            if (c == '0') {
                if (inword) {
                    w.push_back(c);
                } else {
                    hasZero = true;
                }
            } else if ('1' <= c and c <= '9') {
                hasZero = false;
                inword = true;
                w.push_back(c);
            } else {
                if (inword) {
                    words.insert(w);
                }
                if (hasZero) {
                    realZero = true;
                }
                inword = false;
                w.clear();
            }
        }
        if (inword) {
            words.insert(w);
        }
        if (hasZero) {
            realZero = true;
        }
        return words.size() + (int) realZero;
    }
};


class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> words;
        bool inword = false, hasZero = false, realZero = false;
        word.push_back('d');
        string w = "";
        for (const char c: word)
            if (c == '0')
                if (inword)
                    w.push_back(c);
                else
                    hasZero = true;
            else if ('1' <= c and c <= '9')
                hasZero = false, inword = true, w.push_back(c);
            else {
                if (inword) words.insert(w);
                if (hasZero) realZero = true;
                inword = false;
                w.clear();
            }
        return words.size() + static_cast<int>(realZero);
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numDifferentIntegers("a123bc34d8ef34") << endl;
}

//
// Created By jing At 2026-05-28 17:43
//
