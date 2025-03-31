// problem:
// https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/description/?envType=daily-question&envId=2025-03-27
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        int left = 0;
        int right = s.size() - 1;
        int nx_left = left;
        int nx_right = right;
        int n = s.length();
        while (++nx_left < n and s[nx_left] == s[left]) {
        }
        while (--nx_right >= 0 and s[nx_right] == s[right]) {
        }
        long long ans = 0;
        while (nx_right >= left) {
            if (nx_left <= n - 1 - nx_right) {
                left = nx_left;
                ans += nx_left;
                while (++nx_left < n and s[nx_left] == s[left]) {
                }
            } else {
                right = nx_right;
                ans += n - 1 - nx_right;
                while (--nx_right >= 0 and s[nx_right] == s[right]) {
                }
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumCost("1100000111100010") << endl;
    cout << test.minimumCost("010101") << endl;
    cout << test.minimumCost("0011") << endl;
    cout << test.minimumCost("0") << endl;
}

//
// Created by ASUS on 2025/3/27.
//
