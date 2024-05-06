#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution2 {
public:
    int removePalindromeSub(string s) {
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        if (s == tmp) return 1;
        return 2;
    }
};

class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        for (int j = 0;j < n/2;j++){
            if (s[j] != s[n - j - 1]) return 2;
        }
        return 1;
    }
};
int main(){
    Solution test;
    cout << test.removePalindromeSub("ababa") << endl;
    cout << test.removePalindromeSub("abb") << endl;
}
//
// Created by ASUS on 2023/7/16.
//
