// problem: https://leetcode.cn/problems/check-if-all-1s-are-at-least-length-k-places-away/?envType=daily-question&envId=2025-11-17 

namespace leetcodeNo1437;

using System;

public class Solution {
    public bool KLengthApart(int[] nums, int k) {
        var n = nums.Length;
        int curCnt = n;
        for (var i = 0; i < n; ++i) {
            if (nums[i] != 1) {
                curCnt++;
            } else {
                if (curCnt < k) {
                    return false;
                }

                curCnt = 0;
            }
        }

        return true;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.KLengthApart([1, 0, 0, 0, 1, 0, 0, 1], 2));
        Console.WriteLine(s.KLengthApart([1, 0, 0, 1, 0, 1], 2));
    }
}

//
// Created By jing At 11/17/25 19:11:38
//