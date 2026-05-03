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
        while (iss >> word) {
            
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countValidWords("cat and  dog") << endl;
}

//
// Created By jing At 2026-04-30 00:38
//
