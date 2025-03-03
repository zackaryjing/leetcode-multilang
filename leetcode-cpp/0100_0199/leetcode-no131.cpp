#include <functional>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        int n = static_cast<int>(s.size());
        vector table(n, vector(n, false));
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                i == j;
                table[i][j] == (table[i + 1][j - 1] or j - i == 1) and s[i] == s[j];
            }
        }

        vector<vector<string> > ans;
        vector<string> mid;
        const function<void(int)> dfs = [&](int start) {
            if (start == n) {
                ans.push_back(mid);
                return;
            }
            for (int i = start; i < n; i++) {
                if (table[start][i]) {
                    mid.push_back(s.substr(start, i - start + 1));
                    dfs(i + 1);
                    mid.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    auto res1 = test.partition("aab");
    for (const auto &str_vec: res1) {
        show_vector(str_vec);
    }
}


// Created by ASUS on 2025/3/1.
//
