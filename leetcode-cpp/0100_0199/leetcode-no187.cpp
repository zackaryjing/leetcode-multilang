#include <iostream>
#include <map>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    map<char, int> proj = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    map<int, int> times;

    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n <= 10) {
            return {};
        }
        int len = 10;
        int rep = 0;
        for (int i = 0; i < len - 1; i++) {
            rep = rep << 2 | proj[s[i]];
        }
        int mask = (1 << (2 * len)) - 1;
        vector<string> ans;
        for (int i = len - 1; i < n; ++i) {
            rep = (rep << 2 | proj[s[i]]) & mask;
            times[rep]++;
            if (times[rep] == 2) {
                ans.push_back(s.substr(i - len + 1, len));
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<string> res1 = test.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    show_vector(res1);
}


//
// Created by ASUS on 2025/2/17.
//
