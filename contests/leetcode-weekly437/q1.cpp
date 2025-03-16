#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        if (s.size() < k) return false;
        char cur = s[0];
        const int n = s.size();
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == cur) {
                len++;
            } else {
                if (len == k) {
                    return true;
                }
                cur = s[i];
                len = 1;
            }
        }
        if (len == k) {
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.hasSpecialSubstring("aaabaaa",3) << endl;;
    cout << test.hasSpecialSubstring("caabraa",3) << endl;;
    cout << test.hasSpecialSubstring("caabaaa",3) << endl;;
    cout << test.hasSpecialSubstring("abc",2) << endl;;
}


//
// Created by ASUS on 2025/2/16.
//
