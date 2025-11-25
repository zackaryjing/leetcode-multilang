// problem: https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo1253;

using System;

public class Solution {
    public IList<IList<int>> ReconstructMatrix(int upper, int lower, int[] colsum) {
        var cnt = 0;
        var n = colsum.Length;
        IList<IList<int>> res = [new int[n], new int[n]];
        int totalColSum = 0;
        for (var j = 0; j < n; ++j) {
            totalColSum += colsum[j];
            if (colsum[j] == 2) {
                res[0][j] = 1;
                res[1][j] = 1;
                colsum[j] = 0;
                cnt++;
            }
        }

        if (totalColSum != upper + lower || cnt > upper || cnt > lower || upper > (totalColSum - cnt) ||
            lower > (totalColSum - cnt)) {
            return [];
        }

        var i = 0;
        for (; cnt < upper; ++i) {
            if (colsum[i] > 0) {
                res[0][i] = 1;
                cnt += 1;
            }
        }

        for (; i < n; ++i) {
            if (colsum[i] > 0) {
                res[1][i] = 1;
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(",", s.ReconstructMatrix(2, 1, [1, 1, 1]).Select(x => string.Join(" ", x))));
        Console.WriteLine(string.Join(",", s.ReconstructMatrix(2, 3, [2, 2, 1, 1]).Select(x => string.Join(" ", x))));
        Console.WriteLine(string.Join(",",
            s.ReconstructMatrix(5, 5, [2, 1, 2, 0, 1, 0, 1, 2, 0, 1]).Select(x => string.Join(" ", x))));
        Console.WriteLine(string.Join(",",
            s.ReconstructMatrix(9, 2, [0, 1, 2, 0, 0, 0, 0, 0, 2, 1, 2, 1, 2]).Select(x => string.Join(" ", x))));
    }
}

//
// Created By ASUS At 11/8/2025 16:11:58
//