// problem: check-balanced-string
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int n = static_cast<int>(num.size());
        int even_sum = 0, odd_sum = 0;
        for (int i = 0; i < n; i += 2) {
            even_sum += num[i] - '0';
        }
        for (int i = 1; i < n; i += 2) {
            odd_sum += num[i] - '0';
        }
        return even_sum == odd_sum;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isBalanced("24123") << endl;
    cout << test.isBalanced("1234") << endl;
}


//
// Created by ASUS on 2025/3/14.
//
