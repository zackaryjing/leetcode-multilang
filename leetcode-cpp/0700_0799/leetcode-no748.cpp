#include <regex>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        map<char, int> times;
        int minimal_length = 0;
        for (auto ch: licensePlate) {
            if (std::isalpha(ch)) {
                times[std::tolower(ch)]++;
                minimal_length++;
            }
        }
        int min_length = 100;
        string ans;
        bool valid = true;
        for (auto word: words) {
            int len = word.length();
            if (len >= min_length or len < minimal_length) {
                continue;
            }
            valid = true;
            map<char, int> wd_times;
            for (auto ch: word) {
                wd_times[ch]++;
            }
            for (auto [key,val]: times) {
                if (wd_times[key] < val) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans = word;
                min_length = word.length();
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        map<char, int> cnts;
        for (auto k: licensePlate) {
            if (std::isalpha(k)) {
                cnts[tolower(k)]++;
            }
        }
        string basic_string = "";
        for (auto [key,val]: cnts) {
            basic_string += "(?=(?:.*" + string(1, key) + "){" + to_string(val) + ",})";
        }
        // cout << basic_string << endl;

        regex pattern(basic_string);
        int min_length = 100;
        string ans;
        for (const auto &word: words) {
            // cout << word << endl;
            if (regex_search(word, pattern)) {
                if (word.length() < min_length) {
                    ans = word;
                    min_length = word.length();
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    string ans = test.shortestCompletingWord("1s3 PSt", *(new vector<string>({
                                                 "step", "steps", "stripe", "stepple"
                                             })));
    cout << ans << endl;
}

//
// Created by ASUS on 2024/7/17.
//
//
// Modified by ASUS on 2025/2/6.
//
