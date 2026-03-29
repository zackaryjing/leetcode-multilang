// problem: https://leetcode.cn/problems/meeting-rooms/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;
using System.Runtime.Versioning;

namespace leetcodeNo252;

using System;

public class Solution {
    public bool CanAttendMeetings(int[][] intervals) {
        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));

        var n = intervals.Length;
        if (n == 0) {
            return true;
        }

        var prevE = intervals[0][1];

        for (var i = 1; i < n; ++i) {
            var temp = intervals[i];
            if (temp[0] < prevE) {
                return false;
            }

            prevE = temp[1];
        }

        return true;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CanAttendMeetings([[0, 30], [5, 10], [15, 20]]));
        Console.WriteLine(s.CanAttendMeetings([[7, 10], [2, 4]]));
    }
}

//
// Created By ASUS At 12/1/2025 16:12:06
//