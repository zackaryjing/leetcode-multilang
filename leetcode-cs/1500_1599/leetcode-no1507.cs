// problem: https://leetcode.cn/problems/reformat-date/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;

namespace leetcodeNo1507;

using System;

public class Solution {
    public string ReformatDate(string date) {
        var month = new Dictionary<string, string> {
            { "Jan", "01" },
            { "Feb", "02" },
            { "Mar", "03" },
            { "Apr", "04" },
            { "May", "05" },
            { "Jun", "06" },
            { "Jul", "07" },
            { "Aug", "08" },
            { "Sep", "09" },
            { "Oct", "10" },
            { "Nov", "11" },
            { "Dec", "12" }
        };
        var parts = date.Split(" ");
        var day = parts[0][..^2];
        return parts[2] + "-" + month[parts[1]] + "-" + (day.Length == 1 ? "0" : "") + day;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ReformatDate("6th Jun 1933"));
        Console.WriteLine(s.ReformatDate("26th May 1960"));
    }
}

//
// Created By ASUS At 11/26/2025 00:11:24
//