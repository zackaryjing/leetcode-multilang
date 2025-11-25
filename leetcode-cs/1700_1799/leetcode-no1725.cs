// problem: https://leetcode.cn/problems/number-of-rectangles-that-can-form-the-largest-square/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1725;

using System;

public class Solution {
    public int CountGoodRectangles(int[][] rectangles) {
        var mx = 0;
        var res = 0;
        foreach (var size in rectangles) {
            var cur = int.Min(size[0], size[1]);
            if (cur > mx) {
                res = 1;
                mx = cur;
            } else if (mx == cur) {
                res++;
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CountGoodRectangles([[5, 8], [3, 9], [5, 12], [16, 5]]));
        Console.WriteLine(s.CountGoodRectangles([[2, 3], [3, 7], [4, 3], [3, 7]]));
    }
}

//
// Created By ASUS At 11/24/2025 01:11:13
//