// problem: https://leetcode.cn/problems/rearrange-spaces-between-words/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <sstream>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int cnts = 0;
        bool isword = false;
        int wordcnt = 0;
        for (const char &c: text) {
            if (c == ' ') {
                cnts++;
                isword = false;
            } else {
                if (not isword) {
                    wordcnt++;
                }
                isword = true;
            }
        }
        istringstream ss;
        ss.str(text);
        string word;
        stringstream res;
        if (wordcnt <= 1) {
            ss >> word;
            return word + string(cnts,' ');
        }
        int divide = cnts / (wordcnt - 1);
        while (ss >> word) {
            res << word;
            if (cnts >= divide) {
                res << string(divide, ' ');
                cnts -= divide;
            }
        }
        if (cnts > 0) {
            res << string(cnts, ' ');
        }
        return res.str();
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.reorderSpaces("  this   is  a sentence ") << "|" << endl;
    cout << test.reorderSpaces("practice   makes   perfect   ") << "|" << endl;
    cout << test.reorderSpaces("a   ") << "|" << endl;
    cout << test.reorderSpaces(" ") << "|" << endl;
}

//
// Created By ASUS At 2026-04-15 14:33
//
