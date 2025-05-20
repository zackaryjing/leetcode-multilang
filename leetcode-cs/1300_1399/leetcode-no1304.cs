// problem: https://leetcode.cn/problems/find-n-unique-integers-sum-up-to-zero/

using System;
using System.Collections.Generic;
using System.Linq;

namespace leetcode_no1304;

public class Solution {
    public int[] SumZero(int n) {
        List<int> res = [];
        if ((n & 1) == 1) {
            res.Add(0);
        }

        for (var i = 1; i <= n / 2; ++i) {
            res.Add(i);
            res.Add(-i);
        }

        return res.ToArray();
    }

    public static void Run() {
        var s = new Solution();
        Console.WriteLine($"res: {string.Join(",", s.SumZero(5))}");
    }
}

//
// Created By Zackary At 2025-05-20 21:16:16
//