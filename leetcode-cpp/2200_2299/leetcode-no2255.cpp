// problem: count-prefixes-of-a-given-string
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string> &words, string s) {
        return count_if(words, [&s](string &word) {
            return s.starts_with(word);
        };
    }
};


class Solution2 {
public:
    int countPrefixes(vector<string> &words, string s) {
        int n = s.size();
        int ans = 0;
        for (auto word: words) {
            if (word.size() > n) {
                continue;
            }
            bool valid = true;
            int i = 0;
            for (auto ch: word) {
                if (i < n and ch != s[i]) {
                    valid = false;
                    break;
                }
                i++;
            }
            if (valid) {
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<string> words = {"a", "b", "c", "ab", "bc", "abc"};
    string s = "abc";
    cout << test.countPrefixes(words, s) << endl;
    words = {"a", "a"};
    s = "aa";
    cout << test.countPrefixes(words, s) << endl;
}


//
// Created by ASUS on 2025/3/24.
//
