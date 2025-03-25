// problem: check-if-a-parentheses-string-can-be-valid
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        int cur = 0;
        int available = 0;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == ')') {
                    available--;
                    if (available < 0) {
                        valid = false;
                        break;
                    }
                } else if (s[i] == '(') {
                    available++;
                }
            } else {
                available++;
            }
        }
        if (available % 2) {
            return false;
        }
        available = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    available--;
                    if (available < 0) {
                        valid = false;
                        break;
                    }
                } else if (s[i] == ')') {
                    available++;
                }
            } else {
                available++;
            }
        }
        if (available % 2) {
            return false;
        }
        return valid;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canBeValid("))()))", "010100") << endl;
    cout << test.canBeValid("()()", "0000") << endl;
    cout << test.canBeValid(")", "0") << endl;
    cout << test.canBeValid("(((())(((())", "111111010111") << endl;
}


//
// Created by ASUS on 2025/3/23.
//
