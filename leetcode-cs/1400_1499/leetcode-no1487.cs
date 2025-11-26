// problem: https://leetcode.cn/problems/making-file-names-unique/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo1487;

using System;

public class Solution {
    // Copy and paste from leetcode official, I am an idiot;
    // f**k, I am an idiot!
    public string[] GetFolderNames(string[] names) {
        var index = new Dictionary<string, int>();
        var n = names.Length;
        var res = new string[n];
        for (var i = 0; i < n; ++i) {
            var name = names[i];
            if (index.TryAdd(name, 1)) {
                res[i] = name;
            } else {
                var k = index[name];
                while (index.ContainsKey($"{name}({k})")) {
                    k++;
                }

                res[i] = $"{name}({k})";
                index[name] = k + 1;
                index.Add($"{name}({k})", 1);
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        // Console.WriteLine(string.Join(" ", s.GetFolderNames(["kaido", "kaido(1)", "kaido", "kaido(1)"])));
        // Console.WriteLine(string.Join(" ", s.GetFolderNames(["wano", "wano", "wano", "wano"])));
        // Console.WriteLine(string.Join(" ",
        //     s.GetFolderNames(["onepiece", "onepiece(1)", "onepiece(2)", "onepiece(3)", "onepiece"])));
        // Console.WriteLine(string.Join(" ", s.GetFolderNames(["pes", "fifa", "gta", "pes(2019)"])));
        // Console.WriteLine(string.Join(" ", s.GetFolderNames(["kaido", "kaido(1)", "kaido", "kaido(1)", "kaido(2)"])));
        // Console.WriteLine(string.Join(" ", s.GetFolderNames(["kingston(0)", "kingston", "kingston"])));
        Console.WriteLine(string.Join(" ", s.GetFolderNames(["gta", "gta(1)", "gta", "avalon"])));
    }
}

// ended at 1:02AM

//
// Created By ASUS At 11/26/2025 15:11:53
//