#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution2 {
    public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> nums1(arr1.begin(),arr1.end());
        unordered_set<int> nums2(arr2.begin(),arr2.end());
        int size1 = arr1.size();
        int size2 = arr2.size();
        unordered_set<int> nums3;
        //arr2.resize(size1 + size2);
        cout << endl;
//        set_difference(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());
        for (auto i : arr2) cout << i << " ";
        return {};
    }
};

class Solution3 {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        set<int> s1(arr1.begin(), arr1.end());
        set<int> s2(arr2.begin(), arr2.end());
        set<int> s3;
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3,s3.begin()));
        for (auto t : s3) cout << t << " " ;
//        cout << endl;
//        sort(arr2.begin(), arr2.end());
        arr2.insert(arr2.end(),s3.begin(),s3.end());
        return arr2;
    }
};

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> times;
        for (auto k : arr1){
            times[k]++;
        }
        vector<int> ans;
        for (auto k : arr2){
            for (int j = 0;j < times[k];++j){
                ans.push_back(k);
            }
            times.erase(k);
        }
        for (auto [h,time] : times) {
            for (int k = 0 ;k < time;++k) {
                ans.push_back(h);
            }
        }
        return ans;
    }
};


int main(){
    Solution test;
    vector<int> arr1 = {9,3,4,5,7,8,6,1,2};
    vector<int> arr2 = {2,1,3,4,5};
    vector<int> res = test.relativeSortArray(arr1,arr2);
    for (auto j : res) cout << j << " " ;
    cout << endl;
    arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    arr2 = {2,1,4,3,9,6};
    res = test.relativeSortArray(arr1,arr2);
    for (auto j : res) cout << j << " " ;
    cout << endl;
    arr1 = {28,6,22,8,44,17};
    arr2 = {22,28,8,6};
    res = test.relativeSortArray(arr1,arr2);
    for (auto j : res) cout << j << " " ;
    cout << endl;
    arr1 = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};
    arr2 = {2,42,38,0,43,21};
    res = test.relativeSortArray(arr1,arr2);
    for (auto j : res) cout << j << " " ;
}
//
// Created by ASUS on 2023/6/28.
//
