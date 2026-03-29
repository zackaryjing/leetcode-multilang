// problem: https://leetcode.cn/problems/paint-house-ii/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo265;

using System;

public class Solution {
    public int MinCostII(int[][] costs) {
        int m = costs[0].Length, vpos = -1, vmn1 = 0, vmn2 = 0;
        var dp = costs[0];
        for (var i = 0; i < costs.Length; ++i) {
            var cost = costs[i];
            int mn1 = int.MaxValue, mn2 = int.MaxValue, pos = -1;
            for (var j = 0; j < m; ++j) {
                dp[j] = cost[j] + (j == vpos ? vmn2 : vmn1);
                var temp = dp[j];
                if (temp <= mn1) {
                    mn2 = mn1;
                    mn1 = temp;
                    pos = j;
                } else if (temp < mn2) {
                    mn2 = temp;
                }
            }

            vmn1 = mn1;
            vmn2 = mn2;
            vpos = pos;
        }

        return vmn1;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinCostII([[1, 3], [2, 4]]));
        Console.WriteLine(s.MinCostII([[1, 5, 3], [2, 9, 4]]));
    }
}

//
// Created By ASUS At 12/2/2025 15:12:02
//