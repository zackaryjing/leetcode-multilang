class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;

  TreeNode([this.val = 0, this.left, this.right]);
}

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */
class Solution {
  bool isCousins(TreeNode? root, int x, int y) {
    this.x = x;
    this.y = y;
    if (root != null) {
      findpos(root, 1, 0);
    }
    // print("x_location ${x_location![0] ~/ 2} y_location: ${y_location![0] ~/ 2}");
    return x_location != null &&
        y_location != null &&
        x_location![1] == y_location![1] &&
        x_location![0] ~/ 2 != y_location![0] ~/ 2;
  }

  int x = 0, y = 0;
  List<int>? x_location, y_location;

  void findpos(TreeNode root, int pos, int level) {
    // print('val: ${root.val}');
    if (root.val != x && root.val != y) {
      if (root.left != null) {
        findpos(root.left!, pos * 2, level + 1);
      }
      if (root.right != null) {
        findpos(root.right!, pos * 2 + 1, level + 1);
      }
    } else {
      if (root.val == x) {
        x_location = [pos, level];
        return;
      }
      if (root.val == y) {
        y_location = [pos, level];
        return;
      }
    }
  }
}

void main() {
  // 创建测试二叉树
  TreeNode root = TreeNode(1);
  root.left = TreeNode(2);
  root.right = TreeNode(3);
  root.left!.left = TreeNode(4);
  root.left!.right = TreeNode(5);
  root.right!.left = TreeNode(6);
  root.right!.right = TreeNode(7);

  Solution solution = Solution();

  // 测试 isCousins 方法
  print(solution.isCousins(root, 4, 5)); // false
  print(solution.isCousins(root, 4, 6)); // true
  print(solution.isCousins(root, 3, 7)); // false
}

//          0
//        1  2
//      3 4 5 6
//    7 8

//          1
//        2  3
//      4 5 6 7
//    8 9
