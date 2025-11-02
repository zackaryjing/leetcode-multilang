// problem: https://leetcode.cn/problems/shift-2d-grid/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections;
using System.Collections.Generic;
using Utils;

namespace leetcodeNo1260;

using System;

public class Solution {
    public IList<IList<int>> ShiftGrid2(int[][] grid, int k) {
        var m = grid.Length;
        var n = grid[0].Length;
        var a = k % n;
        var b = (k / n) % m;
        var c = (b + 1) % m;
        int[][] nGrid = new int[m][];

        for (var i = 0; i < m; ++i) nGrid[i] = new int[n];
        for (var i = 0; i < m; ++i) {
            for (var j = 0; j < n - a; ++j) {
                nGrid[(i + b) % m][(j + a) % n] = grid[i][j];
            }

            for (var j = n - a; j < n; ++j) {
                nGrid[(i + c) % m][(j + a) % n] = grid[i][j];
            }
        }

        var res = new List<IList<int>>(m);
        for (int i = 0; i < m; ++i) {
            res.Add(nGrid[i]);
        }

        return res;
    }

    public IList<IList<int>> ShiftGrid(int[][] grid, int k) {
        var m = grid.Length;
        var n = grid[0].Length;
        var a = k % n;
        var b = (k / n);
        var c = (b + 1);
        int[][] nGrid = new int[m][];

        for (var i = 0; i < m; ++i) nGrid[i] = new int[n];
        for (var i = 0; i < m; ++i) {
            var first = (i + b) % m;
            var second = (i + c) % m;
            for (var j = 0; j < n - a; ++j) {
                nGrid[first][(j + a) % n] = grid[i][j];
            }

            for (var j = n - a; j < n; ++j) {
                nGrid[second][(j + a) % n] = grid[i][j];
            }
        }

        var res = new List<IList<int>>(m);
        for (int i = 0; i < m; ++i) {
            res.Add(nGrid[i]);
        }

        return res;
    }

    public static void Run() {
        var s = new Solution();
        // Utils.PrintIList(s.ShiftGrid([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 1));
        // Utils.PrintIList(s.ShiftGrid([[3, 8, 1, 9], [19, 7, 2, 5], [4, 6, 11, 10], [12, 0, 21, 13]], 4));
    }
}

//
// Created By jing At 10/30/25 21:10:54
//