// problem: https://leetcode.cn/problems/flip-game/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo293;

using System;

public class Solution {
    public IList<string> GeneratePossibleNextMoves(string currentState) {
        var cs = currentState.ToCharArray();
        var res = new List<string>();
        for (var i = 1; i < cs.Length; ++i) {
            if (cs[i - 1] == '+' && cs[i] == '+') {
                cs[i - 1] = '-';
                cs[i] = '-';
                res.Add(new string(cs));
                cs[i - 1] = '+';
                cs[i] = '+';
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.GeneratePossibleNextMoves("++++")));
    }
}

//
// Created By ASUS At 12/5/2025 23:12:20
//