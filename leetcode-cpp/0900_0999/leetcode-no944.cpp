#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string> &strs) {
        int n = strs[0].length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<string> eg1 = {"cba", "daf", "ghi"};
    cout << test.minDeletionSize(eg1) << endl;
    vector<string> eg2 = {"a", "b"};
    cout << test.minDeletionSize(eg2) << endl;
    vector<string> eg3 = {"zyx", "wvu", "tsr"};
    cout << test.minDeletionSize(eg3) << endl;
}


//
// Created by ASUS on 2025/1/23.
//
