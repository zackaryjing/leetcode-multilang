// problem:  https://leetcode.cn/problems/reformat-phone-number/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    string reformatNumber(string number) {
        string res;
        int dcnt = 0, curCnt = 0;
        for (const auto &c: number) dcnt += isdigit(c) ? 1 : 0;
        if ((dcnt % 3) == 1) {
            for (const auto &c: number) {
                if (isdigit(c)) {
                    if (curCnt > 0 and ((dcnt > 4 and curCnt % 3 == 0) or dcnt == 4 or dcnt == 2)) {
                        res.push_back('-');
                    }
                    res.push_back(c);
                    curCnt++;
                    dcnt--;
                }
            }
        } else {
            for (const auto &c: number) {
                if (isdigit(c)) {
                    if (curCnt > 0 and curCnt % 3 == 0) {
                        res.push_back('-');
                    }
                    res.push_back(c);
                    curCnt++;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    string reformatNumber(string number) {
        string res;
        int dcnt = 0, curCnt = 0;
        for (const auto &c: number) dcnt += isdigit(c) ? 1 : 0;
        int ccnt = dcnt;
        for (const auto &c: number) {
            if (isdigit(c)) {
                if (curCnt > 0 and ((ccnt % 3 != 1 and curCnt % 3 == 0) or
                                    (ccnt % 3 == 1 and ((dcnt > 4 and curCnt % 3 == 0) or dcnt == 4 or dcnt == 2)))) {
                    res.push_back('-');
                }
                res.push_back(c);
                curCnt++;
                dcnt--;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.reformatNumber("1-23-45 6") << endl;
    cout << test.reformatNumber("123 4-567") << endl;
    cout << test.reformatNumber("123 4-5678") << endl;
    cout << test.reformatNumber("9964-") << endl;
    cout << test.reformatNumber("123 4-567") << endl;
}

//
// Created By jing At 2026-06-04 14:48
//
