// problem: https://leetcode.cn/problems/maximum-number-of-operations-to-move-ones-to-the-end/?envType=daily-question&envId=2025-11-13 

using System.Collections.Generic;

namespace leetcodeNo3228;

using System;

public class Solution2 {
    public int MaxOperations(string s) {
        List<int> oneCnts = [];
        var cur = 0;
        var n = s.Length;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                cur += 1;
            } else if (cur != 0) {
                oneCnts.Add(cur);
                cur = 0;
            }
        }

        var res = 0;
        var m = oneCnts.Count;
        for (int i = 0; i < m; ++i) {
            res += oneCnts[i] * (m - i);
        }

        return res;
    }
}

public class Solution {
    public int MaxOperations(string s) {
        var cur = s[0] == '1' ? 1 : 0;
        var n = s.Length;
        var res = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') {
                cur += 1;
            } else if (cur != 0 && s[i - 1] == '1') {
                res += cur;
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MaxOperations("1001101"));
        Console.WriteLine(s.MaxOperations("00111"));
    }
}

//
// Created By jing At 11/13/25 17:11:27
//