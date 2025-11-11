// problem: https://leetcode.cn/problems/sliding-puzzle/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;

namespace leetcodeNo773;

using System;

public class Solution {
    public int SlidingPuzzle(int[][] board) {
        var initStatus = 0;
        const int targetStatus = 0b000101100011010001;
        const int keyMask = 0b100100100100100100;
        for (var i = 0; i < 2; ++i) {
            for (var j = 0; j < 3; ++j) {
                initStatus |= board[i][j] << ((i * 3 + j) * 3);
            }
        }

        if (initStatus == targetStatus) {
            return 0;
        }

        var vis = new HashSet<int>([initStatus]);
        var statusQueue = new Queue<int>([initStatus]);
        var step = 1;
        while (statusQueue.Count > 0) {
            var nQueue = new Queue<int>();
            while (statusQueue.Count > 0) {
                var curStatus = statusQueue.Dequeue();
                var temp = ~curStatus;
                temp = temp & (temp << 1) & (temp << 2) & keyMask;
                var zMask = temp | temp >> 1 | temp >> 2;
                foreach (var shift in (List<int>)[9, 3, -3, -9]) {
                    if (zMask == 0b000000000111000000 && shift == 3) continue;
                    if (zMask == 0b000000111000000000 && shift == -3) continue;
                    int nxtStatus;

                    var thatMask = zMask << shift;
                    if (shift > 0) {
                        thatMask = zMask << shift;
                        nxtStatus = (curStatus & ~thatMask | ((curStatus & thatMask) >> shift)) & ~thatMask;
                    } else {
                        thatMask = (zMask >> -shift);
                        nxtStatus = (curStatus & ~thatMask | ((curStatus & thatMask) << -shift)) & ~thatMask;
                    }

                    if (thatMask is 0 or > 0b1000000000000000000) {
                        continue;
                    }

                    if (nxtStatus == targetStatus) {
                        return step;
                    }

                    if (!vis.Contains(nxtStatus)) {
                        nQueue.Enqueue(nxtStatus);
                        vis.Add(nxtStatus);
                    }
                }
            }

            step++;
            statusQueue = nQueue;
        }

        return -1;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.SlidingPuzzle([[1, 2, 3], [4, 0, 5]]));
        Console.WriteLine(s.SlidingPuzzle([[4, 1, 2], [5, 0, 3]]));
    }
}

//
// Created By jing At 11/11/25 15:11:53
//