#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> nums1(arr1.begin(),arr1.end());
        unordered_set<int> nums2(arr2.begin(),arr2.end());
        int size1 = arr1.size();
        int size2 = arr2.size();
        unordered_set<int> nums3;
        //arr2.resize(size1 + size2);
        cout << endl;
        set_difference(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());
        for (auto i : arr2) cout << i << " ";
    }
};

int main(){
    Solution test;
    vector<int> arr1 = {9,3,4,5,7,8,6,1,2};
    vector<int> arr2 = {1,2,3,4,5};
    test.relativeSortArray(arr1,arr2);
}
//
// Created by ASUS on 2023/6/28.
//
