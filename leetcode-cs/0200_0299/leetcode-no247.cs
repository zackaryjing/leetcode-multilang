// problem: https://leetcode.cn/problems/strobogrammatic-number-ii/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;

namespace leetcodeNo247;

using System;

public class Solution {
    // could do better if using mod operation and divide
    private readonly char[] available = ['0', '1', '6', '9', '8'];
    private readonly char[] reverse = ['0', '1', '9', '6', '8'];
    private readonly char[] center = ['0', '1', '8'];

    public IList<string> FindStrobogrammatic(int n) {
        int m = n / 2;
        var total = (int)Math.Pow(5, m);
        var list = new char[total][];
        if (n == 1) return ["0", "1", "8"];

        for (var i = 0; i < total; ++i) list[i] = new char[n];
        for (var i = 0; i < m; ++i) {
            for (var j = 1; j <= i + 1; ++j) {
                var length = total / (int)Math.Pow(5, j);
                var step = length * 5;
                for (var offset = 0; offset < 5; ++offset) {
                    for (var start = offset * length; start < total; start += step) {
                        var end = start + length;
                        for (var k = start; k < end; ++k) {
                            list[k][i] = available[offset];
                            list[k][n - i - 1] = reverse[offset];
                        }
                    }
                }
            }
        }

        List<string> res = [];
        if (n % 2 == 0) {
            for (var i = 0; i < total; ++i) {
                if (list[i][0] != '0') res.Add(new string(list[i]));
            }
        } else {
            for (var j = 0; j < 3; ++j) {
                for (var i = 0; i < total; ++i) {
                    list[i][m] = center[j];
                    if (list[i][0] != '0') res.Add(new string(list[i]));
                }
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.FindStrobogrammatic(5)));
        Console.WriteLine(string.Join(" ", s.FindStrobogrammatic(4)));
        Console.WriteLine(string.Join(" ", s.FindStrobogrammatic(3)));
        // Console.WriteLine(string.Join(" ", s.FindStrobogrammatic(2)));
        // Console.WriteLine(string.Join(" ", s.FindStrobogrammatic(1)));
    }
}

//
// Created By jing At 11/30/25 18:11:28
//