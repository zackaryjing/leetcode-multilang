// problem: https://leetcode.cn/problems/add-to-array-form-of-integer/
struct Solution;

impl Solution {
    pub fn add_to_array_form(num: Vec<i32>, k: i32) -> Vec<i32> {
        let n = num.len();
        let mut k = k;
        let mut res = Vec::with_capacity(n + 1);
        for i in (0..n).rev() {
            let temp = num[i] + k;
            res.push(temp % 10);
            k = temp / 10;
        }
        while k > 0 {
            res.push(k % 10);
            k /= 10;
        }
        res.reverse();
        res
    }
}

fn main() {
    println!("{:?}", Solution::add_to_array_form(vec![0], 20));
    println!("{:?}", Solution::add_to_array_form(vec![9,9,9,9,9,9,9,9,9,9,9], 2));
    println!("{:?}", Solution::add_to_array_form(vec![1, 2, 6, 6], 34));
    println!("{:?}", Solution::add_to_array_form(vec![1, 2, 0, 0], 34));
    println!("{:?}", Solution::add_to_array_form(vec![2, 7, 4], 181));
}

//
// Created by zhiya at 2025/5/24 22:08
//
