// problem: https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/?envType=problem-list-v2&envId=3rBpGyas 

using Utils;

namespace leetcodeNo865;

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
    private int mx = 0;
    private TreeNode ans = null;

    private int Dfs(TreeNode root, int depth) {
        if (depth > mx) {
            mx = depth;
            ans = root;
        }

        int ld = 0, rd = 0;
        if (root.left != null) {
            ld = Dfs(root.left, depth + 1);
        }

        if (root.right != null) {
            rd = Dfs(root.right, depth + 1);
        }

        if (ld == rd && ld == mx) {
            ans = root;
        }

        return int.Max(int.Max(rd, ld), depth);
    }

    public TreeNode SubtreeWithAllDeepest(TreeNode root) {
        Dfs(root, 0);
        return ans;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.SubtreeWithAllDeepest(TreeGenerator.StringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]")).val);
    }
}

//
// Created By jing At 12/8/25 18:12:34
//