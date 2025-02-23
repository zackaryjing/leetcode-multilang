#include <cmath>
#include <iostream>
#include <vector>
#include <pstl/execution_defs.h>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        int n1 = num;
        vector<int> parts(10);
        int k = 0;
        int end_num;
        while (n1 > 0) {
            int cur = n1 % 10;
            if (cur != 0) {
                parts[cur] += cur * pow(10, k);
            } else {
                parts[cur] += pow(10, k);
            }
            n1 = n1 / 10;
            k++;
            end_num = cur;
        }
        int delta_neg = 0;
        for (int i = 1; i < 10; i++) {
            if (i != end_num) {
                delta_neg = max(delta_neg, parts[i]);
            } else {
                delta_neg = max(delta_neg, static_cast<int>(parts[i] * (1.0 - 1.0 / i)));
            }
        }

        int delta_pos = 9 * parts[0];
        for (int i = 1; i < 10; i++) {
            delta_pos = max(delta_pos, static_cast<int>((9.0 / i - 1.0) * parts[i]));
        }

        // cout << delta_neg << " " << delta_pos << endl;
        // for (auto k: parts) {
        //     cout << k << " ";
        // }
        // cout << endl;

        return delta_neg + delta_pos;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxDiff(4249) << endl;
    cout << test.maxDiff(5555) << endl;
}


//
// Created by ASUS on 2025/2/22.
//
