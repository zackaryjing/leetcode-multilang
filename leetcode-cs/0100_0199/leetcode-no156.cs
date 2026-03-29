// problem: https://leetcode.cn/problems/binary-tree-upside-down/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo156;

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
    private TreeNode newRoot;

    private void Dfs(TreeNode root) {
        newRoot = root;
        if (root.left != null) {
            Dfs(root.left);
            root.left.right = root;
        }

        if (root.right != null) {
            root.left.left = root.right;
        }

        root.right = null;
        root.left = null;
    }

    public TreeNode UpsideDownBinaryTree(TreeNode root) {
        if (root != null) {
            Dfs(root);
        }

        return newRoot;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        TreeGenerator.PrettyPrintTree(s.UpsideDownBinaryTree(TreeGenerator.StringToTreeNode("[1,2,3,4,5]")));
    }
}

//
// Created By ASUS At 11/30/2025 15:11:54
//