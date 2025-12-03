// problem: https://leetcode.cn/problems/closest-binary-search-tree-value/?envType=problem-list-v2&envId=fMpGFr6b 

using Utils;

namespace leetcodeNo270;

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
    public int ClosestValue(TreeNode root, double target) {
        int upper = root.val;
        int lower = root.val;
        while (true) {
            if (root.val > target) {
                upper = root.val;
                if (root.left != null) {
                    root = root.left;
                } else break;
            } else if (root.val < target) {
                lower = root.val;
                if (root.right != null) {
                    root = root.right;
                } else break;
            } else {
                return root.val;
            }
        }

        // Console.WriteLine($"upper: {upper}");
        // Console.WriteLine($"lower: {lower}");

        return double.Abs(upper - target) > double.Abs(lower - target) ? lower : upper;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ClosestValue(TreeGenerator.StringToTreeNode("[4,2,5,1,3]"), 3.714286));
        Console.WriteLine(s.ClosestValue(TreeGenerator.StringToTreeNode("[1,null,2]"), 3.714286));
    }
}

//
// Created By ASUS At 12/3/2025 19:12:30
//