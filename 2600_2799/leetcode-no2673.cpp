#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int> &cost) {
        int ans = 0;
        vector<int> last(n - n / 2, 0);
        while (n > 1) {
            for (int i = n / 2; i < n; i += 2) {
                ans += abs(cost[i] + last[i - n / 2] - cost[i + 1] - last[i + 1 - n / 2]);
                last[(i - n / 2) / 2] = max(cost[i] + last[i - n / 2], cost[i + 1] + last[i + 1 - n / 2]);
            }
            n /= 2;
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 5, 2, 2, 3, 3, 1};
    cout << test.minIncrements(7, nums) << endl;
    nums = {5,3,3};
    cout << test.minIncrements(3, nums) << endl;
}
//
// Created by ASUS on 2024/2/28.
//
