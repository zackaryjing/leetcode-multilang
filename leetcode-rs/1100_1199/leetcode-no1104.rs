// problem: https://leetcode.cn/problems/path-in-zigzag-labelled-binary-tree/?envType=problem-list-v2&envId=3rBpGyas
struct Solution;

use std::collections::VecDeque;
use utils::treegenerator;
use utils::treegenerator::TreeNode;

impl Solution {
    pub fn path_in_zig_zag_tree(label: i32) -> Vec<i32> {
        let n = 31 - label.leading_zeros() as usize;
        let mut c = [label, ((3 << n) - 1 - label) >> 1];
        let mut res = vec![1; 1 + n];
        for i in 0..n {
            res[n - i] = c[i & 1];
            c[i & 1] >>= 2;
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::path_in_zig_zag_tree(14));
    println!("{:?}", Solution::path_in_zig_zag_tree(3));
    println!("{:?}", Solution::path_in_zig_zag_tree(26));
}

//
// Created by jing at 2025-12-16 20:09
//
