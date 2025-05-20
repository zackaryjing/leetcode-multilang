// problem: https://leetcode.cn/problems/build-array-from-permutation/?envType=daily-question&envId=2025-05-06
struct Solution;

macro_rules! result {
    ( $x:expr ) => {{
        let n = $x.len();
        let mut res = vec![0; n];
        for (index, num) in $x.iter().enumerate() {
            res[index] = $x[*num as usize];
        }
        res
    }};
}

impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        result!(nums)
    }
}

fn main() {
    println!("{:?}", Solution::build_array(vec![0, 2, 1, 5, 3, 4]));
}

//
// Created by zhiya at 2025/5/6 14:16
//
