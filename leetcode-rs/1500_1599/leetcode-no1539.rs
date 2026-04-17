// problem: https://leetcode.cn/problems/kth-missing-positive-number/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

impl Solution {
    pub fn find_kth_positive(arr: Vec<i32>, k: i32) -> i32 {
        for i in 0..arr.len() {
            if arr[i] - i as i32 - 1 >= k {
                return i as i32 + k;
            }
        }
        arr.len() as i32 + k
    }
}

fn main() {
    println!("{:?}", Solution::find_kth_positive(vec![2, 3, 4, 7, 11], 5));
    println!("{:?}", Solution::find_kth_positive(vec![1, 2, 3, 4], 2));
}

//
// Created by jing at 2026-04-14 22:43
//
