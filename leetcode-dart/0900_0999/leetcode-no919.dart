/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */

import 'dart:collection';
class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;

  TreeNode([this.val = 0, this.left, this.right]);
}

class CBTInserter {
  late TreeNode _root;
  Queue<TreeNode> queue = Queue();

  CBTInserter(TreeNode? root) {
    _root = root!;
    bfs(root);
  }

  void bfs(TreeNode root) {
    Queue<TreeNode> toVis = Queue();
    toVis.addFirst(root);
    while (!toVis.isEmpty) {
      root = toVis.first;
      toVis.removeFirst();
      bool noLeft = true;
      bool noRight = true;
      if (root.left != null) {
        toVis.addLast(root.left!);
        noLeft = false;
      }
      if (root.right != null) {
        toVis.addLast(root.right!);
        noRight = false;
      }
      if (noLeft || noRight) {
        queue.add(root);
      }
    }
  }

  int insert(int val) {
    var parent = queue.first;
    if (parent.left != null) {
      parent.right = TreeNode(val);
      queue.addLast(parent.right!);
      queue.removeFirst();
    } else {
      parent.left = TreeNode(val);
      queue.addLast(parent.left!);
    }
    return parent.val;
  }

  TreeNode? get_root() {
    return _root;
  }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = CBTInserter(root);
 * int param1 = obj.insert(val);
 * TreeNode? param2 = obj.get_root();
 */
