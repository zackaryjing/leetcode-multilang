// problem: https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/description/?envType=daily-question&envId=2025-04-02
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;


class Solution {
public:
    long long maximumTripletValue(vector<int> &nums) {
        int n = nums.size();
        long long res = 0,imax = 0,dmax  =0;
        for (int i = 0;i < n; ++i) {
            res = max(res,nums[i] * dmax);
            dmax = max(dmax,imax - nums[i]);
            imax = max(imax,static_cast<long long>(nums[i]));
        }
        return res;
    }
};

class Solution2 {
public:
    long long maximumTripletValue(vector<int> &nums) {
        const int MAX = 10e6 + 1;
        int n = nums.size();
        long long ans = 0;
        long long max_num = 0, first = -1, second = MAX;
        long long first_temp = -1, second_temp = MAX;
        for (int i = 0; i < n; ++i) {
            auto t = static_cast<long long>(nums[i]);
            if (t > first_temp) {
                first_temp = t;
                second_temp = t;
            } else if (t < second_temp) {
                second_temp = t;
            }
            max_num = max(max_num, t);
            ans = max(ans, (first - second) * max_num);
            if (first_temp - second_temp > first - second) {
                first = first_temp;
                second = second_temp;
                max_num = 0;
            }
            ans = max(ans, (first - second) * max_num);
            // cout << first_temp << ", " << second_temp << ", " << t << endl;
            // cout << first << ", " << second << ", " << max_num << endl << endl;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumTripletValue(temp_vector({10, 13, 6, 2})) << endl;
    cout << test.maximumTripletValue(temp_vector({1000000, 1, 1000000})) << endl;
    cout << test.maximumTripletValue(temp_vector({12, 6, 1, 2, 7})) << endl;
    cout << test.maximumTripletValue(temp_vector({1, 10, 3, 5, 19})) << endl;
    cout << test.maximumTripletValue(temp_vector({1, 2, 3})) << endl;
}


//
// Created by ASUS on 2025/4/7.
//
