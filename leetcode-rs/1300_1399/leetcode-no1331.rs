// problem: https://leetcode.cn/problems/rank-transform-of-an-array/
struct Solution;

impl Solution {
    pub fn array_rank_transform2(mut arr: Vec<i32>) -> Vec<i32> {
        if arr.len() == 0 {
            return vec![];
        }
        let mut pos_arr: Vec<(i32, usize)> = (0..arr.len())
            .into_iter()
            .map(|pos| {
                return (arr[pos], pos);
            })
            .collect();
        pos_arr.sort();
        let mut res = vec![0; arr.len()];
        let mut last_num = pos_arr[0].0 - 1;
        let mut index = 0;
        for (num, pos) in pos_arr {
            if num != last_num {
                index += 1;
            }
            res[pos] = index;
            last_num = num;
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::array_rank_transform(vec![37, 12, 28, 9, 100, 56, 80, 5, 12])
    );
}

//
// Created by jing at 2025-10-16 15:14
//
