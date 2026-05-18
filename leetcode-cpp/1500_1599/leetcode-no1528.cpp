// problem: https://leetcode.cn/problems/shuffle-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int> &indices) {
        string res(s.size(), ' ');
        for (int i = 0; i < indices.size(); ++i) {
            res[indices[i]] = s[i];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.restoreString("codeleet", temp_vector({4, 5, 6, 7, 0, 2, 1, 3})) << endl;
}

//
// Created By jing At 2026-05-17 00:10
//
