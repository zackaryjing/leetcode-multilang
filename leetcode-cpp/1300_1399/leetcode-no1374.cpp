// problem: https://leetcode.cn/problems/generate-a-string-with-characters-that-have-odd-counts/?envType=problem-list-v2&envId=FeuPdeiM
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        return n % 2 == 0 ? string(n - 1,'a') + "b" : string(n, 'a');
    }
};

int main(int argc, char *argv[]) {
    Solution test;

}

//
// Created By jing At 2026-05-25 19:02
//