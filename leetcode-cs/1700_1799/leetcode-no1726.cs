// problem: https://leetcode.cn/problems/tuple-with-same-product/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;

namespace leetcodeNo1726;

using System;

public class Solution {
    // pass
    public int TupleSameProduct(int[] nums) {
        Dictionary<int, int> cnt = new();
        var n = nums.Length;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < i; ++j) {
                var t = nums[i] * nums[j];
                if (!cnt.TryAdd(t, 1)) {
                    cnt[t]++;
                }
            }
        }

        var res = 0;
        foreach (var item in cnt.Values) {
            res += item * (item - 1) * 4;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.TupleSameProduct([2, 3, 4, 6]));
        Console.WriteLine(s.TupleSameProduct([1, 2, 4, 5, 10]));
    }
}

//
// Created By jing At 12/26/25 22:04:12
//