#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <minmax.h>

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            for (int k = 0; k < min(n - i,m); ++k) {
                if (nums1[k + i] == nums2[k]){
                    tmp ++;
                } else {
                    tmp = 0;
                }
                ans = max(ans,tmp);
            }
        }
        for (int i = 0; i < m; ++i) {
            int tmp = 0;
            for (int k = 0; k < min(m - i,n); ++k) {
                if (nums2[k + i] == nums1[k]){
                    tmp ++;
                } else {
                    tmp = 0;
                }
                ans = max(ans,tmp);
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> eg1 = {1, 2, 3, 2, 1};
    vector<int> eg2 = {3, 2, 1, 4, 7};
    cout << test.findLength(eg1, eg2) << endl;
    cout << test.findLength(eg2, eg1) << endl;
    vector<int> eg3 = {0,0,0,0,0};
    cout << test.findLength(eg3, eg3) << endl;
    vector<int> eg4 = {5,14,53,80,48};
    vector<int> eg5 = {50,47,3,80,83};
    cout << test.findLength(eg4, eg5) << endl;
    vector<int> eg6 ={1,2,3,2,1};
    vector<int> eg7 ={3,2,1,4};
    cout << test.findLength(eg6, eg7) << endl;
}

//
// Created by ASUS on 2023/6/20.
//
