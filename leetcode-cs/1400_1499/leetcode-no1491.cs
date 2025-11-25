// problem: https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1491;

using System;

public class Solution {
    public double Average(int[] salary) {
        var n = salary.Length;
        var mx = salary[0];
        var mn = salary[1];
        var mid = 0;
        if (salary[1] > salary[0]) {
            mx = salary[1];
            mn = salary[0];
        }

        for (var i = 2; i < n; ++i) {
            if (salary[i] > mx) {
                mid += mx;
                mx = salary[i];
            } else if (salary[i] < mn) {
                mid += mn;
                mn = salary[i];
            } else {
                mid += salary[i];
            }
        }

        return (double)mid / (n - 2);
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.Average([1, 2, 3]));
    }
}

//
// Created By ASUS At 11/25/2025 23:11:22
//