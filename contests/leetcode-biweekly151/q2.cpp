#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countArrays(vector<int> &original, vector<vector<int> > &bounds) {
        int n = static_cast<int>(original.size());
        if (not n) {
            return 0;
        }
        int top = INT_MAX;
        int bottom = INT_MIN;
        for (int i = 0; i < n; i++) {
            top = min(bounds[i][1] - original[i], top);
            bottom = max(bottom, bounds[i][0] - original[i]);
        }
        return max(top - bottom + 1, 0);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1 = {1, 2, 3, 4};
    vector<vector<int> > eg2 =
            // {{1,10},{2,9},{3,8},{4,7}};
            {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << test.countArrays(eg1, eg2) << endl;
}


//
// Created by ASUS on 2025/3/1.
//
