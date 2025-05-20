// problem: https://leetcode.cn/problems/minimum-absolute-difference/description/

using System.Collections.Generic;
using System.Linq;
using System;

namespace leetcode_no1200;

public class Solution {
    public IList<IList<int>> MinimumAbsDifference(int[] arr) {
        Array.Sort(arr);
        var n = arr.Length;
        var minDist = int.MaxValue;
        IList<IList<int>> res = new List<IList<int>>();
        for (int i = 1; i < n; i++) {
            var diff = arr[i] - arr[i - 1];
            if (minDist > diff) {
                res.Clear();
                minDist = diff;
                res.Add([arr[i - 1], arr[i]]);
            }
            else if (minDist == diff) {
                res.Add([arr[i - 1], arr[i]]);
            }
        }

        return res;
    }

    public static void Run() {
        var sol = new Solution();
        int[] nums = { 4, 2, 1, 3 };
        IList<IList<int>> result = sol.MinimumAbsDifference(nums);
        Console.WriteLine("Result:" +
                          string.Join(", ", result.Select(pair => $"[{string.Join(",", pair)}]")));
        nums = [1, 3, 6, 10, 15];
        result = sol.MinimumAbsDifference(nums);
        Console.WriteLine("Result:" +
                          string.Join(", ", result.Select(pair => $"[{string.Join(",", pair)}]")));
    }
}


//
// Created By Zackary At 2025-05-20 12:38:59
//