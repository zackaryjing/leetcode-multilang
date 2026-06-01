// problem:
// https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool oneSeg = false;
        bool oneOccured = false;
        for (const char c: s) {
            if (c == '1') {
                oneOccured = true;
                if (oneSeg) {
                    return false;
                }
            } else {
                if (oneOccured) oneSeg = true;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.checkOnesSegment("1001") << endl;
    cout << test.checkOnesSegment("110") << endl;
}

//
// Created By jing At 18:47
//
