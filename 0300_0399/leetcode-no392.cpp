#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cur = 0;
        for (auto s_i: s) {
            while (t[cur] != s_i and cur < t.length()) cur++;
            if (cur == t.length()) {
                return false;
            }
            cur++;
        }
        return true;
    }
};

int main() {
    Solution test;
    cout << test.isSubsequence("abc","ahbgdc") << endl;
    cout << test.isSubsequence("axc","ahbgdc") << endl;
    cout << test.isSubsequence("aaaaaa","bbaaaa") << endl;
}
//
// Created by ASUS on 2024/2/19.
//
