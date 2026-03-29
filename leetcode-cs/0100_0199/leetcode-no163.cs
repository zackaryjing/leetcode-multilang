// problem: https://leetcode.cn/problems/missing-ranges/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo163;

using System;

public class Solution {
    public IList<IList<int>> FindMissingRanges(int[] nums, int lower, int upper) {
        var res = new List<IList<int>>();
        var n = nums.Length;
        if (n == 0) {
            res.Add(new List<int> { lower, upper });
            return res;
        }

        if (nums[0] > lower) {
            res.Add(new List<int> { lower, nums[0] - 1 });
        }

        var last = nums[0];
        for (var i = 1; i < n; ++i) {
            var cur = nums[i];
            if (cur > last + 1) {
                res.Add(new List<int> { last + 1, cur - 1 });
            }

            last = cur;
        }

        if (nums[n - 1] < upper) {
            res.Add(new List<int> { nums[n - 1] + 1, upper });
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ",
            s.FindMissingRanges([0, 1, 3, 50, 75], 0, 99).Select((list) => $"[{list[0]},{list[1]}]")));
        Console.WriteLine(string.Join(" ",
            s.FindMissingRanges([], 0, 99).Select((list) => $"[{list[0]},{list[1]}]")));
    }
}

//
// Created By ASUS At 11/30/2025 12:11:54
//