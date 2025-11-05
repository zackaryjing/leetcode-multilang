// problem: https://leetcode.cn/problems/get-equal-substrings-within-budget/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1208;

using System;

public class Solution {
    public int EqualSubstring(string s, string t, int maxCost) {
        var origin = Math.Abs(s[0] - t[0]);
        var valid = maxCost >= origin;
        int first = valid ? 0 : 1, second = 1;
        var n = s.Length;
        var cur = valid ? origin : 0;
        var res = valid ? 1 : 0;
        while (second < n) {
            Console.WriteLine($"cur: {cur}");
            Console.WriteLine($"res: {res}");

            cur += Math.Abs(t[second] - s[second]);
            if (cur <= maxCost) {
                res = int.Max(res, second - first + 1);
            }

            while (first <= second && cur > maxCost) {
                cur -= t[first] - s[first];
                first++;
            }

            second++;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.EqualSubstring("abcd", "bcdf", 3));
        Console.WriteLine(s.EqualSubstring("abcd", "cdef", 3));
        Console.WriteLine(s.EqualSubstring("abcd", "acde", 0));
        Console.WriteLine(s.EqualSubstring("krrgw", "zjxss", 19));
        Console.WriteLine(s.EqualSubstring("ujteygggjwxnfl", "nstsenrzttikoy", 43));
    }
}

//
// Created By jing At 11/4/25 21:11:06
//