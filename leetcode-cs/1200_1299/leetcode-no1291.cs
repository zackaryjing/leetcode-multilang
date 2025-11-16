// problem: https://leetcode.cn/problems/sequential-digits/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;

namespace leetcodeNo1291;

using System;

public class Solution {
    public IList<int> SequentialDigits(int low, int high) {
        var n = 36;
        int[] valid = [
            12, 23, 34, 45, 56, 67, 78, 89, 123, 234,
            345, 456, 567, 678, 789, 1234, 2345, 3456,
            4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789,
            123456, 234567, 345678, 456789, 1234567, 2345678, 3456789,
            12345678, 23456789, 123456789
        ];
        var res = new List<int>();
        for (var i = 0; i < n; ++i) {
            if (valid[i] >= low && valid[i] <= high) {
                res.Add(valid[i]);
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.SequentialDigits(100, 300)));
        Console.WriteLine(string.Join(" ", s.SequentialDigits(1000, 13000)));
    }
}

//
// Created By ASUS At 11/16/2025 22:11:44
//