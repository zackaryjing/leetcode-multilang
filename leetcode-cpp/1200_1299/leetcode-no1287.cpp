#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> & list,int val,int n,int type){
        int left = 0,right = n -  1;
        if (type) {
            while (left != right) {
                int mid = (left + right) / 2 + 1;
                if (mid >= n) {
                    return n;
                }
                if (list[mid] > val) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            return left;
        } else {
            while (left != right) {
                int mid = (left + right) / 2;
                if (mid < 0) {
                    return 0;
                }
                if (list[mid] >= val) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }
    }
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4 + 1;
        vector<int> candidate;
        for (int i = 0;i < n;i += span){
            candidate.push_back(arr[i]);
        }
        for (auto cand : candidate){
//            cout << binarySearch(arr,cand,n,1) - binarySearch(arr,cand,n,0) + 1 << endl;
            if (binarySearch(arr,cand,n,1) - binarySearch(arr,cand,n,0) + 1 >= span){
                return cand;
            }
        }
//        return 0;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {1,2,2,6,6,6,6,7,10};
    cout << test.findSpecialInteger(eg1) << endl;
    vector<int> eg2 = {1};
    cout << test.findSpecialInteger(eg2) << endl;
}

//
// Created by ASUS on 2023/7/15.
//
