// problem: https://leetcode.cn/problems/prime-number-of-set-bits-in-binary-representation/

using System;
using System.Collections.Generic;
using System.Numerics;

namespace leetcode_no762;

public class Solution {
    bool[] primes = [
        false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false,
        true, false, true
    ];

    public int CountPrimeSetBits(int left, int right) {
        var res = 0;
        for (var i = left; i <= right; i++) {
            var ones = BitOperations.PopCount((uint)i);
            if (primes[ones]) {
                res += 1;
            }
        }
        return res;
    }

    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CountPrimeSetBits(10, 15));
        Console.WriteLine(s.CountPrimeSetBits(6, 10));
    }
}

//
// Created By Zackary At 2025-05-22 14:00:43
//