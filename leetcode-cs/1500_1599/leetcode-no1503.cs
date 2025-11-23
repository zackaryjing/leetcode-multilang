// problem: https://leetcode.cn/problems/last-moment-before-all-ants-fall-out-of-a-plank/?envType=problem-list-v2&envId=3rBpGyas 

using System.Linq;

namespace leetcodeNo1503;

using System;

public class Solution2 {
    // slow
    public int GetLastMoment(int n, int[] left, int[] right) {
        var res = left.Aggregate(0, int.Max);

        return right.Aggregate(res, (current, r) => int.Max(current, n - r));
    }
}

public class Solution {
    // fast
    public int GetLastMoment(int n, int[] left, int[] right) {
        int res = 0;
        foreach (var l in left) {
            res = int.Max(res, l);
        }

        foreach (var r in right) {
            res = int.Max(res, n - r);
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.GetLastMoment(4, [4, 3], [0, 1]));
        Console.WriteLine(s.GetLastMoment(7, [0, 1, 2, 3, 4, 5, 6, 7], []));
        Console.WriteLine(s.GetLastMoment(7, [], [0, 1, 2, 3, 4, 5, 6, 7]));
    }
}

//
// Created By ASUS At 11/19/2025 15:11:21
//