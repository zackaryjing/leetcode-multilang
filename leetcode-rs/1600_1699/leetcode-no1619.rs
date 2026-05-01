// problem:
struct Solution;

impl Solution {
    pub fn trim_mean(mut arr: Vec<i32>) -> f64 {
        let mut n = arr.len();
        arr.sort();
        let k = (n as f64 * 0.05) as usize;
        arr[k..n - k].iter().sum::<i32>() as f64 / ((n - (2 * k)) as f64)
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::trim_mean(vec![
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3
        ])
    );
    println!(
        "{:?}",
        Solution::trim_mean(vec![
            4, 8, 4, 10, 0, 7, 1, 3, 7, 8, 8, 3, 4, 1, 6, 2, 1, 1, 8, 0, 9, 8, 0, 3, 9, 10, 3, 10,
            1, 10, 7, 3, 2, 1, 4, 9, 10, 7, 6, 4, 0, 8, 5, 1, 2, 1, 6, 2, 5, 0, 7, 10, 9, 10, 3, 7,
            10, 5, 8, 5, 7, 6, 7, 6, 10, 9, 5, 10, 5, 5, 7, 2, 10, 7, 7, 8, 2, 0, 1, 1
        ])
    );
}

//
// Created by jing at 2026-04-28 18:26
//
