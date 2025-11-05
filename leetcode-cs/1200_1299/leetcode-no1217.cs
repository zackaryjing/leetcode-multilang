// problem: https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1217;

using System;

public class Solution {
    public int MinCostToMoveChips(int[] position) {
        int[] cnt = new int[2];
        foreach (var i in position) {
            cnt[i % 2]++;
        }

        return int.Min(cnt[0], cnt[1]);
    }

    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinCostToMoveChips([2, 2, 2, 3, 3]));
        Console.WriteLine(s.MinCostToMoveChips([1, 2, 3]));
    }
}

//
// Created By jing At 10/30/25 21:10:10
//