// problem: https://leetcode.cn/problems/meeting-rooms-ii/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Transactions;

namespace leetcodeNo253;

using System;

public class Solution2 {
    // actually better
    public int MinMeetingRooms(int[][] intervals) {
        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));
        var n = intervals.Length;
        if (n == 0) return 0;
        var st = new PriorityQueue<int, int>();
        st.Enqueue(int.MaxValue, int.MaxValue);
        var res = 0;
        for (var i = 0; i < n; ++i) {
            var start = intervals[i][0];
            var end = intervals[i][1];
            st.Enqueue(end, end);
            while (st.Peek() <= start) st.Dequeue();
            res = int.Max(res, st.Count - 1);
        }

        return res;
    }
}

public class Solution {
    public int MinMeetingRooms(int[][] intervals) {
        var n = intervals.Length;
        if (n == 0) return 0;
        int[] startList = new int[n], endList = new int[n];
        for (var i = 0; i < n; ++i) {
            startList[i] = intervals[i][0];
            endList[i] = intervals[i][1];
        }

        Array.Sort(startList);
        Array.Sort(endList);
        int res = 0, spos = 0, epos = 0;
        while (spos < n) {
            var end = endList[epos];
            while (spos < n && startList[spos] < end) spos++;
            res = int.Max(res, spos - epos);
            if (spos >= n) continue;
            var start = startList[spos];
            while (epos < n && endList[epos] <= start) epos++;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinMeetingRooms([[0, 30], [5, 10], [15, 20]]));
        Console.WriteLine(s.MinMeetingRooms([[7, 10], [2, 4]]));
        Console.WriteLine(s.MinMeetingRooms([[13, 15], [1, 13]]));
    }
}

//
// Created By ASUS At 12/1/2025 16:12:04
//