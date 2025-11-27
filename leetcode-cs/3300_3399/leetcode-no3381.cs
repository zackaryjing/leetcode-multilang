// problem: https://leetcode.cn/problems/maximum-subarray-sum-with-length-divisible-by-k/?envType=daily-question&envId=2025-11-27 

namespace leetcodeNo3381;

using System;

public class Solution2 {
    public long MaxSubarraySum(int[] nums, int k) {
        var n = nums.Length;
        var prefixSum = new long[n];
        prefixSum[0] = nums[0];
        for (var i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        var mn = new long[k];
        for (var i = 0; i < k; ++i) {
            mn[i] = prefixSum[i];
        }

        mn[k - 1] = long.Min(mn[k - 1], 0L);

        var res = prefixSum[k - 1];
        for (var i = k; i < n; ++i) {
            res = long.Max(res, prefixSum[i] - mn[i % k]);
            mn[i % k] = long.Min(prefixSum[i], mn[i % k]);
        }

        return res;
    }
}

public class Solution {
    public long MaxSubarraySum(int[] nums, int k) {
        var prefixSum = 0L;

        var mn = new long[k];
        for (var i = 0; i < k; ++i) {
            prefixSum += nums[i];
            mn[i] = prefixSum;
        }

        mn[k - 1] = long.Min(mn[k - 1], 0L);

        var res = prefixSum;
        for (var i = k; i < nums.Length; ++i) {
            prefixSum += nums[i];
            var p = i % k;
            var h = mn[p];
            res = long.Max(res, prefixSum - h);
            mn[p] = long.Min(prefixSum, h);
        }

        return res;
    }
}



public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MaxSubarraySum([1, 2], 1));
        Console.WriteLine(s.MaxSubarraySum([-1, -2, -3, -4, -5], 4));
        Console.WriteLine(s.MaxSubarraySum([-5, 1, 2, -3, 4], 2));
    }
}

//
// Created By zhiya At 2025/11/27 17:11:59
//