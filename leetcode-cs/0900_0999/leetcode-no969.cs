// problem: https://leetcode.cn/problems/pancake-sorting/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;

namespace leetcodeNo969;

using System;

public class Solution2 {
    public IList<int> PancakeSort(int[] arr) {
        int n = arr.Length;
        var num2pos = new int[n];
        for (var i = 0; i < n; ++i) {
            arr[i]--;
            num2pos[arr[i]] = i;
        }

        List<int> res = new List<int>(2 * n);

        for (var i = n - 1; i >= 0; --i) {
            var pos = num2pos[i];
            res.Add(pos + 1);
            for (var j = 0; j <= pos; ++j) {
                num2pos[arr[j]] = pos - j;
            }

            for (var j = 0; j < (pos + 1) / 2; ++j) {
                (arr[j], arr[pos - j]) = (arr[pos - j], arr[j]);
            }

            res.Add(i + 1);
            for (var j = 0; j <= i; ++j) {
                num2pos[arr[j]] = i - j;
            }

            for (var j = 0; j < (i + 1) / 2; ++j) {
                (arr[j], arr[i - j]) = (arr[i - j], arr[j]);
            }
        }

        return res;
    }
}

public class Solution {
    public IList<int> PancakeSort(int[] arr) {
        var n = arr.Length;
        var num2Pos = new int[n];
        for (var i = 0; i < n; ++i) {
            arr[i]--;
            num2Pos[arr[i]] = i;
        }

        var res = new List<int>(2 * n);

        for (var i = n - 1; i >= 0; --i) {
            if (num2Pos[i] == i) {
                continue;
            }

            var pos = num2Pos[i];
            res.Add(pos + 1);
            for (var j = 0; j <= pos; ++j) {
                num2Pos[arr[j]] = pos - j;
            }

            for (var j = 0; j < (pos + 1) / 2; ++j) {
                (arr[j], arr[pos - j]) = (arr[pos - j], arr[j]);
            }

            res.Add(i + 1);
            for (var j = 0; j <= i; ++j) {
                num2Pos[arr[j]] = i - j;
            }

            for (var j = 0; j < (i + 1) / 2; ++j) {
                (arr[j], arr[i - j]) = (arr[i - j], arr[j]);
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.PancakeSort([3, 2, 4, 1])));
        Console.WriteLine(string.Join(" ", s.PancakeSort([1, 2, 3])));
    }
}

//
// Created By jing At 11/5/25 19:11:34
//