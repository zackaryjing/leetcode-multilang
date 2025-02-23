#include <algorithm>
#include <bitset>
#include <iostream>
#include <memory>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int> > &grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        bitset<256> bits;
        bitset<256> once;
        for (const auto &line: grid) {
            bitset<256> temp;
            for (int j = 0; j < m; j++) {
                temp[m - j - 1] = line[j];
            }
            bits |= once & temp;
            once |= temp;
        }
        for (auto line: grid) {
            int line_sum = 0;
            line_sum = accumulate(line.begin(), line.end(), 0);
            if (line_sum > 1) {
                ans += line_sum;
            } else {
                auto it = ranges::find(line, 1);
                if (it != line.end()) {
                    int pos = static_cast<int>(it - line.begin());
                    if (bits[m - pos - 1] == 1) {
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countServers(*make_unique<vector<vector<int> > >(vector<vector<int> >{
        {1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}
    })) << endl;
    cout << test.countServers(*make_unique<vector<vector<int> > >(vector<vector<int> >{
        {1, 0}, {1, 1}
    })) << endl;
}


//
// Created by ASUS on 2025/2/20.
//
