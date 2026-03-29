// problem: https://leetcode.cn/problems/graph-valid-tree/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo261;

using System;

public class Solution {
    private int[] parents;
    private int[] rank;

    private int find(int x) {
        while (x != parents[x]) x = parents[x];
        return x;
    }

    private bool unit(int a, int b) {
        if (rank[a] > rank[b]) {
            (a, b) = (b, a);
        }

        var pa = find(a);
        var pb = find(b);
        if (pa == pb) {
            return false;
        }

        parents[pa] = parents[pb];
        rank[pb] += rank[pa];
        return true;
    }


    public bool ValidTree(int n, int[][] edges) {
        var m = edges.Length;
        if (n != m + 1) return false;
        parents = new int[n];
        rank = new int[n];
        for (var i = 0; i < n; ++i) {
            parents[i] = i;
            rank[i] = 1;
        }

        for (var i = 0; i < m; ++i) {
            if (!unit(edges[i][0], edges[i][1])) return false;
        }

        return true;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ValidTree(5, [[0, 1], [0, 2], [0, 3], [1, 4]]));
        Console.WriteLine(s.ValidTree(5, [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]));
        Console.WriteLine(s.ValidTree(5, [[0, 4], [1, 2], [2, 3], [1, 3]]));
    }
}

//
// Created By ASUS At 12/2/2025 15:12:14
//