// problem:  

using System.Collections;
using System.Collections.Generic;

namespace leetcodeNo1092;

using System;

public class Solution {
    private readonly int[,] direciotns =
        { { 1, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    private struct Point(int x, int y) {
        public int X = x, Y = y;
    }

    public int ShortestPathBinaryMatrix(int[][] grid) {
        var n = grid.Length;
        var toVis = new Queue<Point>();
        toVis.Enqueue(new Point(0, 0));
        if (grid[0][0] == 1) {
            return -1;
        }

        grid[0][0] = 1;

        if (n == 1) {
            return 1;
        }

        var depth = 2;
        while (toVis.Count > 0) {
            var m = toVis.Count;
            for (var k = 0; k < m; ++k) {
                var p = toVis.Dequeue();
                for (var j = 0; j < 8; ++j) {
                    var nx = direciotns[j, 0] + p.X;
                    var ny = direciotns[j, 1] + p.Y;

                    if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;
                    if (grid[nx][ny] != 0) continue;
                    if (nx == n - 1 && ny == n - 1) {
                        return depth;
                    }

                    grid[nx][ny] = 1;
                    toVis.Enqueue(new Point(nx, ny));
                }
            }

            depth++;
        }

        return -1;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ShortestPathBinaryMatrix([
            [0, 1, 0, 0, 0, 0], [0, 1, 0, 1, 1, 0], [0, 1, 1, 0, 1, 0], [0, 0, 0, 0, 1, 0], [1, 1, 1, 1, 1, 0],
            [1, 1, 1, 1, 1, 0]
        ]));
        // Console.WriteLine(s.ShortestPathBinaryMatrix([[0, 1], [1, 0]]));
        // Console.WriteLine(s.ShortestPathBinaryMatrix([[0, 0, 0], [1, 1, 0], [1, 1, 0]]));
        // Console.WriteLine(s.ShortestPathBinaryMatrix([[1, 0, 0], [1, 1, 0], [1, 1, 0]]));
        // Console.WriteLine(s.ShortestPathBinaryMatrix([[0, 0, 0], [1, 1, 0], [1, 1, 1]]));
    }
}

//
// Created By zhiya At 2025/11/27 19:11:00
//