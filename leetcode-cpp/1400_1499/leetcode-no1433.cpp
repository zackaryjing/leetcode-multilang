#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        ranges::sort(s1);
        ranges::sort(s2);
        const size_t n = s1.size();
        bool has_direction = false;
        bool direction = true;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (has_direction) {
                if (s1[i] == s2[i]) {
                    continue;
                }
                if (s1[i] > s2[i]) {
                    if (not direction) {
                        valid = false;
                    }
                } else {
                    if (direction) {
                        valid = false;
                    }
                }
            } else {
                if (s1[i] != s2[i]) {
                    direction = s1[i] > s2[i];
                    has_direction = true;
                }
            }
        }
        return valid;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.checkIfCanBreak("abc","xya") << endl;
    cout << test.checkIfCanBreak("abe","xya") << endl;
    cout << test.checkIfCanBreak("leetcodee","interview") << endl;
    cout << test.checkIfCanBreak("axy","def") << endl;
}


//
// Created by ASUS on 2025/2/22.
//
