// problem: https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/?envType=problem-list-v2&envId=3rBpGyas
struct Solution;

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use utils::treegenerator::{TreeNode, string_to_tree_node};
use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        struct Calculator {
            res: i32,
        }
        impl Calculator {
            pub fn new() -> Self {
                Self { res: 0 }
            }
            pub fn dfs(&mut self, root: &Rc<RefCell<TreeNode>>, mut val: i32) {
                let mut has_child = false;
                val = (val << 1) + root.borrow().val;
                if let Some(left) = &root.borrow().left {
                    has_child = true;
                    self.dfs(left, val);
                }
                if let Some(right) = &root.borrow().right {
                    has_child = true;
                    self.dfs(right, val);
                }
                if !has_child {
                    self.res += val;
                }
            }
        }
        let mut c = Calculator::new();
        c.dfs(&root.unwrap(), 0);
        c.res
    }
}

fn main() {
    println!(
        "{:?} e:22",
        Solution::sum_root_to_leaf(string_to_tree_node("[1,0,1,0,1,0,1]"))
    );
    println!(
        "{:?} e:0",
        Solution::sum_root_to_leaf(string_to_tree_node("[0]"))
    );
}

//
// Created by jing at 2025-12-18 22:41
//
