// problem: https://leetcode.cn/problems/longest-turbulent-subarray/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo978;

using System;

public class Solution2 {
    public int MaxTurbulenceSize(int[] arr) {
        if (arr.Length == 1) return 1;
        var cur = 1;
        var last = arr[1] < arr[0];
        var res = 1;
        for (int i = 1; i < arr.Length; ++i) {
            if (arr[i] == arr[i - 1]) {
                res = int.Max(res, cur);
                cur = 1;
            } else {
                if (cur == 1) cur++;
                else if (arr[i] > arr[i - 1] != last) {
                    cur++;
                } else {
                    res = int.Max(res, cur);
                    cur = 2;
                }

                last = arr[i] > arr[i - 1];
            }
        }

        res = int.Max(res, cur);
        return res;
    }
}

public class Solution {
    public int MaxTurbulenceSize(int[] arr) {
        if (arr.Length == 1) return 1;
        var cur = 1;
        var last = arr[1] < arr[0];
        var res = 1;
        var prev = arr[0];
        for (var i = 1; i < arr.Length; ++i) {
            var c = arr[i];
            if (c == prev) {
                res = int.Max(res, cur);
                cur = 1;
            } else {
                if (cur == 1 || c > prev != last) cur++;
                else {
                    res = int.Max(res, cur);
                    cur = 2;
                }

                last = c > prev;
            }

            prev = c;
        }

        res = int.Max(res, cur);
        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MaxTurbulenceSize([9, 4, 2, 10, 7, 8, 8, 1, 9]));
        Console.WriteLine(s.MaxTurbulenceSize([4, 8, 12, 16]));
        Console.WriteLine(s.MaxTurbulenceSize([100]));
        Console.WriteLine(s.MaxTurbulenceSize([9, 9]));
    }
}

//
// Created By ASUS At 11/24/2025 14:11:24
//