// problem: https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/?envType=daily-question&envId=2025-08-16
struct Solution;

const MOD: i64 = 1000_000_007;
impl Solution {
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        let x = x as u32;
        let n = n as usize;
        let mut dp = vec![0i64; n + 1];
        dp[0] = 1;
        for j in 1..=n {
            let num = j.pow(x);
            if num > n {
                break;
            }
            for i in (num..=n).rev() {
                dp[i] += dp[i - num];
            }
        }
        (dp[n] % MOD) as i32
    }
}

impl Solution {
    pub fn number_of_ways_2(n: i32, x: i32) -> i32 {
        let x = x as u32;
        let n = n as usize;
        let mut nums = vec![];
        for i in 1..=n {
            if i.pow(x) <= n {
                nums.push(i.pow(x));
            }
        }
        let mut dp = vec![0i64; n + 1];
        dp[0] = 1;
        let m = nums.len();
        for j in 0..m {
            let num = nums[j];
            let mut dp_nxt = dp.clone();
            for i in 0..=n {
                if i >= num {
                    dp_nxt[i] = (dp[i] + dp[i - num]) % MOD;
                }
            }
            dp = dp_nxt;
        }
        dp[n] as i32
    }
}

fn main() {
    println!("{:?} e:1", Solution::number_of_ways(10, 2));
    println!("{:?} e:2", Solution::number_of_ways(4, 1));
    println!("{:?} e:6", Solution::number_of_ways(8, 1));
}

//
// Created by zhiya at 8/16/2025 2:54 PM
//
