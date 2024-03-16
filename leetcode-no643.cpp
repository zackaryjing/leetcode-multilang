#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
//        cout << *nums.begin() << " " << *(nums.begin() + 1) << endl;
//        cout << accumulate(nums.begin(), nums.begin() + 3, 0) << endl;
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
//        cout << sum << "<--" << endl;
        int maxum = sum;
//        cout << sum << endl;
//        cout << (int)nums.size() - k- 1 << "size" << endl;
        if ((int)nums.size() - k - 1 >= 0) {
            for (int i = 0; i <= (int)nums.size() - k; i++) {
                sum -= nums[i];
                sum += nums[i + k];
//                cout << sum << endl;
                maxum = max(maxum, sum);
            }
        }
        double res = ((double) maxum) / k;
        return (res);
    }
};

int main() {
    Solution test;
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    cout << test.findMaxAverage(nums1, 4) << endl;
    vector<int> nums2 = {5};
    cout << test.findMaxAverage(nums2, 1) << endl;
    vector<int> nums3 = {0,1,1,3,3};
    cout << test.findMaxAverage(nums3, 4) << endl;
}
//
// Created by ASUS on 2024/2/25.
//
