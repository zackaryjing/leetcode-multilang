// problem: https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1758;

using System;

public class Solution2 {
    public int MinOperations(string s) {
        var a = 0;
        var b = 0;
        for (int i = 0; i < s.Length; ++i) {
            if ((i & 1) == 1 && s[i] == '0' || (i & 1) != 1 && s[i] == '1') {
                a++;
            }

            if ((i & 1) == 1 && s[i] == '1' || (i & 1) != 1 && s[i] == '0') {
                b++;
            }
        }

        return int.Min(a, b);
    }
}

public class Solution3 {
    public int MinOperations(string s) {
        var a = 0;
        var b = 0;
        var m = false;
        foreach (var c in s) {
            if (m) {
                a += c == '0' ? 1 : 0;
                b += c == '1' ? 1 : 0;
            } else {
                a += c == '1' ? 1 : 0;
                b += c == '0' ? 1 : 0;
            }

            m = !m;
        }

        return int.Min(a, b);
    }
}

public class Solution {
    public int MinOperations(string s) {
        int a = 0, b = 0;
        for (var i = 0; i < s.Length; ++i) {
            a += (i & 1) == 1 ? s[i] & 1 : ~s[i] & 1;
            b += (i & 1) == 0 ? s[i] & 1 : ~s[i] & 1;
        }

        return int.Min(a, b);
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinOperations("0100"));
        Console.WriteLine(s.MinOperations("10"));
        Console.WriteLine(s.MinOperations("1111"));
    }
}

//
// Created By ASUS At 11/24/2025 02:11:33
//