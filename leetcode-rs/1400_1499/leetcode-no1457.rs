// problem: https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/
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

use utils::treegenerator::{TreeNode, pretty_print_tree, string_to_tree_node};

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn pseudo_palindromic_paths(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        struct Finder {
            res: i32,
            path: Vec<i32>,
        }
        impl Finder {
            pub fn new() -> Self {
                Self {
                    res: 0,
                    path: vec![0; 10],
                }
            }
            pub fn dfs(&mut self, root: &Rc<RefCell<TreeNode>>) {
                let mut has_child = false;
                let value = root.borrow().val as usize;
                self.path[value] += 1;
                if let Some(left) = &root.borrow().left {
                    has_child = true;
                    self.dfs(left);
                }
                if let Some(right) = &root.borrow().right {
                    has_child = true;
                    self.dfs(right)
                }
                if !has_child {
                    // println!("{:?}", self.path);
                    let mut odd_cnt = 0;
                    for i in 0..10 {
                        if self.path[i] & 1 == 1 {
                            odd_cnt += 1;
                        }
                    }
                    if odd_cnt <= 1 {
                        self.res += 1;
                    }
                }
                self.path[value] -= 1;
            }
        }
        let mut finder = Finder::new();
        finder.dfs(&root.unwrap());
        finder.res
    }
}

fn main() {
    let tn = string_to_tree_node("[2,3,1,3,1,null,1]");
    pretty_print_tree(&tn, "".to_string(), true);
    println!("{:?}", Solution::pseudo_palindromic_paths(tn));
}

//
// Created by jing at 2025-09-15 13:13
//
