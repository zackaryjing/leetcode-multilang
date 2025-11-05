// problem: https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/?envType=problem-list-v2&envId=3rBpGyas 

using System.Linq;
using System.Numerics;

namespace leetcodeNo1252;

using System;

public class Solution {
    public int OddCells(int m, int n, int[][] indices) {
        Int64 row = 0;
        Int64 column = 0;
        foreach (var t in indices) {
            row ^= 1L << t[0];
            column ^= 1L << t[1];
        }

        var rowOdd = BitOperations.PopCount((ulong)row);
        var columnOdd = BitOperations.PopCount((ulong)column);
        return rowOdd * (n - columnOdd) + columnOdd * (m - rowOdd);
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.OddCells(2, 3, [[0, 1], [1, 1]]));
        Console.WriteLine(s.OddCells(2, 2, [[1, 1], [0, 0]]));
    }
}

//
// Created By jing At 11/3/25 17:11:57
//