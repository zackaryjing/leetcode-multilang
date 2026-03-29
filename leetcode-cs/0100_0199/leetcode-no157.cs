// problem: https://leetcode.cn/problems/read-n-characters-given-read4/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo157;

using System;

/**
 * The Read4 API is defined in the parent class Reader4.
 *     int Read4(char[] buf4);
 */
public class Reader4 {
    public int Read4(char[] buf4) {
        buf4[0] = 'a';
        buf4[1] = 'b';
        buf4[2] = 'c';
        return 3;
    }
}

public class Solution : Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    public int Read(char[] buf, int n) {
        var pos = 0;
        while (pos < n) {
            var buf4 = new char[4];
            var cnt = Read4(buf4);
            if (cnt == 0) {
                break;
            }

            if (n - pos < 4 || cnt < 4) {
                for (var i = pos; i < int.Min(n, cnt + pos); ++i) {
                    buf[i] = buf4[i - pos];
                }

                pos += cnt;
                break;
            }

            buf4.CopyTo(buf, pos);
            pos += 4;
        }

        return int.Min(pos, n);
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        var buf = new char[4];
        var a = s.Read(buf, 4);
        Console.WriteLine($"a: {a}");
        Console.WriteLine(buf);
    }
}

//
// Created By ASUS At 12/2/2025 14:12:02
//