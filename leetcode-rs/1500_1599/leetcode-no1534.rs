// problem: https://leetcode.cn/problems/count-good-triplets/description/?envType=daily-question&envId=2025-04-14
struct Solution;

impl Solution {
    pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
        let n = arr.len();
        let mut res = 0;
        for i in 0..n {
            for j in i + 1..n {
                for k in j + 1..n {
                    if arr[i].abs_diff(arr[j]) <= a as u32
                        && arr[i].abs_diff(arr[k]) <= c as u32
                        && arr[j].abs_diff(arr[k]) <= b as u32
                    {
                        res += 1;
                    }
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{}",
        Solution::count_good_triplets(vec![3, 0, 1, 1, 9, 7], 7, 2, 3)
    );
}

//
// Created by ASUS at 2025/4/14 13:59
//
