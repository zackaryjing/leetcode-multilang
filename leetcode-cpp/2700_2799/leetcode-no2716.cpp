// problem:  https://leetcode.cn/problems/minimize-string-length/?envType=daily-question&envId=2025-03-28
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        bitset<26> data;
        for (int i = 0;i < s.size();i++) {
            data.set(s[i] - 'a');
        }
        return data.count();
    }
};


int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created by ASUS on 2025/3/28.
//
