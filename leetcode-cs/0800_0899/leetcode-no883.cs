// problem: https://leetcode.cn/problems/projection-area-of-3d-shapes/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo883;

using System;
using System.Linq;

public class Solution {
    public int ProjectionArea(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        int[] mx = new int[m];
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int lmx = 0;
            for (int j = 0; j < m; ++j) {
                int temp = grid[i][j];
                if (temp > 0)
                    res++;
                if (temp > mx[j])
                    mx[j] = temp;
                if (temp > lmx)
                    lmx = temp;
            }

            res += lmx;
        }

        for (int i = 0; i < m; ++i) res += mx[i];
        return res;
    }

    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ProjectionArea([[1, 2], [3, 4]]));
        Console.WriteLine(s.ProjectionArea([[2]]));
        Console.WriteLine(s.ProjectionArea([[1, 0], [0, 2]]));
    }
}

//
// Created By jing At 10/31/25 18:10:30
//