// problem: https://leetcode.cn/problems/group-shifted-strings/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

namespace leetcodeNo249;

using System;

public class Solution {
    public IList<IList<string>> GroupStrings(string[] strings) {
        var position = new Dictionary<string, int>();
        var res = new List<IList<string>>();
        foreach (var s in strings) {
            var diff = s[0];
            var sb = new StringBuilder();
            foreach (var c in s) {
                sb.Append((char)((c - diff + 26) % 26));
            }

            var ts = sb.ToString();
            if (position.TryGetValue(ts, out var pos)) {
                res[pos].Add(s);
            } else {
                position[ts] = res.Count;
                res.Add([s]);
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join("\t",
            s.GroupStrings(["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]).Select((t) => string.Join(",", t))));
        Console.WriteLine(string.Join("\t",
            s.GroupStrings(["abc", "am"]).Select((t) => string.Join(",", t))));
    }
}

//
// Created By jing At 11/30/25 22:11:12
//