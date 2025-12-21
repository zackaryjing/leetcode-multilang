// problem: https://leetcode.cn/problems/number-of-good-ways-to-split-a-string/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1525;

using System;
using System.Numerics;

public class Solution2 {
    // pass
    public int NumSplits(string s) {
        int n = s.Length, left = 0, right = n - 1;
        uint lcnt = 0, rcnt = 0;
        lcnt |= 1U << (s[left] - 'a');
        rcnt |= 1U << (s[right] - 'a');
        var res = 0;
        while (true) {
            var pleft = left;
            var pright = right;
            while (left < s.Length && ((lcnt >> (s[left] - 'a')) & 1) == 1)
                left++;

            while (right >= 0 && ((rcnt >> (s[right] - 'a')) & 1) == 1)
                right--;

            if (left < s.Length)
                lcnt |= 1U << (s[left] - 'a');
            if (right >= 0)
                rcnt |= 1U << (s[right] - 'a');
            if (right > left) continue;
            var l = int.Max(pleft, right);
            var r = int.Min(left, pright);
            res = r - l;
            break;
        }

        return res;
    }
}

public class Solution {
    // pass, strangest code ever
    public int NumSplits(string s) {
        int left = 0, right = s.Length - 1, lcnt = 0, rcnt = 0, pleft = 0, pright = 0;
        while (right > left) {
            (pleft, pright) = (left, right);
            while (left < s.Length && (lcnt ^ (lcnt |= 1 << (s[left] - 'a'))) == 0 && ++left >= 0) ;
            while (right >= 0 && (rcnt ^ (rcnt |= 1 << (s[right] - 'a'))) == 0 && --right < s.Length) ;
        }

        return int.Min(left, pright) - int.Max(pleft, right);
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.NumSplits("aacaba")); // 2
        Console.WriteLine(s.NumSplits("abcd")); // 1
        Console.WriteLine(s.NumSplits("aaaaa")); // 4
        Console.WriteLine(s.NumSplits("acbadbaada")); // 2
    }
}

//
// Created By ASUS At 12/20/2025 16:12:20
//