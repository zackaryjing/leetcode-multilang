// problem: https://leetcode.cn/problems/paint-house/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Linq;

namespace leetcodeNo256;

using System;

public class Solution2 {
    public int MinCost(int[][] costs) {
        var res = 0;
        var m = costs[0].Length;
        var dp = costs[0];
        for (var i = 1; i < costs.Length; ++i) {
            var mn1 = int.MaxValue;
            var mn2 = int.MaxValue;
            var pos = -1;
            for (var j = 0; j < m; ++j) {
                var temp = dp[j];
                if (temp <= mn1) {
                    mn2 = mn1;
                    mn1 = temp;
                    pos = j;
                } else if (temp < mn2) {
                    mn2 = temp;
                }
            }

            for (var j = 0; j < m; ++j) {
                dp[j] = costs[i][j] + (j == pos ? mn2 : mn1);
            }
        }

        return dp.Min();
    }
}

public class Solution {
    public int MinCost(int[][] costs) {
        int m = costs[0].Length, vpos = -1, vmn1 = 0, vmn2 = 0;
        var dp = costs[0];
        // ReSharper disable once ForCanBeConvertedToForeach
        for (var i = 0; i < costs.Length; ++i) {
            var cost = costs[i];
            var mn1 = int.MaxValue;
            var mn2 = int.MaxValue;
            var pos = -1;
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
        Console.WriteLine(s.MinCost([[17, 2, 17], [16, 16, 5], [14, 3, 19]]));
        Console.WriteLine(s.MinCost([[7, 6, 2]]));
        Console.WriteLine(s.MinCost([[3, 5, 3], [6, 17, 6], [7, 13, 18], [9, 10, 18]]));
    }
}

//
// Created By ASUS At 12/2/2025 02:12:19
//