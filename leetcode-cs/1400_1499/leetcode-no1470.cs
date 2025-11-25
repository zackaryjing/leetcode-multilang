// problem: https://leetcode.cn/problems/shuffle-the-array/?envType=problem-list-v2&envId=3rBpGyas 

using System.Linq;
using System.Runtime.InteropServices;

namespace leetcodeNo1470;

using System;

public class Solution {
    public int[] Shuffle(int[] nums, int n) {
        var res = new int [2 * n];
        for (var i = 0; i < n; ++i) {
            res[i * 2] = nums[i];
        }

        for (var i = n; i < 2 * n; ++i) {
            res[2 * (i - n) + 1] = nums[i];
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.Shuffle([2, 5, 1, 3, 4, 7], 3)));
        Console.WriteLine(string.Join(" ", s.Shuffle([1, 2, 3, 4, 4, 3, 2, 1], 4)));
    }
}

//
// Created By ASUS At 11/25/2025 14:11:42
//