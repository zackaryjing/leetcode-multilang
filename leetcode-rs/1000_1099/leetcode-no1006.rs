// problem: https://leetcode.cn/problems/clumsy-factorial/?envType=problem-list-v2&envId=3rBpGyas
struct Solution;

impl Solution {
    pub fn clumsy(n: i32) -> i32 {
        let mut cur = n - 1;
        let mut temp = n;
        let mut res = 0;

        for t in 0..n - 1 {
            // println!("c: {cur} res:{res} temp:{temp}");
            match t % 4 {
                0 => temp *= cur,
                1 => temp /= cur,
                2 => {
                    res += temp + cur;
                    temp = 0;
                }
                _ => {
                    temp = -cur;
                }
            }
            cur -= 1;
        }
        res += temp;
        res
    }
}

fn main() {
    println!("{:?}", Solution::clumsy(4));
    println!("{:?}", Solution::clumsy(10));
}

//
// Created by ASUS at 2025-12-14 18:21
//
