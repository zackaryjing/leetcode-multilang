#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return (a != b) ? max(a.size(), b.size()) : -1;
    }
};

int main() {
    Solution test;
}

//
// Created by ASUS on 2025/2/7.
//
