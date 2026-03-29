// problem: https://leetcode.cn/problems/zigzag-iterator/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;

namespace leetcodeNo281;

using System;

public class ZigzagIterator {
    private IList<int> _v1;
    private IList<int> _v2;
    int p1 = 0;
    int p2 = 0;
    private int l1 = 0;
    private int l2 = 0;
    int cur = 1;

    public ZigzagIterator(IList<int> v1, IList<int> v2) {
        l1 = v1.Count;
        l2 = v2.Count;
        _v1 = v1;
        _v2 = v2;
        if (l1 != 0) cur = 0;
    }

    public bool HasNext() {
        if (p1 < l1 || p2 < l2) {
            return true;
        }

        return false;
    }

    public int Next() {
        int res;
        if (cur == 0) {
            res = _v1[p1];
            p1++;
            if (p2 < l2) {
                cur = 1;
            }
        } else {
            res = _v2[p2];
            p2++;
            if (p1 < l1) {
                cur = 0;
            }
        }

        return res;
    }
}

/**
 * Your ZigzagIterator will be called like this:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.HasNext()) v[f()] = i.Next();
 */
public class Test {
    public static void Run() {
        var s = new ZigzagIterator([1, 2], [3, 4, 5, 6]);
        Console.WriteLine(s.Next());
        Console.WriteLine(s.Next());
        Console.WriteLine(s.Next());
        Console.WriteLine(s.Next());
    }
}

//
// Created By ASUS At 12/4/2025 00:12:12
//