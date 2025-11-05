// problem: https://leetcode.cn/problems/count-negative-numbers-in-a-sorted-matrix/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1351;

using System;

public class Solution {
    public int CountNegatives(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        int pos = 0;
        int res = 0;

        for (int i = n - 1; i >= 0; --i) {
            while (pos < m && grid[i][pos] >= 0) {
                pos++;
            }

            if (pos < m) {
                res += m - pos;
            } else {
                break;
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CountNegatives([[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]));
    }
}

//
// Created By jing At 11/5/25 13:11:05
//