// problem: https://leetcode.cn/problems/xor-operation-in-an-array/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1486;

using System;

public class Solution {
    public int XorOperation(int n, int start) {
        var res = 0;
        for (int i = 0; i < n; ++i) {
            res ^= start + 2 * i;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.XorOperation(5, 0));
        Console.WriteLine(s.XorOperation(4, 3));
        Console.WriteLine(s.XorOperation(1, 7));
        Console.WriteLine(s.XorOperation(10, 5));
    }
}

//
// Created By ASUS At 11/25/2025 22:11:16
//