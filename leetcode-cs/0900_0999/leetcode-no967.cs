// problem: https://leetcode.cn/problems/numbers-with-same-consecutive-differences/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo967;

using System;

public class Solution {
    private int _k;
    private List<int> res = [];

    public int[] NumsSameConsecDiff(int n, int k) {
        _k = k;
        for (int i = 1; i <= 9; ++i) {
            dfs(i, i, n - 1);
        }

        return res.ToArray();
    }

    public void dfs(int num, int added, int depth) {
        if (depth > 1) {
            if (added + _k <= 9) {
                dfs(num * 10 + added + _k, added + _k, depth - 1);
            }

            if (_k != 0 && added - _k >= 0) {
                dfs(num * 10 + added - _k, added - _k, depth - 1);
            }
        } else {
            if (added + _k <= 9) {
                res.Add(num * 10 + added + _k);
            }

            if (_k != 0 && added - _k >= 0) {
                res.Add(num * 10 + added - _k);
            }
        }
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.NumsSameConsecDiff(3, 7)));
        Console.WriteLine(string.Join(" ", s.NumsSameConsecDiff(2, 1)));
    }
}

//
// Created By jing At 11/5/25 18:11:02
//