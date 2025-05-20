// problem: https://leetcode.cn/problems/check-if-it-is-a-straight-line/description/

namespace leetcode_no1232;

using System;

public class Solution {
    public bool CheckStraightLine(int[][] coordinates) {
        var n = coordinates.Length;
        if (n == 2) {
            return true;
        }

        var x0 = coordinates[0][0];
        var y0 = coordinates[0][1];
        var diffX = coordinates[1][0] - x0;
        var diffY = coordinates[1][1] - y0;
        for (var i = 2; i < n; i++) {
            if (diffY * (coordinates[i][0] - x0) != diffX * (coordinates[i][1] - y0)) {
                return false;
            }
        }

        return true;
    }

    public static void Run() {
        var s = new Solution();
        var res = s.CheckStraightLine([[1, 1], [2, 2], [3, 4], [4, 5], [5, 6], [7, 7]]);
        Console.WriteLine($"Result: {res}");
        res = s.CheckStraightLine([[1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7]]);
        Console.WriteLine($"Result: {res}");
    }
}

//
// Created By Zackary At 2025-05-20 20:45:53
//