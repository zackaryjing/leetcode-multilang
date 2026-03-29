// problem: https://leetcode.cn/problems/count-univalue-subtrees/?envType=problem-list-v2&envId=fMpGFr6b 

using System.ComponentModel.Design;
using Utils;

namespace leetcodeNo250;

using System;

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
    private int res = 0;

    (bool, int) Dfs(TreeNode root) {
        bool valid1 = true, valid2 = true;
        int val1 = root.val, val2 = root.val;
        if (root.left != null) {
            (valid1, val1) = Dfs(root.left);
        }

        if (root.right != null) {
            (valid2, val2) = Dfs(root.right);
        }

        if (!valid1 || !valid2 || !(val1 == val2 && val2 == root.val))
            return (false, val1);
        res += 1;
        return (true, val1);
    }

    public int CountUnivalSubtrees(TreeNode root) {
        res = 0;
        if (root != null)
            Dfs(root);
        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CountUnivalSubtrees(TreeGenerator.StringToTreeNode("[5,1,5,5,5,null,5]")));
        Console.WriteLine(s.CountUnivalSubtrees(TreeGenerator.StringToTreeNode("[5,5,5,5,5,null,5]")));
    }
}

//
// Created By ASUS At 12/1/2025 14:12:38
//