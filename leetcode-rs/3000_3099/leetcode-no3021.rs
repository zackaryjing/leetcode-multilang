// problem: https://leetcode.cn/problems/alice-and-bob-playing-flower-game/?envType=daily-question&envId=2025-08-29
struct Solution;

impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        let odd1 = (n as i64 + 1) / 2;
        let odd2 = (m as i64 + 1) / 2;
        let even1 = n as i64 / 2;
        let even2 = m as i64 / 2;
        odd1 * even2 + odd2 * even1
    }
}

fn main() {
    println!("{:?}", Solution::flower_game(3, 2));
    println!("{:?}", Solution::flower_game(1, 1));
}

//
// Created by jing at 2025-08-29 23:22
//
