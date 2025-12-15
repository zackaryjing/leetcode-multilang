// problem: https://leetcode.cn/problems/coupon-code-validator/?envType=daily-question&envId=2025-12-13 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo3606;

using System;

public class Solution {
    private bool isValidCode(string s) {
        if (s.Length == 0) return false;
        foreach (var c in s) {
            if (c is (< 'a' or > 'z') and (< 'A' or > 'Z') and (< '0' or > '9') and not '_') {
                return false;
            }
        }

        return true;
    }

    private int isValidBusiness(string s) {
        return s switch {
            "electronics" => 0,
            "grocery" => 1,
            "pharmacy" => 2,
            "restaurant" => 3,
            _ => 4
        };
    }

    public IList<string> ValidateCoupons(string[] code, string[] businessLine, bool[] isActive) {
        List<string>[] ans = [[], [], [], []];
        for (var i = 0; i < code.Length; ++i) {
            var t = isValidBusiness(businessLine[i]);
            if (t < 4 && isValidCode(code[i]) && isActive[i]) {
                ans[t].Add(code[i]);
            }
        }

        List<string> res = [];
        for (var i = 0; i < 4; ++i) {
            ans[i].Sort(StringComparer.Ordinal);
            res.AddRange(ans[i]);
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.ValidateCoupons(
            ["SAVE20", "", "PHARMA5", "SAVE@20"], ["restaurant", "grocery", "pharmacy", "restaurant"],
            [true, true, true, true]
        )));
    }
}

//
// Created By jing At 12/13/25 16:32:22
//