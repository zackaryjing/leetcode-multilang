// problem: https://leetcode.cn/problems/split-a-string-in-balanced-strings/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1221;

using System;

public class Solution {
    public int BalancedStringSplit(string s) {
        int state = 0;
        int res = 0;
        for (int i = 0; i < s.Length; ++i) {
            state += (s[i] != 'R') ? 1 : -1;
            res += state == 0 ? 1 : 0;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.BalancedStringSplit("RLRRLLRLRL"));
        Console.WriteLine(s.BalancedStringSplit("RLRRRLLRLL"));
        Console.WriteLine(s.BalancedStringSplit("LLLLRRRR"));
    }
}

//
// Created By jing At 11/3/25 22:11:56
//