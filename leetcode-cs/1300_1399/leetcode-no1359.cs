// problem: https://leetcode.cn/problems/count-all-valid-pickup-and-delivery-options/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1359;

using System;

public class Solution2 {
    public int CountOrders(int n) {
        var dp = new Int64[n + 1];
        dp[1] = 1;
        for (var i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] * i * (2 * i - 1) % 1000_000_007;
        }

        // Console.WriteLine(string.Join(" ", dp));
        return (int)dp[n];
    }
}

public class Solution {
    public int CountOrders(int n) {
        long cur = 1;
        for (var i = 2; i <= n; ++i) {
            cur = cur * i * (2 * i - 1) % 1000_000_007;
        }

        return (int)cur;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CountOrders(1));
        Console.WriteLine(s.CountOrders(2));
    }
}

//
// Created By ASUS At 11/18/2025 15:11:26
//