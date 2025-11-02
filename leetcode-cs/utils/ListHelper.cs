using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Utils {
    public static class ListHelper {
        public static void PrintIList(IList<IList<int>> matrix) {
            foreach (var row in matrix) {
                Console.WriteLine(string.Join(" ", row));
            }
        }
    }

    public class TreeNode {
        public int val;
        public TreeNode left;
        public TreeNode right;

        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public static class TreeGenerator {
        // 将二叉树转为字符串（层序遍历）
        public static string TreeNodeToString(TreeNode root) {
            if (root == null)
                return "[]";

            var sb = new StringBuilder();
            var q = new Queue<TreeNode>();
            q.Enqueue(root);

            while (q.Count > 0) {
                var node = q.Dequeue();
                if (node == null) {
                    sb.Append("null, ");
                    continue;
                }

                sb.Append(node.val).Append(", ");
                q.Enqueue(node.left);
                q.Enqueue(node.right);
            }

            // 去掉最后的多余逗号和空格
            if (sb.Length >= 2)
                sb.Length -= 2;

            return "[" + sb.ToString() + "]";
        }

        // 从字符串构造二叉树，如 "[1,2,3,null,4]"
        public static TreeNode StringToTreeNode(string input) {
            input = input.Trim();
            if (input.Length < 2 || input == "[]")
                return null;

            // 去掉前后方括号
            input = input.Substring(1, input.Length - 2);
            if (string.IsNullOrWhiteSpace(input))
                return null;

            var parts = input.Split(',', StringSplitOptions.RemoveEmptyEntries)
                .Select(s => s.Trim()).ToList();

            var root = new TreeNode(int.Parse(parts[0]));
            var queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            int index = 1;

            while (queue.Count > 0 && index < parts.Count) {
                var node = queue.Dequeue();

                // 左节点
                if (index < parts.Count && parts[index] != "null") {
                    node.left = new TreeNode(int.Parse(parts[index]));
                    queue.Enqueue(node.left);
                }

                index++;

                // 右节点
                if (index < parts.Count && parts[index] != "null") {
                    node.right = new TreeNode(int.Parse(parts[index]));
                    queue.Enqueue(node.right);
                }

                index++;
            }

            return root;
        }

        // 打印树的结构（类似 prettyPrintTree）
        public static void PrettyPrintTree(TreeNode node, string prefix = "", bool isLeft = true) {
            if (node == null) {
                Console.WriteLine("Empty tree");
                return;
            }

            if (node.right != null)
                PrettyPrintTree(node.right, prefix + (isLeft ? "│   " : "    "), false);

            Console.WriteLine(prefix + (isLeft ? "└── " : "┌── ") + node.val);

            if (node.left != null)
                PrettyPrintTree(node.left, prefix + (isLeft ? "    " : "│   "), true);
        }
    }
}