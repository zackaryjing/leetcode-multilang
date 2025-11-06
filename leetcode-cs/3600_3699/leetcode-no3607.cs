// problem: https://leetcode.cn/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo3607;

using System;

public class Solution {
    int[] _parent = [];
    private Dictionary<int, List<int>> _sameGroup = new Dictionary<int, List<int>>();
    private Dictionary<int, int> lastMin = new Dictionary<int, int>();

    public int Find(int x) {
        while (x != _parent[x]) {
            x = _parent[x];
        }

        return x;
    }

    public void Unit(int a, int b) {
        var pa = Find(a);
        var pb = Find(b);
        if (pa > pb) {
            _parent[pa] = pb;
            return;
        }

        _parent[pb] = pa;
    }

    public void Process() {
        for (var i = 0; i < _parent.Length; ++i) {
            var t = Find(i);

            if (!_sameGroup.TryAdd(t, [i])) {
                _sameGroup[t].Add(i);
            }

            lastMin.TryAdd(t, 0);

            _parent[i] = t;
        }

        foreach (var (k, v) in _sameGroup) {
            v.Sort();
        }
    }

    public int[] ProcessQueries(int c, int[][] connections, int[][] queries) {
        var isOff = new int[c];
        _parent = Enumerable.Range(0, c).ToArray();
        foreach (var connection in connections) {
            Unit(connection[0] - 1, connection[1] - 1);
        }

        Process();
        List<int> res = [];
        foreach (var query in queries) {
            var first = query[0];
            var second = query[1] - 1;
            if (first == 2) {
                isOff[second] = 1;
            } else {
                if (isOff[second] == 1) {
                    if (isOff[_parent[second]] == 1) {
                        bool found = false;
                        int groupId = _parent[second];
                        var group = _sameGroup[groupId];
                        for (int i = lastMin[groupId]; i < group.Count; ++i) {
                            var num = group[i];
                            if (isOff[num] == 0) {
                                res.Add(num + 1);
                                found = true;
                                lastMin[groupId] = i;
                                break;
                            }
                        }

                        if (!found) {
                            res.Add(-1);
                            lastMin[groupId] = group.Count;
                        }
                    } else {
                        res.Add(_parent[second] + 1);
                    }
                } else {
                    res.Add(second + 1);
                }
            }
        }

        return res.ToArray();
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        // Console.WriteLine(string.Join(" ", s.ProcessQueries(5, [[1, 2], [2, 3], [3, 4], [4, 5]],
        //     [[1, 3], [2, 1], [1, 1], [2, 2], [1, 2]])));
        // Console.WriteLine(string.Join(" ", s.ProcessQueries(3, [], [[1, 1], [2, 1], [1, 1]])));
        Console.WriteLine(string.Join(" ",
            s.ProcessQueries(2, [[2, 1]],
            [
                [1, 1], [1, 2], [2, 2], [2, 1], [2, 2], [2, 2], [2, 1], [1, 1], [2, 2], [2, 1], [1, 1], [2, 1], [2, 2],
                [1, 1], [1, 2], [1, 1], [1, 1], [2, 1], [1, 1], [2, 2], [2, 2], [2, 1], [1, 2], [2, 2], [1, 1], [2, 1],
                [2, 2], [2, 2], [1, 1], [2, 2]
            ])));
    }
}

//
// Created By zhiya At 2025/11/6 19:11:46
//