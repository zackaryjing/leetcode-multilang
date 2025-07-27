// problem: https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/?envType=daily-question&envId=2025-07-13
struct Solution;

// time spent 18:26

impl Solution {
    pub fn match_players_and_trainers(mut players: Vec<i32>, mut trainers: Vec<i32>) -> i32 {
        let mut p_index = players.len();
        let mut t_index = trainers.len();
        players.sort();
        trainers.sort();
        let mut cnt = 0;
        while p_index >= 1 && t_index >= 1 {
            while p_index >= 1 {
                p_index -= 1;
                if trainers[t_index - 1] >= players[p_index] {
                    cnt += 1;
                    break;
                }
            }
            t_index -= 1;
        }
        cnt
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::match_players_and_trainers(vec![4, 7, 9], vec![8, 2, 5, 8])
    );
    println!(
        "{:?}",
        Solution::match_players_and_trainers( vec![1,1,1],  vec![10])
    );
}

//
// Created by zhiya at 7/13/2025 10:56 AM
//
