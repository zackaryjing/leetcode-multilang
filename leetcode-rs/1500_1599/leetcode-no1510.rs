// problem: https://leetcode.cn/problems/stone-game-iv/
struct Solution;

use std::collections::HashSet;
use std::hash::Hash;

impl Solution {
    pub fn winner_square_game(n: i32) -> bool {
        let mut non_valid: Vec<bool> = vec![true; (n + 1) as usize];
        for i in 0..=n {
            if non_valid[i as usize] {
                for j in 1.. {
                    let k = i + j * j;
                    if k <= n {
                        non_valid[k as usize] = false;
                    } else {
                        break;
                    }
                }
            }
        }
        !non_valid[n as usize]
    }
}

fn main() {
    println!("{:?}", Solution::winner_square_game(6));
    println!("{:?}", Solution::winner_square_game(7));
}

impl Solution {
    // [Pass] Perf
    pub fn winner_square_game_2(n: i32) -> bool {
        let mut valid: HashSet<i32> = HashSet::new();
        let mut non_valid: HashSet<i32> = HashSet::new();
        non_valid.insert(0);
        let sq = n.isqrt();
        let mut check = |num: i32| -> bool {
            for i in 1..=sq {
                if num >= i * i && non_valid.contains(&(num - i * i)) {
                    valid.insert(num);
                    return true;
                }
            }
            non_valid.insert(num);
            false
        };
        for i in 0..n {
            check(i);
        }
        check(n)
    }
}


//
// Created by zhiya at 2025/5/7 11:04
//
