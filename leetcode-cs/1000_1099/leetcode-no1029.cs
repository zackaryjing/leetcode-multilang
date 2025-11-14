// problem:  

namespace leetcodeNo1029;

using System;

public class Solution {
    public int TwoCitySchedCost(int[][] costs) {
        var res = 0;
        var n = costs.Length / 2;
        Array.Sort(costs, (a, b) => (a[0] - a[1]).CompareTo(b[0] - b[1]));
        for (var i = 0; i < n; ++i) {
            res += costs[i][0];
        }

        for (var i = n; i < 2 * n; ++i) {
            res += costs[i][1];
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.TwoCitySchedCost([[10, 20], [30, 200], [400, 50], [30, 20]]));
        Console.WriteLine(s.TwoCitySchedCost([[259, 770], [448, 54], [926, 667], [184, 139], [840, 118], [577, 469]]));
        Console.WriteLine(s.TwoCitySchedCost([
            [515, 563], [451, 713], [537, 709], [343, 819], [855, 779], [457, 60], [650, 359], [631, 42]
        ]));
    }
}

//
// Created By jing At 11/12/25 21:11:25
//