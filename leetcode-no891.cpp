#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long res = 0;
        long long MOD = 1e9 + 7;
        long x = nums[0],y = 2;
        for (long long i = 1;i<nums.size();i++){
            res = (res + nums[i] * (y - 1) - x) % MOD;
            y *= 2 ;
            y %= MOD;
            x = (2 * x + nums[i]) % MOD;
        }
        return (res + MOD) % MOD;
    }
};


//
// Created by ASUS on 2023/7/9.
//
