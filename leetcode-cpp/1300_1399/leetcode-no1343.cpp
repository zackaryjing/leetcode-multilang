// problem: number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int limit = k * threshold;
        int n = arr.size();
        if (n < k) {
            return 0;
        }
        int s = 0;
        int i = 0;
        for (; i < k; i++) {
            s += arr[i];
        }
        int res = 0;
        if (s >= limit) {
            res++;
        }
        while (i < n) {
            s += arr[i];
            s -= arr[i - k];
            if (s >= limit) {
                res++;
                // cout << i << endl;
            }
            i++;
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numOfSubarrays(*make_unique<vector<int> >(vector{2, 2, 2, 2, 5, 5, 5, 8}), 3, 4) << endl;
}

//
// Created by ASUS on 2025/3/17.
//
