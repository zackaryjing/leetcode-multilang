// problem: https://leetcode.cn/problems/3sum-smaller/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Reflection.Metadata.Ecma335;

namespace leetcodeNo259;

using System;

public class Solution {
    public int ThreeSumSmaller(int[] nums, int target) {
        var cnt = new int[201];
        int n = nums.Length, mx = int.MinValue, mn = int.MaxValue, res = 0;
        if (n == 0) return 0;
        for (var i = 0; i < n; ++i) {
            var num = nums[i] + 100;
            cnt[num]++;
            if (num > mx) mx = num;
            if (num < mn) mn = num;
        }

        target += 299;
        for (var i = int.Min(target, mx); i >= mn; --i) {
            var a = cnt[i];
            if (a == 0) continue;
            for (var j = int.Min(target - i, i); j >= mn; --j) {
                var same = i == j;
                var (b, d2) = same ? (cnt[j] - 1, 2) : (cnt[j], 1);
                if (b <= 0) continue;

                for (var k = int.Min(target - i - j, j); k >= mn; --k) {
                    int c = cnt[k], d3 = d2;
                    if (j == k) {
                        --c;
                        if (same) {
                            --c;
                            d3 = 6;
                        } else d3 = 2;
                    }

                    if (c <= 0) continue;
                    res += a * b * c / d3;
                }
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ThreeSumSmaller([-1, 1, -1, -1], -1));
        Console.WriteLine(s.ThreeSumSmaller([-2, 0, 1, 3], 2));
        Console.WriteLine(s.ThreeSumSmaller([], 0));
        Console.WriteLine(s.ThreeSumSmaller([0], 0));
    }
}

//
// Created By ASUS At 12/2/2025 15:12:11
//