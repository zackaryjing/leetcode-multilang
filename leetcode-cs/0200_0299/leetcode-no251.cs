// problem: https://leetcode.cn/problems/flatten-2d-vector/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo251;

using System;

public class Vector2D {
    private int[][] _vec;
    private int n = 0;
    private int m = 0;
    private int i = 0;
    private int j = 0;


    public Vector2D(int[][] vec) {
        _vec = vec;
        n = vec.Length;
        if (n > 0) {
            m = vec[0].Length;
        }
    }

    public void toNonEmpty() {
        while (j >= m && i < n) {
            i++;
            if (i < n) {
                m = _vec[i].Length;
            } else {
                m = 0;
            }

            j = 0;
        }
    }

    public int Next() {
        toNonEmpty();

        var res = _vec[i][j];
        j++;

        return res;
    }

    public bool HasNext() {
        toNonEmpty();
        if (i < n && j < m) {
            return true;
        }

        return false;
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(vec);
 * int param_1 = obj.Next();
 * bool param_2 = obj.HasNext();
 */
public class Test {
    public static void Run() {
        var s = new Vector2D([[1, 2], [3], [4]]);
        Console.WriteLine($"s.Next(): {s.Next()}");
        Console.WriteLine($"s.Next(): {s.Next()}");
        Console.WriteLine($"s.Next(): {s.Next()}");
        Console.WriteLine($"s.HasNext(): {s.HasNext()}");
        Console.WriteLine($"s.HasNext(): {s.HasNext()}");
        Console.WriteLine($"s.Next(): {s.Next()}");
        Console.WriteLine($"s.HasNext(): {s.HasNext()}");
    }
}

//
// Created By ASUS At 12/1/2025 00:12:07
//