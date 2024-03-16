#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class NumArray {
private:
    vector<int> accu;
public:
    NumArray(vector<int> &nums) {
        int temp = 0;
        for (auto j: nums) {
            accu.push_back(temp);
            temp += j;
        }
        accu.push_back(temp);
    }
    int sumRange(int left, int right) {
        return accu[right + 1] - accu[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray test(nums);
    cout << test.sumRange(0,2) << endl;
    cout << test.sumRange(2,5) << endl;
    cout << test.sumRange(0,5) << endl;
}
//
// Created by ASUS on 2024/2/19.
//
