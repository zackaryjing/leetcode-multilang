// problem: https://leetcode.cn/problems/crawler-log-folder/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minOperations(vector<string> &logs) {
        int level = 0;
        for (const auto &str: logs) {
            if (str.starts_with("..")) {
                if (level > 0) level--;
            } else if (not str.starts_with(".")) {
                level++;
            }
        }
        return level;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minOperations(temp_vector({"d1/", "d2/", "../", "d21/", "./"})) << endl;
    cout << test.minOperations(temp_vector({"d1/","d2/","./","d3/","../","d31/"})) << endl;
}

//
// Created By ASUS At 2026-04-09 00:46
//
