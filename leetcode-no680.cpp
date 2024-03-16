#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int length = s.length();
        int i = 0, j;
        while (i < length - i - 1 and s[i] == s[length - i - 1]) {
            i++;
        }
        if (i == length / 2) return true;
        j = i + 1;
        while (i < length - i - 2 and s[i] == s[length - i - 2]) {
            i++;
        }
        if (s[i] == s[length - i - 2]) return true;
        while (j < length - j and s[j] == s[length - j]) {
            j++;
        }
        if (s[j] == s[length - j]) return true;
        return false;
    }
};

int main() {
    Solution test;
    cout << test.validPalindrome("abba") << endl; // 1
    cout << test.validPalindrome("aba") << endl; // 1
    cout << test.validPalindrome("abca") << endl; // 1
    cout << test.validPalindrome("acba") << endl; // 1
    cout << test.validPalindrome("acb") << endl; // 0
    cout << test.validPalindrome("aaaaa") << endl; // 1
    cout << test.validPalindrome("aaaaaa") << endl; // 1
    cout << test.validPalindrome("a") << endl; // 1
    cout << test.validPalindrome("abcdedhcba") << endl; // 1
    cout << test.validPalindrome("abcddchba") << endl; // 1
    cout << test.validPalindrome("abfcddchba") << endl; // 0
    cout << test.validPalindrome("abfcdedchba") << endl; // 0
    cout << test.validPalindrome("abfcddcba") << endl; // 1
    cout << test.validPalindrome("abfcdedcba") << endl; // 1
}
//
// Created by ASUS on 2024/2/26.
//
