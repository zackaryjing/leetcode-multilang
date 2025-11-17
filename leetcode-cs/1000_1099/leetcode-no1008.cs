// problem: https://leetcode.cn/problems/construct-binary-search-tree-from-preorder-traversal/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;

namespace leetcodeNo1008;

using System;
using Utils;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode BstFromPreorder(int[] preorder) {
        Stack<TreeNode> treeSt = [];
        var dummy = new TreeNode();
        var last = dummy;
        foreach (var t in preorder) {
            if (treeSt.Count > 0 && t > last.val) {
                while (treeSt.Count > 0 && t > treeSt.Peek().val) {
                    last = treeSt.Pop();
                }

                last.right = new TreeNode(t);
                treeSt.Push(last.right);
                last = last.right;
            } else {
                last.left = new TreeNode(t);
                treeSt.Push(last.left);
                last = last.left;
            }
        }

        return dummy.left;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(
            TreeGenerator.TreeNodeToString(s.BstFromPreorder([8, 5, 1, 7, 10, 12])));
        Console.WriteLine(
            TreeGenerator.TreeNodeToString(s.BstFromPreorder([1, 3])));
    }
}

//
// Created By jing At 11/15/25 21:11:35
//