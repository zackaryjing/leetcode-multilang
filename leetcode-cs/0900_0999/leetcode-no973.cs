// problem: https://leetcode.cn/problems/k-closest-points-to-origin/?envType=problem-list-v2&envId=3rBpGyas 

using System.Linq;

namespace leetcodeNo973;

using System;

public class Solution {
    public int[][] KClosest(int[][] points, int k) {
        Array.Sort(points,
            (p1, p2) => (p1[0] * p1[0] + p1[1] * p1[1]).CompareTo(p2[0] * p2[0] + p2[1] * p2[1]));
        return points.Take(k).ToArray();
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.KClosest([[1, 3], [-2, 2]], 1).Select(point => $"{point[0]},{point[1]}")));
        Console.WriteLine(string.Join(" ",
            s.KClosest([[3, 3], [5, -1], [-2, 4]], 2).Select(point => $"{point[0]},{point[1]}")));
    }
}

//
// Created By zhiya At 2025/11/6 23:11:41
//