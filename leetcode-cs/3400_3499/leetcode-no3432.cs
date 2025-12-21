// problem: https://leetcode.cn/problems/count-partitions-with-even-sum-difference/?envType=daily-question&envId=2025-12-05 

using System.Linq;

namespace leetcodeNo3432;

using System;

public class Solution2 {
    // linq isn't efficient enough
    public int CountPartitions(int[] nums) {
        var t = nums.Sum();
        return ((t & 1) == 0) ? nums.Length - 1 : 0;
    }
}

public class Solution {
    public int CountPartitions(int[] nums) {
        var t = 0;
        for (var i = 0; i < nums.Length; ++i) {
            t += nums[i];
        }

        return ((t & 1) == 0) ? nums.Length - 1 : 0;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
    }
}

//
// Created By ASUS At 12/5/2025 14:12:27
//