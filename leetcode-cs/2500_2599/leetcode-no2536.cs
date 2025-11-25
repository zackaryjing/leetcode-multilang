// problem: https://leetcode.cn/problems/increment-submatrices-by-one/?envType=daily-question&envId=2025-11-14 

using System.Linq;

namespace leetcodeNo2536;

using System;

public class Solution {
    public int[][] RangeAddQueries(int n, int[][] queries) {
        var res = new int[n][];
        var diff = new int[n + 2, n + 2];
        for (var i = 0; i < n; ++i) {
            res[i] = new int[n];
        }

        foreach (var query in queries) {
            var x1 = query[0] + 1;
            var y1 = query[1] + 1;
            var x2 = query[2] + 1;
            var y2 = query[3] + 1;
            diff[x1, y1]++;
            diff[x1, y2 + 1]--;
            diff[x2 + 1, y1]--;
            diff[x2 + 1, y2 + 1]++;
        }

        for (int i = 0; i < n; ++i) {
            diff[i + 1, 1] += diff[i, 1];
            res[i][0] = diff[i + 1, 1];
            for (int j = 1; j < n; ++j) {
                diff[i + 1, j + 1] += diff[i, j + 1];
                res[i][j] = res[i][j - 1] + diff[i + 1, j + 1];
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join("\n", s.RangeAddQueries(
            3, [[1, 1, 2, 2], [0, 0, 1, 1]]
        ).Select(nums => string.Join(" ", nums))));
        Console.WriteLine(string.Join("\n", s.RangeAddQueries(
            2, [[0, 0, 1, 1]]
        ).Select(nums => string.Join(" ", nums))));
    }
}

//
// Created By jing At 11/14/25 19:11:57
//