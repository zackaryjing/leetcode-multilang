// problem: https://leetcode.cn/problems/minimum-swaps-to-make-strings-equal/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1247;

using System;

public class Solution {
    public int MinimumSwap(string s1, string s2) {
        var n = s1.Length;
        var type1 = 0;
        var type2 = 0;
        for (var i = 0; i < n; ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') {
                type1 += 1;
            } else if (s1[i] == 'y' && s2[i] == 'x') {
                type2 += 1;
            }
        }

        // Console.WriteLine($"{type1} {type2}");
        return ((type1 + type2) & 1) == 1 ? -1 : type1 / 2 + type2 / 2 + type1 % 2 + type2 % 2;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinimumSwap("xx", "xy"));
        Console.WriteLine(s.MinimumSwap("xx", "yy"));
        Console.WriteLine(s.MinimumSwap("xy", "yx"));
    }
}

//
// Created By ASUS At 11/7/2025 15:11:27
//