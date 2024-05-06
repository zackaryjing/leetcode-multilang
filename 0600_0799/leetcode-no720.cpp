#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    static bool compareStrings(const string &str1, const string &str2) {
        if (str1.size() == str2.size()) {
            return str1 < str2;
        }
        return str1.length() < str2.length();
    }

    string longestWord(vector<string> &words) {
        if (words.empty()) return "";
        sort(words.begin(), words.end(), compareStrings);
        set<string, decltype(compareStrings) *> within(compareStrings);
        set<string, decltype(compareStrings) *> cur(compareStrings);
        auto b_length = words[0].length();
        for (auto& word: words) {
            auto n = word.size();
            if (n > b_length) {
                if (cur.empty()) {
                    break;
                }
                within = cur;
                cur.clear();
                b_length = n;
            }
            if (n == 1) {
                cur.insert(word);
            } else {
                if (within.find(word.substr(0, n - 1)) != within.end()) {
                    cur.insert(word);
                }
            }
        }
        if (!cur.empty()) {
            within = cur;
        }
        if (within.empty()) { return ""; }
        string ans = *within.rbegin();
        auto l_length = within.rbegin()->length();
        for (auto k = within.rbegin(); k != within.rend(); k++) {
            if (k->length() == l_length) {
                ans = *k;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    struct Trie {
        string val;
        vector<Trie> child;

        Trie() {
            child.resize(26);
        }
    };

    string longestWord(vector<string> &words) {

    }
};

int main() {
    Solution test;
    vector<string> words1 = {"w", "wo", "wor", "worl", "world"};
    cout << test.longestWord(words1) << endl;
    vector<string> words2 = {"b", "br", "bre", "brea", "break", "breakf", "breakfa", "breakfas", "breakfast", "l", "lu",
                             "lun", "lunc", "lunch", "d", "di", "din", "dinn", "dinne", "dinner"};
    cout << test.longestWord(words2) << endl;
    vector<string> words3 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << test.longestWord(words3) << endl;
    vector<string> words4 = {"wo", "wor", "worl", "world"};
    cout << test.longestWord(words4) << endl;
}

//
// Created by ASUS on 2023/7/16.
//
