// problem:  https://leetcode.cn/problems/count-distinct-numbers-on-board/?envType=problem-list-v2&envId=FeuPdeiM
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int distinctIntegers(int n) {
        return max(n - 1,1);
    }
};

int main(int argc, char *argv[]) {
    Solution test;

}

//
// Created By jing At 2026-06-02 18:43
//