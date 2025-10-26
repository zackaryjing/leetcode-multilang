// problem: https://leetcode.cn/problems/valid-number/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if ((s[i] < '0' or s[i] > '9') and s[i] != 'e' and s[i] != 'E' and s[i] != '+' and s[i] != '-' and
                s[i] != '.') {
                return false;
            }
        }
        int dotCnt = 0;
        int dotPos = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '.') {
                dotPos = i;
                dotCnt++;
            }
        }
        if (dotCnt > 1) {
            return false;
        }
        int ePos = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'e' or s[i] == 'E') {
                if (ePos != -1) {
                    return false;
                } else {
                    ePos = i; // only one e is allowed
                }
            }
        }
        if (ePos > -1 and dotPos > ePos) {
            return false;
        }
        auto checkSign = [](string &num) {
            if (num.size() == 0) {
                return false;
            }
            int signCnt = 0;
            for (int i = 0; i < num.size(); i++) {
                if (num[i] == '-' or num[i] == '+') {
                    signCnt++;
                }
            }
            if (signCnt > 1) {
                return false;
            }
            if (signCnt == 1) {
                if (num[0] != '+' and num[0] != '-') {
                    return false;
                }
                if (num.size() <= 1) {
                    return false;
                }
            }
            return true;
        };
        string significand;
        string exponent;
        if (ePos != -1) {
            // 100.52e23
            significand = s.substr(0, ePos);
            exponent = s.substr(ePos + 1);
            if (not checkSign(exponent)) {
                return false;
            }
        } else {
            significand = s;
        }
        if (not checkSign(significand)) {
            return false;
        }
        if (significand.size() == 1) {
            if (significand == ".") {
                return false;
            }
        } else if (significand.size() == 2) {
            if (significand[0] == '-' or significand[0] == '+') {
                if (significand[1] == '.') {
                    return false;
                }
            }
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isNumber("0") << endl;
    cout << test.isNumber("0098") << endl;
    cout << test.isNumber("-0.1") << endl;
    cout << test.isNumber("+3.14") << endl;
    cout << test.isNumber("4.") << endl;
    cout << test.isNumber("-.9") << endl;
    cout << test.isNumber("2e10") << endl;
    cout << test.isNumber("-90E3") << endl;
    cout << test.isNumber("3e+7") << endl;
    cout << test.isNumber("+6e-1") << endl;
    cout << test.isNumber("53.5e93") << endl;
    cout << string(20, '-') << endl;
    cout << test.isNumber("abc") << endl;
    cout << test.isNumber("1a") << endl;
    cout << test.isNumber("1e") << endl;
    cout << test.isNumber("e3") << endl;
    cout << test.isNumber("99e2.5") << endl;
    cout << test.isNumber("--6") << endl;
    cout << test.isNumber("-+3") << endl;
    cout << test.isNumber("95a54e53") << endl;
    cout << test.isNumber(".") << endl;
    cout << test.isNumber("-.E3") << endl;
}

//
// Created By jing At 2025-10-26 11:01
//
