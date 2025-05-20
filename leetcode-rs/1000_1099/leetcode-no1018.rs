// problem:
struct Solution;

impl Solution {
    pub fn prefixes_div_by5_2(nums: Vec<i32>) -> Vec<bool> {
        let n = nums.len();
        let mut res = vec![false; n];
        let mut cur = 0;
        for i in 0..n {
            cur <<= 1;
            cur |= nums[i];
            cur %= 5;
            res[i] = if cur == 0 { true } else { false };
        }
        res
    }
}
impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let n = nums.len();
        let mut cur = 0;
        let mut res = nums.iter().map(|num| {
            cur = ((cur << 1) | num) % 5;
            return cur == 0;
        }).collect();
        res
    }
}


fn main() {
    println!("{:?}", Solution::prefixes_div_by5(vec![0, 1, 1]));
    println!("{:?}", Solution::prefixes_div_by5(vec![1, 1, 1]));
    println!(
        "{:?}",
        Solution::prefixes_div_by5(vec![
            1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0,
            0, 0, 1, 1, 0, 1, 0, 0, 0, 1
        ])
    );
}

//
// Created by zhiya at 2025/4/17 20:46
//
