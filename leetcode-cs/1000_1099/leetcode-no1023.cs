// problem:  

using System.Collections.Generic;

namespace leetcodeNo1023;

using System;

public class Solution {
    public IList<bool> CamelMatch(string[] queries, string pattern) {
        int m = queries.Length;
        var res = new List<bool>(m);
        int n = pattern.Length;
        foreach (var query in queries) {
            int l = query.Length;
            if (l < n) {
                res.Add(false);
                continue;
            }

            var index = 0;
            var valid = true;
            for (var j = 0; j < l; ++j) {
                if (index < n && query[j] == pattern[index]) {
                    index++;
                } else {
                    if (query[j] > 'z' || query[j] < 'a') {
                        valid = false;
                        break;
                    }
                }
            }

            if (index != n) {
                valid = false;
            }

            res.Add(valid);
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ",
            s.CamelMatch(["FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"], "FB")));
        Console.WriteLine(string.Join(" ",
            s.CamelMatch(["FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"], "FoBa")));
        Console.WriteLine(string.Join(" ",
            s.CamelMatch(["FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"], "FoBaT")));
    }
}

// True False True True False
// True False True False False
// True True True False False


//
// Created By jing At 11/12/25 21:11:40
//