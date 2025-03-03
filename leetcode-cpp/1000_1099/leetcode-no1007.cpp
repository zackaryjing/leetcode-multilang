#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        int n = tops.size();
        vector<int> top(7);
        vector<int> bottom(7);
        vector<int> total(7);
        for (int i = 0; i < n; i++) {
            const int t = tops[i], b = bottoms[i];
            top[t]++;
            bottom[b]++;
            total[t]++;
            if (t != b) {
                total[b]++;
            }
        }
        int ans = INT_MAX;
        for (int key = 1; key <= 6; key++) {
            if (const int val = total[key]; val == n) {
                ans = min(ans, min(n - top[key], n - bottom[key]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector egt1 = {2, 1, 2, 4, 2, 2};
    vector egb1 = {5, 2, 6, 2, 3, 2};
    cout << test.minDominoRotations(egt1, egb1) << endl;
    vector egt2 = {3, 5, 1, 2, 3};
    vector egb2 = {3, 6, 3, 3, 4};
    cout << test.minDominoRotations(egt2, egb2) << endl;
}



//
// Created by ASUS on 2025/2/26.
//
