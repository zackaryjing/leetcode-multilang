// problem: https://leetcode.cn/problems/minimum-distance-between-bst-nodes/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo783;

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
    private int res = Int32.MaxValue;
    private int last = -1;

    public int MinDiffInBST(TreeNode root) {
        dfs(root);
        return res;
    }

    public void dfs(TreeNode root) {
        int cur = root.val;

        if (root.left != null) {
            dfs(root.left);
        }

        if (last >= 0) {
            res = int.Min(res, cur - last);
        }

        last = cur;
        if (root.right != null) {
            dfs(root.right);
        }
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinDiffInBST(TreeGenerator.StringToTreeNode("[4,2,6,1,3]")));
        var s2 = new Solution();
        Console.WriteLine(s2.MinDiffInBST(TreeGenerator.StringToTreeNode("[1,0,48,null,null,12,49]")));
    }
}

//
// Created By jing At 10/31/25 20:10:24
//