// problem: https://leetcode.cn/problems/decode-the-message/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> table(26, -1);
        int cur = 0;
        for (const auto k: key) {
            if (isspace(k)) continue;
            if (table[k - 'a'] < 0) {
                table[k - 'a'] = cur++;
            }
        }
        string res(message.size(), ' ');
        for (int i = 0; i < message.size(); ++i) {
            const auto k = message[i];
            res[i] = isspace(k) ? ' ' : table[k - 'a'] + 'a';
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv") << endl;
}

//
// Created By jing At 2026-05-12 21:29
//
