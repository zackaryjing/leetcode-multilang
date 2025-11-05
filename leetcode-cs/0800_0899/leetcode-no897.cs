// problem: https://leetcode.cn/problems/increasing-order-search-tree/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo897;

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
    private TreeNode last = null;
    private TreeNode nroot = null;

    public TreeNode IncreasingBST(TreeNode root) {
        dfs(root);
        return nroot;
    }

    public void dfs(TreeNode root) {
        if (root.left != null)
            dfs(root.left);
        root.left = null;
        if (last != null)
            last.right = root;
        else
            nroot = root;
        last = root;
        if (root.right != null)
            dfs(root.right);
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        TreeGenerator.PrettyPrintTree(
            s.IncreasingBST(TreeGenerator.StringToTreeNode("[5,3,6,2,4,null,8,1,null,null,null,7,9]")));
        var s2 = new Solution();
        TreeGenerator.PrettyPrintTree(s2.IncreasingBST(TreeGenerator.StringToTreeNode("[5,1,7]")));
    }
}

//
// Created By jing At 11/1/25 15:11:10
//