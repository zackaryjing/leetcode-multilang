// problem:  https://leetcode.cn/problems/jump-game-v/

using System.Linq;

namespace leetcodeNo1340;

using System;

public class Solution2 {
    public int MaxJumps(int[] arr, int d) {
        var n = arr.Length;
        var sorted = arr.Select((num, pos) => (num, pos)).OrderBy((v) => v.num);
        var res = Enumerable.Repeat(1, n).ToArray();
        foreach (var (num, pos) in sorted) {
            var mx = num;
            for (var j = pos + 1; j <= int.Min(pos + d, n - 1); ++j) {
                if (arr[j] > mx) {
                    res[j] = int.Max(res[pos] + 1, res[j]);
                }

                mx = int.Max(arr[j], mx);
            }

            mx = num;
            for (var j = pos - 1; j >= int.Max(pos - d, 0); --j) {
                if (arr[j] > mx) {
                    res[j] = int.Max(res[pos] + 1, res[j]);
                }

                mx = int.Max(arr[j], mx);
            }
        }

        var ans = 1;
        foreach (var num in res) {
            ans = int.Max(ans, num);
        }

        return ans;
    }
}

public class Solution {
    public int MaxJumps(int[] arr, int d) {
        var n = arr.Length;
        var sorted = arr.Select((num, pos) => (num, pos)).ToList();
        sorted.Sort();
        var res = Enumerable.Repeat(1, n).ToArray();
        foreach (var (num, pos) in sorted) {
            var mx1 = num;
            var mx2 = num;
            var nxt = res[pos] + 1;
            for (var j = 1; j <= d; ++j) {
                var left = pos - j;
                var right = pos + j;
                if (left >= 0 && arr[left] > mx1) {
                    res[left] = int.Max(nxt, res[left]);
                    mx1 = int.Max(mx1, arr[left]);
                }

                if (right < n && arr[right] > mx2) {
                    res[right] = int.Max(nxt, res[right]);
                    mx2 = int.Max(mx2, arr[right]);
                }
            }
        }

        var ans = 1;
        foreach (var num in res) {
            ans = int.Max(ans, num);
        }

        return ans;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MaxJumps([6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12], 2)); // 4
        Console.WriteLine(s.MaxJumps([7, 6, 5, 4, 3, 2, 1], 1)); // 7
        Console.WriteLine(s.MaxJumps(
        [
            40, 98, 14, 22, 45, 71, 20, 19, 26, 9, 29, 64, 76, 66, 32, 79, 14, 83, 62, 39, 69, 25, 92, 79, 70, 34, 22,
            19, 41, 26, 5, 82, 38
        ], 6)); // 9
    }
}

//
// Created By jing At 11/18/25 17:11:39
//