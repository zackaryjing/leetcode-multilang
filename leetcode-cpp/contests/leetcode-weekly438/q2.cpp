#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

#include "../../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int> > &grid, vector<int> &limits, int k) {
        vector<int> valid;
        int amount = accumulate(limits.begin(), limits.end(), 0);
        valid.reserve(amount);
        const size_t n = grid.size();
        for (int i = 0; i < n; i++) {
            const auto &line = grid[i];
            priority_queue<int> maxHeap(line.begin(), line.end());
            for (int j = 0; j < limits[i]; j++) {
                valid.push_back(maxHeap.top());
                maxHeap.pop();
            }
        }
        priority_queue<int> res(valid.begin(), valid.end());
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans += res.top();
            res.pop();
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > grid1 = {{1, 2}, {3, 4}};
    vector<int> limits1 = {{1, 2}};
    cout << test.maxSum(grid1, limits1, 2) << endl;
    vector<vector<int> > grid2 = {{5, 3, 7}, {8, 2, 6}};
    vector<int> limits2 = {{2, 2}};
    cout << test.maxSum(grid2, limits2, 3) << endl;
}


//
// Created by ASUS on 2025/2/23.
//
