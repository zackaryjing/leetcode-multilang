// problem: https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-subarrays/?envType=problem-list-v2&envId=3rBpGyas 

using System.Linq;

namespace leetcodeNo1406;

using System;

public class Solution2 {
    public bool CanBeEqual(int[] target, int[] arr) {
        Array.Sort(arr);
        Array.Sort(target);
        return target.SequenceEqual(arr);
    }
}

public class Solution {
    public bool CanBeEqual(int[] target, int[] arr) {
        var a = new int[1001];
        var b = new int[1001];
        foreach (var j in target) {
            a[j]++;
        }

        foreach (var j in arr) {
            b[j]++;
        }

        for (var i = 0; i <= 1000; ++i) {
            if (a[i] != b[i]) return false;
        }

        return true;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CanBeEqual([1, 2, 3, 4], [2, 4, 1, 3]));
    }
}

//
// Created By ASUS At 11/14/2025 01:11:30
//