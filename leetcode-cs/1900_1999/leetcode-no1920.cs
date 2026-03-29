// problem: https://leetcode.cn/problems/count-square-sum-triples/?envType=daily-question&envId=2025-12-08 

namespace leetcodeNo1920;

using System;

public class Solution {
    public int CountTriples(int n) {
        int limit = n * n, res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int t = i * i + j * j;
                if (t > limit) continue;
                int m = t % 16;
                if (m != 1 && m != 4 && m != 9 && m != 0) continue;
                int x = t;
                int y = (x + 1) / 2;
                while (y < x) {
                    x = y;
                    y = (x + t / x) / 2;
                }

                if (x * x == t) {
                    if (i == j) {
                        res += 1;
                    } else {
                        res += 2;
                    }
                }
            }
        }

        return res;
    }
}

public class Solution3 {
    private int getSquare(int t) {
        int x = t;
        int y = (x + 1) / 2;
        while (y < x) {
            x = y;
            y = (x + t / x) / 2;
        }

        return x;
    }

    public int CountTriples(int n) {
        int limit = n * n, res = 0;
        for (int i = 5; i <= n; ++i) {
            var t = i * i;
            int x = getSquare(t);
            if (x * x == t) {
                for (var j = 1; j < x; ++j) {
                    var k = t - j * j;
                    var sk = getSquare(k);
                    if (sk * sk == k) {
                        res += 1;
                    }
                }
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CountTriples(5));
        Console.WriteLine(s.CountTriples(10));
        Console.WriteLine(s.CountTriples(18));
    }
}

//
// Created By jing At 12/8/25 18:17:49
//