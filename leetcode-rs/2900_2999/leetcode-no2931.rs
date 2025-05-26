// problem: https://leetcode.cn/problems/maximum-spending-after-buying-items/
struct Solution;

use std::cmp::Reverse;
use std::collections::BinaryHeap;
impl Solution {
    pub fn max_spending(values: Vec<Vec<i32>>) -> i64 {
        // val level
        let mut heap: BinaryHeap<Reverse<(i32, usize)>> = BinaryHeap::new();
        let n = values.len();
        let m = values[0].len();
        let mut pos = vec![m - 1; n];
        for i in 0..n {
            heap.push(Reverse((values[i][m - 1], i)));
        }
        let mut res = 0i64;
        let mut d = 1;
        while let Some(Reverse(top)) = heap.pop() {
            res += top.0 as i64 * d as i64;
            if pos[top.1] > 0 {
                heap.push((Reverse((values[top.1][pos[top.1] - 1], top.1))));
                pos[top.1] -= 1;
            }
            d += 1;
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::max_spending(vec![vec![8, 5, 2], vec![6, 4, 1], vec![9, 7, 3]])
    );
    println!();
    println!(
        "{:?}",
        Solution::max_spending(vec![vec![10, 8, 6, 4, 2], vec![9, 7, 5, 3, 2]])
    );
}

//
// Created by zhiya at 2025/5/26 19:13
//
