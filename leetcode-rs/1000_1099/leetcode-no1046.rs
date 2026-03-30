// problem: https://leetcode.cn/problems/last-stone-weight/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

use std::collections::BinaryHeap;
impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        let mut cnt = stones.len();
        let mut stbh: BinaryHeap<i32> = BinaryHeap::from(stones);
        while cnt > 1 {
            let a = stbh.pop().unwrap();
            let b = stbh.pop().unwrap();
            if a != b {
                stbh.push((a - b).abs());
                cnt += 1;
            }
            cnt -= 2;
        }
        if cnt == 0 { 0 } else { stbh.pop().unwrap() }
    }
}

fn main() {
    println!("{:?}", Solution::last_stone_weight(vec![2, 7, 4, 1, 8, 1]));
}

//
// Created by zhiya at 2026/3/29 22:42
//
