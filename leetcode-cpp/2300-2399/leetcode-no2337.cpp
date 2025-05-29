// problem: https://leetcode.cn/problems/move-pieces-to-obtain-a-string/
#include <iostream>
#include <vector>
using namespace std;

// time spent : 31:35

class Solution {
public:
    bool canChange(string start, string target) {
        int base1 = 0, base2 = 0;
        int n = start.size();
        while (true) {
            while (base1 < n and start[base1] == '_') {
                base1++;
            }
            while (base2 < n and target[base2] == '_') {
                base2++;
            }
            if (base1 < n and base2 < n) {
                if (start[base1] != target[base2]) {
                    return false;
                }
                if (start[base1] == 'L') {
                    if (base1 < base2) {
                        return false;
                    }
                } else {
                    if (base1 > base2) {
                        return false;
                    }
                }
                base1++;
                base2++;
            } else if (not(base1 == n and base2 == n)) {
                return false;
            } else {
                break;
            }
        }
        return true;
    }
};


class Solution2 {
public:
    bool canChange(string start, string target) {
        int base1 = 0, base2 = 0;
        int n = start.size();
        while (true) {
            while (base1 < n and start[base1] == '_') {
                base1++;
            }
            while (base2 < n and target[base2] == '_') {
                base2++;
            }
            if (base1 < n and base2 < n) {
                if (start[base1] != target[base2]) {
                    return false;
                }
                base1++;
                base2++;
            } else if (not(base1 == n and base2 == n)) {
                return false;
            } else {
                break;
            }
        }
        int cur1 = 0, cur2 = 0;
        int cur3 = 0, cur4 = 0;
        for (int i = 0; i < n; ++i) {
            switch (start[i]) {
                case 'L':
                    cur1++;
                    break;
                case 'R':
                    cur3++;
                    break;
                default:
                    break;

            }
            switch (target[i]) {
                case 'L':
                    cur2++;
                    break;
                case 'R':
                    cur4++;
                    break;
                default:
                    break;
            }
            if (cur1 > cur2) {
                return false;
            }
            if (cur3 < cur4) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canChange("_L__R__R_", "L______RR") << endl;
    cout << test.canChange("R_L_", "__LR") << endl;
    cout << test.canChange("_R", "R_") << endl;
    cout << test.canChange("_R", "RL") << endl;
}

//
// Created By Zackary At 2025-05-28 22:52:57
//
