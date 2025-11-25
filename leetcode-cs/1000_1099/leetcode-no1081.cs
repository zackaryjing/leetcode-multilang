// problem: https://leetcode.cn/problems/binary-prefix-divisible-by-5/?envType=daily-question&envId=2025-11-25 

using System.Collections.Generic;
using System.Globalization;

namespace leetcodeNo1081;

using System;

public class Solution {
    public IList<bool> PrefixesDivBy5(int[] nums) {
        var res = new List<bool>(nums.Length);
        var cur = 0;
        foreach (var num in nums) {
            cur = ((cur << 1) | num) % 5;
            res.Add(cur == 0);
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.PrefixesDivBy5([0, 1, 1])));
        Console.WriteLine(string.Join(" ", s.PrefixesDivBy5([1, 1, 1])));
        Console.WriteLine(string.Join(" ",
            s.PrefixesDivBy5([
                1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1,
                0, 0, 0, 1
            ])));
    }
}

//
// Created By ASUS At 11/25/2025 00:11:14
//