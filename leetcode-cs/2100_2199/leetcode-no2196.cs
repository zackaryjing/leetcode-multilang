// problem: https://leetcode.cn/problems/create-binary-tree-from-descriptions/ 

using System.Collections.Generic;
using System.Linq;
using Utils;

namespace leetcodeNo2196;

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
    public TreeNode CreateBinaryTree(int[][] descriptions) {
        var shown = new Dictionary<int, TreeNode>();
        var asChild = new HashSet<int>();
        for (var i = 0; i < descriptions.Length; ++i) {
            var desc = descriptions[i];
            TreeNode child, parent;
            int pv = desc[0], cv = desc[1];
            asChild.Add(cv);
            if (shown.TryGetValue(pv, out var valueP)) {
                parent = valueP;
            } else {
                parent = new TreeNode(pv);
                shown[pv] = parent;
            }

            if (shown.TryGetValue(cv, out var valueC)) {
                child = valueC;
            } else {
                child = new TreeNode(cv);
                shown[cv] = child;
            }

            if (desc[2] == 1)
                parent.left = child;
            else
                parent.right = child;
        }

        foreach (var kv in shown) {
            if (!asChild.Contains(kv.Key))
                return kv.Value;
        }

        return new TreeNode(0);
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        TreeGenerator.PrettyPrintTree(s.CreateBinaryTree([
            [20, 15, 1], [20, 17, 0], [50, 20, 1], [50, 80, 0], [80, 19, 1]
        ]));

        TreeGenerator.PrettyPrintTree(s.CreateBinaryTree([
            [1, 2, 1], [2, 3, 0], [3, 4, 1]
        ]));
    }
}

//
// Created By jing At 12/21/25 16:09:48
//