// problem: https://leetcode.cn/problems/reverse-prefix-of-word/
#include <iostream>
#include <vector>
using namespace std;

// time spent: 06:08
class Solution {

public:
    string reversePrefix(string word, char ch) {
        size_t pos = word.find(ch);
        if (pos != string::npos) {
            for (int i = 0; i + i < pos; ++i) {
                swap(word[i], word[pos - i]);
            }
        }
        return word;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.reversePrefix("abcdefd", 'd') << endl;
    cout << test.reversePrefix("xyxzxe", 'z') << endl;
    cout << test.reversePrefix("abcd", 'z') << endl;
}

//
// Created By Zackary At 2025-05-29 17:19:07
//
