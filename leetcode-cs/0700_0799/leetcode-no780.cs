// problem: https://leetcode.cn/problems/reaching-points/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo780;

using System;

public class Solution {
    public bool ReachingPoints(int sx, int sy, int tx, int ty) {
        // need redo
        while (tx > sx && sy < ty && tx != ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }

        return (tx == sx && ty == sy) ||
               ((tx - sx) % sy == 0 && tx > sx && ty == sy) ||
               ((ty - sy) % sx == 0 && ty > sy && tx == sx);
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ReachingPoints(1, 8, 4, 15));
        Console.WriteLine(s.ReachingPoints(9, 10, 9, 19));
        Console.WriteLine(s.ReachingPoints(1, 1, 3, 5));
        Console.WriteLine(s.ReachingPoints(1, 1, 2, 2));
        Console.WriteLine(s.ReachingPoints(1, 1, 1, 1));
    }
}

//
// Created By jing At 11/10/25 16:11:13
//