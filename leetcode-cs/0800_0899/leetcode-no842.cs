// problem: https://leetcode.cn/problems/split-array-into-fibonacci-sequence/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo842;

using System;

public class Solution2 {
    private static int CountDigits(long x) {
        if (x >= 1000000000) return 10;
        if (x >= 100000000) return 9;
        if (x >= 10000000) return 8;
        if (x >= 1000000) return 7;
        if (x >= 100000) return 6;
        if (x >= 10000) return 5;
        if (x >= 1000) return 4;
        if (x >= 100) return 3;
        if (x >= 10) return 2;
        return 1;
    }

    private string _num;
    private int _m;

    private List<int> check(int pos, long first, long second) {
        var third = first + second;
        if (third > int.MaxValue) return [];
        var n = CountDigits(third);
        if (pos + n > _m) {
            return [];
        }

        List<int> res = [];
        var temp = Int64.Parse(_num.Substring(pos, n));
        if (temp > int.MaxValue) return [];
        if (temp == third) {
            if (pos + n == _m) {
                return [(int)third];
            }

            if (pos + n < _m) {
                res = check(pos + n, second, third);
                if (res.Count > 0) {
                    res.Add((int)third);
                }
            }
        }

        return res;
    }

    public IList<int> SplitIntoFibonacci(string num) {
        _m = num.Length;
        _num = num;
        if (num.StartsWith("00")) {
            foreach (var c in num) {
                if (c != '0') {
                    return [];
                }
            }

            return Enumerable.Repeat(0, _m).ToList();
        }

        var limit = 10;
        if (num[0] == '0') {
            limit = 1;
        }

        List<int> res = [];
        for (int i = 1; i <= int.Min(_m / 2, int.Min(limit, 10)); ++i) {
            var first = Int64.Parse(num[..i]);
            if (first > Int32.MaxValue) break;

            var limit2 = 10;
            if (num[i] == '0') {
                limit2 = 1;
            }

            for (int j = 1; j <= limit2; ++j) {
                if (i + j >= _m) {
                    break;
                }

                var second = Int64.Parse(num[i..(i + j)]);
                if (second > Int32.MaxValue) break;
                res = check(i + j, first, second);
                if (res.Count > 0) {
                    res.Add((int)second);
                    res.Add((int)first);
                    res.Reverse();
                    return res;
                }
            }
        }

        return [];
    }
}

public class Solution {
    private int CountDigits(long x) {
        int c = 1;
        while (x >= 10) {
            x /= 10;
            c++;
        }

        return c;
    }

    long Parse(string s, int start, int len) {
        long v = 0;
        for (int k = 0; k < len; k++) {
            v = v * 10 + (s[start + k] - '0');
            if (v > int.MaxValue) return -1;
        }

        return v;
    }


    public IList<int> SplitIntoFibonacci(string num) {
        int m = num.Length;
        if (num.StartsWith("00")) {
            foreach (var c in num) {
                if (c != '0') {
                    return [];
                }
            }

            return Enumerable.Repeat(0, m).ToList();
        }

        var limit = 10;
        if (num[0] == '0') {
            limit = 1;
        }

        for (int i = 1; i <= int.Min(m / 2, int.Min(limit, 10)); ++i) {
            var firstOrigin = Parse(num, 0, i);
            if (firstOrigin > Int32.MaxValue) break;

            var limit2 = 10;
            if (num[i] == '0') {
                limit2 = 1;
            }

            for (int j = 1; j <= limit2; ++j) {
                if (i + j >= m) {
                    break;
                }

                var secondOrigin = Parse(num, i, j);
                if (secondOrigin > Int32.MaxValue) break;

                var first = firstOrigin;
                var second = secondOrigin;

                var pos = i + j;
                List<int> seq = [(int)first, (int)second];
                while (true) {
                    var third = first + second;
                    if (third > int.MaxValue) break;
                    var n = CountDigits(third);
                    if (pos + n > m) {
                        break;
                    }

                    var temp = Parse(num, pos, n);
                    if (temp > int.MaxValue) break;
                    if (temp == third) {
                        seq.Add((int)third);
                        if (pos + n == m) {
                            return seq;
                        }
                    } else {
                        break;
                    }

                    first = second;
                    second = third;
                    pos += n;
                }
            }
        }

        return [];
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("112358130")));
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("123456579")));
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("0000")));
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("0224")));
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("5511816597")));
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("214748364721474836422147483641")));
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("74912134825162255812723932620170946950766784234934")));
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("1023")));
        Console.WriteLine(string.Join(" ", s.SplitIntoFibonacci("1101111")));
        Console.WriteLine(string.Join(" ",
            s.SplitIntoFibonacci("1320581321313221264343965566089105744171833277577")));
    }
}

//
// Created By jing At 11/14/25 21:11:57
//