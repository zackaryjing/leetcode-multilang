// problem: https://leetcode.cn/problems/defuse-the-bomb/
struct Solution;

impl Solution {
    pub fn decrypt(mut code: Vec<i32>, k: i32) -> Vec<i32> {
        let n = code.len();
        let mut res = vec![0; n];
        for i in 1..n {
            code[i] += code[i - 1];
        }
        for i in 0..n {
            let mut start = 0;
            let mut end = 0;
            if k > 0 {
                start = i;
                end = (i + k as usize) % n;
            }
            if k < 0 {
                start = ((i + n) as i32 + k - 1) as usize % n;
                end = (i + n - 1) % n;
            }
            if start <= end {
                res[i] = code[end] - code[start];
            } else {
                res[i] = code[n - 1] - code[start] + code[end];
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::decrypt(vec![5, 7, 1, 4], 3));
    println!(
        "{:?}",
        Solution::decrypt(vec![10, 5, 7, 7, 3, 2, 10, 3, 6, 9, 1, 6], -4)
    );
    println!("{:?}", Solution::decrypt(vec![1, 2, 3, 4], 0));
    println!("{:?}", Solution::decrypt(vec![2, 4, 9, 3], -2));
}

//
// Created by jing at 2025-09-08 11:07
//
