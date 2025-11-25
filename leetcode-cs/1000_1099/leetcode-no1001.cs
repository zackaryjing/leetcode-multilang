// problem: https://leetcode.cn/problems/grid-illumination/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;
using System.IO;

namespace leetcodeNo1001;

using System;

public class Solution2 {
    private static void AddTomap(Dictionary<int, HashSet<long>> map, int key, long val) {
        if (!map.TryGetValue(key, out var set)) {
            set = new HashSet<long>();
            map[key] = set;
        }

        set.Add(val);
    }

    public int[] GridIllumination(int n, int[][] lamps, int[][] queries) {
        Dictionary<int, HashSet<long>> sum = [], diff = [], col = [], row = [];

        foreach (var lamp in lamps) {
            var expression = (long)lamp[0] << 32 | (long)lamp[1];
            int r = lamp[0], c = lamp[1];
            AddTomap(row, r, expression);
            AddTomap(col, c, expression);
            AddTomap(sum, r + c, expression);
            AddTomap(diff, r - c, expression);
        }


        int[][] dirs = [[0, 1], [1, 0], [-1, 0], [0, -1], [1, 1], [1, -1], [-1, 1], [-1, -1], [0, 0]];
        var m = queries.Length;
        var res = new List<int>(m);
        foreach (var query in queries) {
            var r = query[0];
            var c = query[1];
            var s = query[0] + query[1];
            var d = query[0] - query[1];
            if ((row.ContainsKey(r) && row[r].Count > 0) ||
                (col.ContainsKey(c) && col[c].Count > 0) ||
                (sum.ContainsKey(s) && sum[s].Count > 0) ||
                (diff.ContainsKey(d) && diff[d].Count > 0)) {
                res.Add(1);
            } else {
                res.Add(0);
            }

            foreach (var delta in dirs) {
                var nr = r + delta[0];
                var nc = c + delta[1];
                var nx = ((long)nr << 32) | (long)nc;
                var ns = s + delta[0] + delta[1];
                var nd = d + delta[0] - delta[1];
                if (row.TryGetValue(nr, out var value)) value.Remove(nx);

                if (col.TryGetValue(nc, out var value2)) value2.Remove(nx);

                if (sum.TryGetValue(ns, out var value3)) value3.Remove(nx);

                if (diff.TryGetValue(nd, out var value4)) value4.Remove(nx);
            }
        }

        return res.ToArray();
    }
}

public class Solution {
    // a lot faster
    private static readonly int[][] Dirs =
        [[0, 1], [1, 0], [-1, 0], [0, -1], [1, 1], [1, -1], [-1, 1], [-1, -1], [0, 0]];

    private static void TryMinusOne(Dictionary<int, int> map, int key) {
        map[key]--;
        if (map[key] == 0) {
            map.Remove(key);
        }
    }

    public int[] GridIllumination(int n, int[][] lamps, int[][] queries) {
        Dictionary<int, int> sum = [], diff = [], col = [], row = [];
        HashSet<long> points = [];

        foreach (var lamp in lamps) {
            var point = (long)lamp[0] << 32 | (long)lamp[1];
            if (points.Contains(point)) continue;
            int r = lamp[0], c = lamp[1];
            row[r] = row.GetValueOrDefault(r) + 1;
            col[c] = col.GetValueOrDefault(c) + 1;
            sum[r + c] = sum.GetValueOrDefault(r + c) + 1;
            diff[r - c] = diff.GetValueOrDefault(r - c) + 1;
            points.Add(point);
        }

        var m = queries.Length;
        var res = new List<int>(m);
        foreach (var query in queries) {
            var r = query[0];
            var c = query[1];
            var s = query[0] + query[1];
            var d = query[0] - query[1];
            if (row.GetValueOrDefault(r) > 0 ||
                col.GetValueOrDefault(c) > 0 ||
                sum.GetValueOrDefault(s) > 0 ||
                diff.GetValueOrDefault(d) > 0) {
                res.Add(1);
            } else {
                res.Add(0);
            }

            foreach (var delta in Dirs) {
                var nr = r + delta[0];
                var nc = c + delta[1];
                var nx = ((long)nr << 32) | (long)nc;
                if (!points.Contains(nx))
                    continue;
                points.Remove(nx);
                var ns = nr + nc;
                var nd = nr - nc;
                TryMinusOne(row, nr);
                TryMinusOne(col, nc);
                TryMinusOne(sum, ns);
                TryMinusOne(diff, nd);
            }
        }

        return res.ToArray();
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.GridIllumination(5, [[0, 0], [1, 0]], [[1, 1], [1, 1]])));
        Console.WriteLine(string.Join(" ", s.GridIllumination(5, [[0, 0], [4, 4]], [[1, 1], [1, 0]])));
        Console.WriteLine(string.Join(" ", s.GridIllumination(5, [[0, 0], [4, 4]], [[1, 1], [1, 1]])));
    }
}

//
// Created By jing At 11/11/25 21:11:01
//