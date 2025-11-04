// problem: https://leetcode.cn/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2025-11-03 

using System.Linq;

namespace leetcodeNo1578;

using System;

public class Solution {
    public int MinCost(string colors, int[] neededTime) {
        var n = colors.Length;
        var sameColorTime = neededTime[0];
        var mxSameColorTime = neededTime[0];
        var res = 0;
        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                mxSameColorTime = int.Max(neededTime[i], mxSameColorTime);
                sameColorTime += neededTime[i];
            } else {
                res += sameColorTime - mxSameColorTime;
                sameColorTime = neededTime[i];
                mxSameColorTime = neededTime[i];
            }
        }

        res += sameColorTime - mxSameColorTime;
        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinCost("abaac", [1, 2, 3, 4, 5]));
        Console.WriteLine(s.MinCost("abc", [1, 2, 3]));
    }
}

//
// Created By jing At 11/3/25 15:11:12
//