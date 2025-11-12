// problem: https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/?envType=problem-list-v2&envId=3rBpGyas 

using System.Linq;

namespace leetcodeNo1665;

using System;

public class Solution {
    public int MinimumEffort(int[][] tasks) {
        Array.Sort(tasks, (a, b) => (a[1] - a[0]).CompareTo(b[1] - b[0]));

        return tasks.Aggregate(int.MaxValue, (current, task) => int.Max(current + task[0], task[1]));
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinimumEffort([[1, 2], [2, 4], [4, 8]]));
    }
}

//
// Created By ASUS At 11/9/2025 22:11:30
//