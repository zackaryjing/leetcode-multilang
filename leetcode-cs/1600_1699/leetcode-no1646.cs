// problem: https://leetcode.cn/problems/get-maximum-in-generated-array/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1646;

using System;

public class Solution2 {
    public int GetMaximumGenerated(int n) {
        n++;
        if (n < 2) {
            return 0;
        }

        var res = new int[n];
        res[1] = 1;

        var ans = 1;
        for (int i = 1; i <= n / 2; ++i) {
            ans = int.Max(ans, res[i] + res[i - 1]);
            if (i * 2 < n) {
                res[i * 2] = res[i];
            }

            res[i * 2 - 1] = res[i] + res[i - 1];
        }

        return ans;
    }
}

public class Solution {
    public int GetMaximumGenerated(int n) {
        n++;
        if (n < 2) {
            return 0;
        }

        var res = new int[n];
        res[1] = 1;

        var ans = 1;
        for (int i = 1; i < n / 2; ++i) {
            ans = int.Max(ans, res[i] + res[i - 1]);
            res[i * 2] = res[i];
            res[i * 2 - 1] = res[i] + res[i - 1];
        }

        if (n % 2 == 1) {
            ans = int.Max(ans, res[n >> 1]);
            res[(n >> 1) << 1] = res[n >> 1];
        }

        res[((n >> 1) << 1) - 1] = res[n >> 1] + res[(n >> 1) - 1];
        ans = int.Max(ans, res[((n >> 1) << 1) - 1]);

        return ans;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.GetMaximumGenerated(100));
        Console.WriteLine(s.GetMaximumGenerated(7));
        Console.WriteLine(s.GetMaximumGenerated(2));
        Console.WriteLine(s.GetMaximumGenerated(3));
        Console.WriteLine(s.GetMaximumGenerated(4));
    }
}

//
// Created By ASUS At 11/27/2025 01:11:33
//