// problem: https://leetcode.cn/problems/number-of-valid-words-in-a-sentence/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <sstream>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        istringstream iss(sentence);
        string word;
        const auto check = [](string word) -> bool {
            int connect_cnt = 0, mark_cnt = 0, connect_pos = 0, mark_pos = 0;
            for (int i = 0; i < word.length(); ++i) {
                char c = word[i];
                if (isdigit(c)) return false;
                if (c == '-') {
                    connect_cnt++;
                    connect_pos = i;
                } else if (not isalpha(c)) {
                    mark_cnt++;
                    mark_pos = i;
                }
            }
            if ((connect_cnt >= 2 || mark_cnt >= 2) || (mark_cnt == 1 and mark_pos != word.size() - 1) ||
                (connect_cnt == 1 and ((connect_pos == 0 || connect_pos == word.size() - 1) ||
                                       (mark_cnt == 1 and connect_pos == word.size() - 2)))) {
                return false;
            }
            return true;
        };
        int res = 0;
        while (iss >> word) {
            if (check(word)) res++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countValidWords("cat and  dog") << endl;
}

//
// Created By jing At 2026-04-30 00:38
//
