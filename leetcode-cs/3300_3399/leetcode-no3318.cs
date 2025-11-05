// problem: https://leetcode.cn/problems/find-x-sum-of-all-k-long-subarrays-i/?envType=daily-question&envId=2025-11-04 

using System.Linq;

namespace leetcodeNo3318;

using System;

public class Solution {
    public int[] FindXSum(int[] nums, int k, int x) {
        int N = 51;
        int n = nums.Length;
        int[] occur = new int[N];
        int[] res = new int[n - k + 1];
        for (int i = 0; i < n; ++i) {
            int num = nums[i];

            occur[num]++;
            if (i >= k - 1) {
                res[i - k + 1] = occur.Select((value, index) => (value, index)).Where(p => p.value > 0)
                    .OrderByDescending(p => p.value)
                    .ThenByDescending(p => p.index).Take(x).Sum(p => p.index * p.value);
                occur[nums[i - k + 1]]--;
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.FindXSum([1, 1, 2, 2, 3, 4, 2, 3], 6, 2)));
        Console.WriteLine(string.Join(" ", s.FindXSum([3, 8, 7, 8, 7, 5], 2, 2)));
        Console.WriteLine(string.Join(" ", s.FindXSum([50, 50, 50, 50, 50, 50], 6, 1)));
    }
}

//
// Created By jing At 11/4/25 14:11:57
//