// problem: https://leetcode.cn/problems/maximum-score-words-formed-by-letters/
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;

// time spent: 1:25:59
class Solution {
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        auto dfs = [&](this auto &&dfs, int i, array<int, 26> left) -> int {
            if (i < 0)
                return 0;
            int res = dfs(i - 1, left);
            int s = 0;
            for (char c: words[i]) {
                if (left[c - 'a']-- == 0)
                    return res;
                s += score[c - 'a'];
            }
            return max(res, s + dfs(i - 1, left));
        };
        array<int, 26> left{};
        for (char c: letters)
            ++left[c - 'a'];
        return dfs(words.size() - 1, left);
    }
};


class Solution_2 {
public:
    // [Pass] Performance very bad.
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        vector<int> letterCnt(26);
        int n = static_cast<int>(words.size());
        vector wordLetterCnt(n, vector<int>(26));
        vector wordScore(n, 0);
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (auto ch: words[i]) {
                const int pos = ch - 'a';
                wordLetterCnt[i][pos]++;
                s += score[pos];
            }
            wordScore[i] = s;
        }
        for (auto l: letters) {
            letterCnt[l - 'a']++;
        }
        int curScore = 0;
        int res = 0;
        int status = 0;
        auto dfs = [&](this auto &&self)-> void {
            for (int i = 0; i < n; ++i) {
                if (status >> i & 1) {
                    continue;
                }
                const auto &wlc = wordLetterCnt[i];
                vector<int> nLetterCnt(26);
                bool valid = true;
                for (int j = 0; j < 26; ++j) {
                    if (letterCnt[j] >= wlc[j]) {
                        nLetterCnt[j] = letterCnt[j] - wlc[j];
                    } else {
                        valid = false;
                    }
                }
                if (valid) {
                    auto tempCnt = move(letterCnt);
                    letterCnt = move(nLetterCnt);
                    curScore += wordScore[i];
                    res = max(res, curScore);
                    status |= 1 << i;
                    self();
                    status &= ~(1 << i);
                    curScore -= wordScore[i];
                    letterCnt = move(tempCnt);
                }
            }
        };
        dfs();
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxScoreWords(temp_vector({"dog", "cat", "dad", "good"}),
                               temp_vector({'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'}),
                               temp_vector({1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                            0})) << endl;
    cout << test.maxScoreWords(temp_vector({"xxxz", "ax", "bx", "cx"}),
                               temp_vector({'z', 'a', 'b', 'c', 'x', 'x', 'x'}),
                               temp_vector({4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0,
                                            10})) << endl;
    cout << test.maxScoreWords(
            temp_vector({"add", "dda", "bb", "ba", "add"}), temp_vector(
                    {'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'd', 'd', 'd'}), temp_vector(
                    {3, 9, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) << endl;
}

//
// Created By Zackary At 2025-06-15 17:21:10
//
