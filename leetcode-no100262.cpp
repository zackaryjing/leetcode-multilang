#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int> &nums) {
        long long ans = 0;
        for (int j : nums){
            int k = 0,m = j % 10;
            while (j > 0){
//                cout << m << " <-m " ;
                j /= 10;
                m = max(m,j % 10);
                k *= 10;
                k++;
//                cout << k << " ";
            }
//            cout << endl;
            ans += k * m;
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {10,21,31};
    cout << test.sumOfEncryptedInt(nums1) << endl;
    cout << endl;
    cout << test.sumOfEncryptedInt(nums2) << endl;

}
//
// Created by ASUS on 2024/3/16.
//
