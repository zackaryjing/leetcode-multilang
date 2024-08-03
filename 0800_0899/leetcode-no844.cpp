#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s1 = (int)s.length() - 1;
        int s2 = (int)t.length() - 1;
        int s1_skip = 0, s2_skip = 0;
        while (true) {
            while (s1 >= 0 and (s[s1] == '#' or s1_skip != 0)) {
                if (s[s1] == '#') {
                    s1_skip++;
                } else {
                    s1_skip--;
                }
                s1--;
            }
            while (s2 >= 0 and (t[s2] == '#' or s2_skip != 0)) {
                if (t[s2] == '#') {
                    s2_skip++;
                } else {
                    s2_skip--;
                }
                s2--;
            }
            if (s1 == -1 and s2 == -1) {
                return true;
            } else if (s1 == -1 or s2 == -1) {
                return false;
            } else {
                if (s[s1] != t[s2]) {
                    return false;
                } else {
                    s1--;s2--;
                }
            }
        }
    }
};

int main() {
    Solution test;
    cout << test.backspaceCompare("ab#c","ad#c") << endl; // true
    cout << test.backspaceCompare("a#c","b") << endl; // false
    cout << test.backspaceCompare("#b","b") << endl; // true
    cout << test.backspaceCompare("###b","b") << endl; // true
    cout << test.backspaceCompare("asdfasdf####asdf","asdfasdasd###f") << endl; // true
    cout << test.backspaceCompare("asdfaiii###sdf####asdf","as90909#####dfasdasd###f") << endl; // true
}
//
// Created by ASUS on 2024/8/3.
//
