// problem: https://leetcode.cn/problems/inorder-successor-in-bst/?envType=problem-list-v2&envId=fMpGFr6b 

using Utils;

namespace leetcodeNo285;

using System;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private bool found = false;
    private TreeNode res = null;
    private int target;

    public void Dfs(TreeNode root) {
        if (target < root.val) {
            if (root.left != null) {
                Dfs(root.left);
            }
        }

        if (found) {
            res = root;
            found = false;
            return;
        }

        if (root.val == target) {
            found = true;
        }

        if (target >= root.val) {
            if (root.right != null) {
                Dfs(root.right);
            }
        }
    }

    public TreeNode InorderSuccessor(TreeNode root, TreeNode p) {
        target = p.val;
        Dfs(root);
        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        // Console.WriteLine(
        //     s.InorderSuccessor(TreeGenerator.StringToTreeNode("[5,3,6,2,4,null,null,1]"), new TreeNode(6)).val);
        Console.WriteLine(
            s.InorderSuccessor(TreeGenerator.StringToTreeNode("[2,1,3]"), new TreeNode(1)).val);
    }
}

//
// Created By ASUS At 12/5/2025 14:12:26
//