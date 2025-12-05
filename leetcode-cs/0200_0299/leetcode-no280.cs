// problem: https://leetcode.cn/problems/wiggle-sort/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo280;

using System;

public class Solution2 {
    public void WiggleSort(int[] nums) {
        int n = nums.Length;
        var copy = (int[])nums.Clone();
        Array.Sort(copy);
        var mid = (n + 1) / 2;
        for (var i = 0; i < mid; ++i) {
            nums[2 * i] = copy[i];
        }

        for (var i = mid; i < n; ++i) {
            nums[(i - mid) * 2 + 1] = copy[i];
        }
    }
}

public class Solution {
    public void WiggleSort(int[] nums) {
        var n = nums.Length;
        var cur = true;
        for (var i = 0; i < n - 1; ++i) {
            if ((i & 1) == 0 && nums[i] > nums[i + 1] || (i & 1) == 1 && nums[i] < nums[i + 1]) {
                (nums[i + 1], nums[i]) = (nums[i], nums[i + 1]);
            }
        }
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        var t1 = new[] { 3, 5, 2, 1, 6, 4 };
        s.WiggleSort(t1);
        Console.WriteLine(string.Join(" ", t1));
        var t2 = new[] { 6, 6, 5, 6, 3, 8 };
        s.WiggleSort(t2);
        Console.WriteLine(string.Join(" ", t2));
    }
}

//
// Created By ASUS At 12/4/2025 16:12:01
//