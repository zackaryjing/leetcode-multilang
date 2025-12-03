// problem: https://leetcode.cn/problems/paint-fence/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo276;

using System;

public class Solution {
    public int NumWays(int n, int k) {
        int can = k, cannot = 0;

        for (var i = 1; i < n; ++i) {
            (can, cannot) = ((can + cannot) * (k - 1), can);
        }

        return can + cannot;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.NumWays(2, 3));
        Console.WriteLine(s.NumWays(3, 2));
        Console.WriteLine(s.NumWays(1, 1));
        Console.WriteLine(s.NumWays(7, 2));
    }
}

//
// Created By ASUS At 12/3/2025 16:12:49
//