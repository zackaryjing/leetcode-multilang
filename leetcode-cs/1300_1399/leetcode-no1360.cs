// problem: https://leetcode.cn/problems/number-of-days-between-two-dates/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1360;

using System;
using System.Linq;

public class Solution {
    public int DaysBetweenDates(string date1, string date2) {
        int baseYear = 1968;
        int[] monthDays = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
        int sum = 0;
        var monthDaysAccu = monthDays.Select(x => sum += x).ToArray();
        var time1 = date1.Split("-");
        var time2 = date2.Split("-");
        var (y1, m1, d1) = (int.Parse(time1[0]), int.Parse(time1[1]), int.Parse(time1[2]));
        var (y2, m2, d2) = (int.Parse(time2[0]), int.Parse(time2[1]), int.Parse(time2[2]));
        var toDay = (int y, int m, int d) => {
            var days = 0;
            var diff = y - baseYear;
            days += diff * 365;
            days += (diff + 3) / 4;
            days += monthDaysAccu[m - 1];
            if (y % 4 == 0 && m > 2 && !(y % 100 == 0 && y % 400 != 0)) days++;
            days += d;
            return days;
        };
        return Math.Abs(toDay(y1, m1, d1) - toDay(y2, m2, d2));
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        // Console.WriteLine(s.DaysBetweenDates("1968-01-01", "1969-01-01"));
        // Console.WriteLine(s.DaysBetweenDates("1972-01-01", "1970-01-01"));
        // Console.WriteLine(s.DaysBetweenDates("1971-01-01", "1970-01-01"));
        // Console.WriteLine(s.DaysBetweenDates("1973-01-01", "1974-01-01"));
        // Console.WriteLine(s.DaysBetweenDates("1980-01-01", "1990-01-01"));
        // Console.WriteLine(s.DaysBetweenDates("2000-01-01", "2010-01-01"));
        // Console.WriteLine(s.DaysBetweenDates("2019-06-29", "2019-06-30"));
        // Console.WriteLine(s.DaysBetweenDates("2020-01-15", "2019-12-31"));
        // Console.WriteLine(s.DaysBetweenDates("1981-01-28", "2054-10-18"));
        // Console.WriteLine(s.DaysBetweenDates("1971-06-29", "2010-09-23"));
        Console.WriteLine(s.DaysBetweenDates("1971-06-29", "2010-09-23") + " e14331");
        Console.WriteLine(s.DaysBetweenDates("2100-09-22", "1991-03-12") + " e40006");
    }
}

//
// Created By jing At 11/5/25 14:11:25
//