// problem: https://leetcode.cn/problems/find-the-winner-of-the-circular-game/
struct Solution;

impl Solution {
    pub fn find_the_winner(n: i32, k: i32) -> i32 {
        let n = n as usize;
        let vis = vec![false; n];

        let nxt = |pos:usize| {
            0
        };
        for i in 0..n {
            let mut j = 0;

            for j in 0..k as usize {
                if !vis[(i + j) % n] {
                    0;
                }
            }
        }
        0
    }
}

fn main() {
    println!("{:?}", Solution::find_the_winner(10,10));
}

//
// Created by ASUS at 7/20/2025 9:31 PM
//