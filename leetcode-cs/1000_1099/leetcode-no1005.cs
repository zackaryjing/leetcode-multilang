// problem: https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/?envType=problem-list-v2&envId=3rBpGyas 

using System.Net;

namespace leetcodeNo1005;

using System;
using System.Linq;

public class Solution2 {
    public int LargestSumAfterKNegations(int[] nums, int k) {
        Array.Sort(nums);
        int n = nums.Length;
        int negCnt = nums.Count(x => x < 0);
        int negSum = 0;
        int res = 0;
        if (negCnt > 0 && negCnt >= k) {
            for (int i = 0; i < k; ++i) {
                negSum += -nums[i];
            }

            for (int i = k; i < n; ++i) {
                res += nums[i];
            }

            return negSum + res;
        }

        int mnAbsVal = Int32.MaxValue;

        if (negCnt > 0) {
            mnAbsVal = int.Abs(nums[negCnt - 1]);
        }

        if (negCnt < n) {
            mnAbsVal = int.Min(nums[negCnt], mnAbsVal);
        }

        for (int i = 0; i < negCnt; ++i) {
            negSum += -nums[i];
        }

        for (int i = negCnt; i < n; ++i) {
            res += nums[i];
        }

        int operationCnt = k - negCnt;
        if (operationCnt % 2 == 1) {
            res -= 2 * mnAbsVal;
        }

        return res + negSum;
    }
}

public class Solution {
    public int LargestSumAfterKNegations(int[] nums, int k) {
        Array.Sort(nums);
        var n = nums.Length;
        var negCnt = nums.Count(x => x < 0);
        var res = 0;
        if (negCnt > 0 && negCnt >= k) {
            for (var i = 0; i < n; ++i) {
                if (i < k) {
                    res += -nums[i];
                } else {
                    res += nums[i];
                }
            }

            return res;
        }

        int mnAbsVal = Int32.MaxValue;

        if (negCnt > 0) {
            mnAbsVal = int.Abs(nums[negCnt - 1]);
        }

        if (negCnt < n) {
            mnAbsVal = int.Min(nums[negCnt], mnAbsVal);
        }

        for (var i = 0; i < n; ++i) {
            if (i < negCnt) {
                res += -nums[i];
            } else {
                res += nums[i];
            }
        }

        if (((k - negCnt) & 1) == 1) {
            res -= mnAbsVal << 1;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.LargestSumAfterKNegations([4, 2, 3], 1));
        Console.WriteLine(s.LargestSumAfterKNegations([3, -1, 0, 2], 3));
        Console.WriteLine(s.LargestSumAfterKNegations([2, -3, -1, 5, -4], 2));
        Console.WriteLine(s.LargestSumAfterKNegations([-2, 5, 0, 2, -2], 3));
    }
}

//
// Created By jing At 11/2/25 14:11:19
//