// problem: https://leetcode.cn/problems/find-the-celebrity/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;

namespace leetcodeNo277;

using System;

/* The Knows API is defined in the parent class Relation.
      bool Knows(int a, int b); */
public class Relation {
    public bool Knows(int a, int b) {
        // if (a == 0 && b == 1) return true;
        // if (a == 1 && b == 0) return false;
        // if (a == 1 && b == 2) return false;
        // if (a == 2 && b == 1) return true;
        // if (a == 2 && b == 0) return true;
        // if (a == 0 && b == 1) return false;
        if (a == 0 && b == 1) return false;
        if (a == 1 && b == 0) return true;
        if (a == 1 && b == 2) return false;
        if (a == 2 && b == 1) return true;
        if (a == 2 && b == 0) return false;
        if (a == 0 && b == 1) return true;
        return true;
    }
}

public class Solution2 : Relation {
    public int FindCelebrity(int n) {
        var nonCand = new HashSet<int>();
        var cand = new HashSet<int>();
        for (var nx = 0; nx < n; ++nx) {
            List<int> toBeRemove = new();
            bool canBeAdd = true;
            foreach (var nc in nonCand) {
                if (canBeAdd && Knows(nx, nc)) {
                    canBeAdd = false;
                    break;
                }
            }

            foreach (var c in cand) {
                if (Knows(c, nx)) {
                    toBeRemove.Add(c);
                    nonCand.Add(c);
                }

                if (Knows(nx, c)) {
                    canBeAdd = false;
                }
            }

            for (var j = 0; j < toBeRemove.Count; ++j) {
                cand.Remove(toBeRemove[j]);
            }

            if (canBeAdd) cand.Add(nx);
            else nonCand.Add(nx);
        }

        if (cand.Count != 1) return -1;
        var res = cand.First();
        for (var i = 0; i < n; ++i) {
            if (!Knows(i, res)) {
                return -1;
            }
        }

        return res;
    }
}

public class Solution : Relation {
    public int FindCelebrity(int n) {
        var nonCand = new HashSet<int>();
        var cand = new HashSet<int>();
        for (var nx = 0; nx < n; ++nx) {
            List<int> toBeRemove = [];
            var canBeAdd = true;
            foreach (var nc in nonCand) {
                if (canBeAdd && (Knows(nx, nc) || !Knows(nc, nx)))
                    canBeAdd = false;
            }

            foreach (var c in cand) {
                var a = Knows(c, nx);
                var b = Knows(nx, c);
                if (a || !b) toBeRemove.Add(c);
                if (b || !a) canBeAdd = false;
            }

            for (var j = 0; j < toBeRemove.Count; ++j) {
                cand.Remove(toBeRemove[j]);
                nonCand.Add(toBeRemove[j]);
            }

            if (canBeAdd) cand.Add(nx);
            else nonCand.Add(nx);
        }

        if (cand.Count != 1) return -1;
        var res = cand.First();
        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.FindCelebrity(3));
    }
}

//
// Created By ASUS At 12/4/2025 17:12:56
//