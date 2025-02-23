#include <algorithm>
#include "../utils/vector_helper.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int n = arr.size();
        // cout << n << endl;
        // sort(arr.begin(), arr.end());
        // show_vector(arr);
        int delta = n / 4 + 1;
        int prev = 0;
        for (int i = 0; i < n; i += delta) {
            auto iter_l = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto iter_r = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (iter_r - iter_l >= delta) {
                return arr[i];
            }
        }
        return 0;
    }
};

int main() {
    Solution test;
    cout << test.findSpecialInteger(
        *make_unique<vector<int> >(vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 12, 12})) << endl;
    cout << test.findSpecialInteger(*make_unique<vector<int> >(vector{1, 2, 2, 6, 6, 6, 6, 7, 10})) << endl;
    cout << test.findSpecialInteger(*make_unique<vector<int> >(vector{1})) << endl;
}

class Solution2 {
public:
    int binarySearch(vector<int> &list, int val, int n, int type) {
        int left = 0, right = n - 1;
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

    int findSpecialInteger(vector<int> &arr) {
        int n = arr.size();
        int span = n / 4 + 1;
        vector<int> candidate;
        for (int i = 0; i < n; i += span) {
            candidate.push_back(arr[i]);
        }
        for (auto cand: candidate) {
            //            cout << binarySearch(arr,cand,n,1) - binarySearch(arr,cand,n,0) + 1 << endl;
            if (binarySearch(arr, cand, n, 1) - binarySearch(arr, cand, n, 0) + 1 >= span) {
                return cand;
            }
        }
        //        return 0;
    }
};


//
// Created by ASUS on 2023/7/15.
//
