// problem: https://leetcode.cn/problems/zero-array-transformation-ii/?envType=daily-question&envId=2025-05-21

using System;
using System.Collections.Generic;

namespace leetcode_no3356;

public class Solution {
    public int MinZeroArray(int[] nums, int[][] queries) {
        var n = nums.Length;
        var m = queries.Length;
        var tot = 0;
        var pos = 0;
        var diffArr = new int[n + 1];
        for (var i = 0; i < n; ++i) {
            var num = nums[i];
            tot += diffArr[i];
            while (pos < m && tot < num) {
                diffArr[queries[pos][0]] += queries[pos][2];
                diffArr[queries[pos][1] + 1] -= queries[pos][2];
                if (queries[pos][0] <= i && queries[pos][1] >= i) {
                    tot += queries[pos][2];
                }
                ++pos;
            }
            if (tot < num) {
                return -1;
            }
        }
        return pos;
    }

    public static void Run() {
        var s = new Solution();
        Console.WriteLine($"{s.MinZeroArray([2, 0, 1], [[0, 2, 1], [0, 2, 1], [1, 1, 3]])}");
        Console.WriteLine($"{s.MinZeroArray([4, 3, 2, 1], [[1, 3, 2], [0, 2, 1]])}");
        Console.WriteLine($"{s.MinZeroArray([7, 6, 8], [[0, 0, 2], [0, 1, 5], [2, 2, 5], [0, 2, 4]])}");
        Console.WriteLine($"{s.MinZeroArray([5], [[0, 0, 5], [0, 0, 1], [0, 0, 3], [0, 0, 2]])}");
        Console.WriteLine($"{s.MinZeroArray([0], [[0, 0, 5], [0, 0, 1], [0, 0, 3], [0, 0, 2]])}");
    }
}

public class Solution_2 {
    // [TLE, MLE] failed, slow and heavy
    public int MinZeroArray(int[] nums, int[][] queries) {
        var n = nums.Length;
        var m = queries.Length;
        var diffVec = new int[n + 1];
        // for (var i = 0; i < m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         diffMatrix[i + 1, j] = diffMatrix[i, j];
        //     }
        //     diffMatrix[i + 1, queries[i][0]] += queries[i][2];
        //     diffMatrix[i + 1, queries[i][1] + 1] -= queries[i][2];
        // }
        var left = 0;
        var right = m;
        var valid = true;
        while (true) {
            var mid = (left + right) / 2;
            var temp = 0;
            valid = true;
            Array.Clear(diffVec, 0, diffVec.Length);
            for (var j = 0; j < mid; j++) {
                diffVec[queries[j][0]] += queries[j][2];
                diffVec[queries[j][1] + 1] -= queries[j][2];
            }
            for (var j = 0; j < n; j++) {
                temp += diffVec[j];
                if (temp < nums[j]) {
                    valid = false;
                    break;
                }
            }
            if (left == right) {
                break;
            }
            if (valid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left >= m && !valid) {
            return -1;
        }
        return left;
    }

    public static void Run() {
        var s = new Solution_2();
        Console.WriteLine($"{s.MinZeroArray([2, 0, 1], [[0, 2, 1], [0, 2, 1], [1, 1, 3]])}");
        Console.WriteLine($"{s.MinZeroArray([4, 3, 2, 1], [[1, 3, 2], [0, 2, 1]])}");
        Console.WriteLine($"{s.MinZeroArray([7, 6, 8], [[0, 0, 2], [0, 1, 5], [2, 2, 5], [0, 2, 4]])}");
        Console.WriteLine($"{s.MinZeroArray([5], [[0, 0, 5], [0, 0, 1], [0, 0, 3], [0, 0, 2]])}");
        Console.WriteLine($"{s.MinZeroArray([0], [[0, 0, 5], [0, 0, 1], [0, 0, 3], [0, 0, 2]])}");
    }
}

//
// Created By Zackary At 2025-05-21 10:45:30
//