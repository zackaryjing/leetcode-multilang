// problem: https://leetcode.cn/problems/walls-and-gates/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo286;

using System;

public class Solution {
    private struct Point(int x, int y) {
        public readonly int X = x, Y = y;
    }

    private readonly int[,] dirs = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };

    public void WallsAndGates(int[][] rooms) {
        Queue<Point> toVis = new();
        int n = rooms.Length, m = rooms[0].Length;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) toVis.Enqueue(new Point(i, j));
            }
        }

        var depth = 1;
        while (toVis.Count > 0) {
            var size = toVis.Count;
            for (var i = 0; i < size; ++i) {
                var p = toVis.Dequeue();
                for (var j = 0; j < 4; ++j) {
                    int ni = p.X + dirs[j, 0], nj = p.Y + dirs[j, 1];
                    if (0 > ni || ni >= n || 0 > nj || nj >= m || rooms[ni][nj] <= depth) continue;
                    rooms[ni][nj] = depth;
                    toVis.Enqueue(new Point(ni, nj));
                }
            }

            depth++;
        }
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        int[][] t1 = {
            [2147483647, -1, 0, 2147483647], [2147483647, 2147483647, 2147483647, -1],
            [2147483647, -1, 2147483647, -1], [0, -1, 2147483647, 2147483647]
        };
        s.WallsAndGates(t1);
        Console.WriteLine(string.Join("\n", t1.Select(a => string.Join(", ", a))));
    }
}

//
// Created By ASUS At 12/5/2025 14:12:34
//