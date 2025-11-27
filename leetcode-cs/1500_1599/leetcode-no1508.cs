// problem: https://leetcode.cn/problems/range-sum-of-sorted-subarray-sums/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;

namespace leetcodeNo1508;

using System;

public class Solution {
    public int RangeSum(int[] nums, int n, int left, int right) {
        var prefixSum = new int[n + 1];
        for (var i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        var sum = new List<int>(n);
        for (var i = 1; i <= n; i++) {
            for (var j = 0; j < i; ++j) {
                sum.Add(prefixSum[i] - prefixSum[j]);
            }
        }

        sum.Sort();
        var res = 0;
        var mask = 1000_000_007;
        for (var i = left; i <= right; ++i) {
            res += sum[i - 1];
            if (res > mask) {
                res %= mask;
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.RangeSum([1, 2, 3, 4], 4, 1, 5));
        Console.WriteLine(s.RangeSum([1, 2, 3, 4], 4, 3, 4));
        Console.WriteLine(s.RangeSum([1, 2, 3, 4], 4, 1, 10));
    }
}

//
// Created By ASUS At 11/28/2025 00:11:38
//