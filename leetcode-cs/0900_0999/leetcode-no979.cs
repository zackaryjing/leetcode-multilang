// problem: https://leetcode.cn/problems/distribute-coins-in-binary-tree/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo979;

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
    private int _res = 0;

    private (int, int) Dfs(TreeNode root) {
        var left = (0, 0);
        var right = (0, 0);
        if (root.left != null) {
            left = Dfs(root.left);
        }

        if (root.right != null) {
            right = Dfs(root.right);
        }

        _res += Math.Abs(left.Item1 - left.Item2);
        _res += Math.Abs(right.Item1 - right.Item2);

        return (left.Item1 + right.Item1 + root.val, left.Item2 + right.Item2 + 1);
    }

    public int DistributeCoins(TreeNode root) {
        _res = 0;
        Dfs(root);
        return _res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.DistributeCoins(TreeGenerator.StringToTreeNode("[0,3,0]")));
        Console.WriteLine(s.DistributeCoins(TreeGenerator.StringToTreeNode("[3,0,0]")));
    }
}

//
// Created By jing At 11/15/25 19:11:09
//