#include <iostream>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        size_t start = 0;
        size_t pos;
        pmr::unordered_set<string_view> s2_words;
        while ((pos = s2.find(' ', start)) != string::npos) {
            s2_words.emplace(s2.data() + start, pos - start);
            start = pos + 1;
        }
        s2_words.emplace(s2.data() + start, s2.size() - start);
        start = 0;
        cout << 2 << endl;
        vector<string> ans;
        while ((pos = s1.find(' ', start)) != string::npos) {
            if (not s2_words.erase(string_view(s1.data() + start, pos - start))) {
                ans.emplace_back(s1.substr(start, pos - start));
            }
            start = pos + 1;
        }
        if (not s2_words.erase(string_view(s1.data() + start, s1.size() - start))) {
            ans.emplace_back(s1.substr(start, s1.size() - start));
        }
        cout << 4 << endl;
        for (auto str: s2_words) {
            ans.emplace_back(str);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.uncommonFromSentences("this apple is sweet", "this apple is sour"));
}


//
// Created by ASUS on 2025/3/1.
//
