// problem: https://leetcode.cn/problems/linked-list-components/?envType=problem-list-v2&envId=OOhHf3Bc 

using System.Collections.Generic;
using System.Linq;
using Utils;

namespace leetcodeNo817;

using System;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution2 {
    public int NumComponents(ListNode head, int[] nums) {
        int m = 1, ans = 0;
        var c = head;
        while ((c = c.next) != null)
            m++;
        var sets = new bool [m];
        for (var i = 0; i < nums.Length; ++i)
            sets[nums[i]] = true;
        var inset = false;
        for (var i = 0; i < m; i++, head = head.next) {
            if (sets[head.val])
                inset = true;
            else {
                if (inset) ans++;
                inset = false;
            }
        }

        if (inset) ans++;
        return ans;
    }
}

public class Solution {
    public int NumComponents(ListNode head, int[] nums) {
        int m = 1, ans = 0, last = head.val;
        var c = head;
        while ((c = c.next) != null) m++;
        var sets = new bool [m];
        for (var i = 0; i < nums.Length; ++i) sets[nums[i]] = true;
        for (var i = 0; i < m; i++, last = head.val, head = head.next)
            if (!sets[head.val] & sets[last])
                ans++;
        if (sets[last]) ans++;
        return ans;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.NumComponents(ListNode.ListToNode([0, 1, 2, 3, 4]), [0, 3, 1, 4]));
        Console.WriteLine(s.NumComponents(ListNode.ListToNode([0, 1, 2, 3]), [0, 1, 3]));
    }
}

//
// Created By ASUS At 12/7/2025 20:12:45
//