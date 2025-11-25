// problem: https://leetcode.cn/problems/exam-room/ 

using System.Collections;
using System.Collections.Generic;

namespace leetcodeNo855;

using System;

public class ExamRoom {
    //(id,left,right) (left,(right - left + 1) / 2)
    private readonly PriorityQueue<(int, int, int), (int, int)> _q =
        new(Comparer<(int, int)>.Create((a, b) => {
                if (a.Item2 == b.Item2) {
                    return a.Item1.CompareTo(b.Item1);
                }

                return b.Item2.CompareTo(a.Item2);
            })
        );

    private int _curTime = 0;
    private int _curCnt;

    // mid,(id,right)
    private readonly Dictionary<int, (int, int)> _rightDivide = [];

    // mid,(id,left)
    private readonly Dictionary<int, (int, int)> _leftDivide = [];

    private readonly int _size = 0;

    // set<id>
    private readonly HashSet<int> _toBeRemove = [];

    private void AddFirst() {
        _q.Enqueue((++_curTime, -2 * _size + 2, 2 * _size - 2), (-2 * _size + 2, (4 * _size - 2) / 2));
        _leftDivide[0] = (-1, -1);
        _rightDivide[0] = (_curTime, _size - 1);
    }

    public ExamRoom(int n) {
        _size = n;
        AddFirst();
    }

    public int Seat() {
        int id = -1, left, right, mid;
        do {
            _toBeRemove.Remove(id);
            (id, left, right) = _q.Dequeue();
            mid = (left + right) / 2;
        } while (_toBeRemove.Contains(id) || mid < 0 || mid >= _size);

        _q.Enqueue((++_curTime, left, mid), (left, (mid - left) / 2));
        _leftDivide[mid] = (_curTime, left);
        _rightDivide[left] = (_curTime, mid);

        _q.Enqueue((++_curTime, mid, right), (mid, (right - mid) / 2));
        _rightDivide[mid] = (_curTime, right);
        _leftDivide[right] = (_curTime, mid);

        _curCnt++;
        return mid;
    }

    public void Leave(int p) {
        _curCnt--;
        var (leftId, left) = _leftDivide[p];
        var (rightId, right) = _rightDivide[p];
        _toBeRemove.Add(leftId);
        _toBeRemove.Add(rightId);
        if (_curCnt == 0) {
            AddFirst();
            return;
        }

        if (left < 0) left = -right;

        if (right >= _size) right = 2 * _size - 2 - left;

        _q.Enqueue((++_curTime, left, right), (left, (right - left) / 2));
        _leftDivide[right] = (_curTime, left);
        _rightDivide[left] = (_curTime, right);
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(n);
 * int param_1 = obj.Seat();
 * obj.Leave(p);
 */
public class Test {
    public static void Run() {
        test1();
        test2();
        test3();
        test4();
        test5();
    }

    static public void test5() {
        var s = new ExamRoom(1);
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 0");
    }

    static public void test4() {
        var s = new ExamRoom(10);
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 0");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 9");
        s.Leave(0);
        s.Leave(9);
        Console.WriteLine($"s.Leave(0) ");
        Console.WriteLine($"s.Leave(9) ");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 0");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 9");
    }

    static public void test1() {
        var s = new ExamRoom(10);
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 0");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 9");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 4");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 2");
        s.Leave(2);
        Console.WriteLine($"s.Leave(): ");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 2");
    }

    static public void test2() {
        var s = new ExamRoom(10);
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 0");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 9");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 4");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 2");
        s.Leave(0);
        Console.WriteLine("s.Leave(0)");
        s.Leave(4);
        Console.WriteLine("s.Leave(4)");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 5");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 0");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 7");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 1");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 3");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 4");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 6");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 8");
    }

    static public void test3() {
        var s = new ExamRoom(10);
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 0"); // 1
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 9"); // 2
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 4"); // 3
        s.Leave(0);
        Console.WriteLine("s.Leave(0)");
        s.Leave(4);
        Console.WriteLine("s.Leave(4)");
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 0"); // 6
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 4"); // 7
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 2"); // 8
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 6"); // 9
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 1"); //10
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 3"); //11
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 5"); //12
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 7"); //13
        Console.WriteLine($"s.Seat(): {s.Seat()} exp: 8"); //14
        s.Leave(0);
        Console.WriteLine("s.Leave(0)");
    }
}

//
// Created By jing At 11/12/25 16:11:17
//