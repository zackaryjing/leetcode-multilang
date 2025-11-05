// problem: https://leetcode.cn/problems/unique-number-of-occurrences/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1207;

using System;

public class Solution {
    public bool UniqueOccurrences(int[] arr) {
        int[] occur = new int[2001];
        foreach (var num in arr) {
            occur[num + 1000]++;
        }

        bool[] times = new bool[2001];
        foreach (var num in occur) {
            if (num > 0 && times[num]) {
                return false;
            }

            times[num] = true;
        }

        return true;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.UniqueOccurrences([1, 2, 2, 1, 1, 3]));
        Console.WriteLine(s.UniqueOccurrences([1, 2]));
        Console.WriteLine(s.UniqueOccurrences([-3, 0, 1, -3, 1, 1, 1, -3, 10, 0]));
    }
}

//
// Created By jing At 11/4/25 21:11:58
//