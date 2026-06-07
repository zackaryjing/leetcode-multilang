// problem: https://leetcode.cn/problems/check-if-the-sentence-is-pangram/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> cnts(26);
        for (const char c: sentence) {
            cnts[c - 'a']++;
        }
        return ranges::all_of(cnts, identity{});
    } 
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << endl;
}

//
// Created By jing At 20:34
//
