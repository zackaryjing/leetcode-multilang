// problem: https://leetcode.cn/problems/encode-and-decode-strings/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace leetcodeNo271;

using System;

public class Codec {
    // Encodes a list of strings to a single string.
    public string encode(IList<string> strs) {
        var sb = new StringBuilder();
        sb.Append((char)strs.Count);
        for (var i = 0; i < strs.Count; ++i) sb.Append((char)strs[i].Length);

        for (var i = 0; i < strs.Count; ++i) sb.Append(strs[i]);

        return sb.ToString();
    }

    // Decodes a single string to a list of strings.
    public IList<string> decode(string s) {
        int cnt = s[0];
        var cnts = new int[cnt];
        for (var i = 0; i < cnt; ++i) cnts[i] = s[i + 1];

        var res = new List<string>();
        var pos = cnt + 1;
        for (var i = 0; i < cnt; ++i) {
            res.Add(s.Substring(pos, cnts[i]));
            pos += cnts[i];
        }

        return res;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));

public class Test {
    public static void Run() {
        var s = new Codec();
        var tmp = s.encode(["Hello", "World"]);
        Console.WriteLine($"tmp: {tmp}");
        Console.WriteLine($"tmp.Length: {tmp.Length}");
        Console.WriteLine(string.Join(" ", s.decode(tmp)));
    }
}

//
// Created By ASUS At 12/3/2025 23:12:01
//