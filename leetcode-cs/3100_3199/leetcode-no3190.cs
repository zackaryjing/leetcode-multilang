// problem: https://leetcode.cn/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/?envType=daily-question&envId=2025-11-22

namespace leetcodeNo3190;

using System;

public class Solution {
    public int MinimumOperations(int[] nums) {
        var res = 0;
        foreach (var num in nums) {
            if (num % 3 != 0) {
                res++;
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinimumOperations([1, 2, 3, 4]));
    }
}

//
// Created By jing At 11/22/25 01:11:41
//