// problem: https://leetcode.cn/problems/find-the-lexicographically-largest-string-from-the-box-i/?envType=daily-question&envId=2025-06-04
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string_view wordv = string_view(word);
        string_view res = wordv.substr(0, n - (numFriends - 1));
        if (numFriends > 1) {
            for (int i = 1; i < n; ++i) {
                string_view nxt = wordv.substr(i, n - (numFriends - 1));
                if (nxt > res) {
                    res = nxt;
                }
            }
        }
        return string(res);

    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.answerString("dbca", 2) << endl;
    cout << test.answerString("gggg", 4) << endl;
    cout << test.answerString("gh", 1) << endl;
    cout << test.answerString("aann", 2) << endl;
}

//
// Created By Zackary At 2025-06-04 13:02:17
//
