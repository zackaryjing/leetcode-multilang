// problem: https://leetcode.cn/problems/range-product-queries-of-powers/?envType=daily-question&envId=2025-08-16
struct Solution;

const MOD: i64 = 1000_000_007;
fn inv(num: i64) -> i64 {
    let mut t = MOD - 2;
    let mut res = 1;
    let mut temp = num;
    while t > 0 {
        if (t & 1) == 1 {
            res = (res * temp) % MOD;
        }
        temp = (temp * temp) % MOD;
        t >>= 1;
    }
    res
}

impl Solution {
    pub fn product_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let m = n.count_ones() as usize;
        let mut inv_v = vec![0; m + 1];
        let mut v = vec![0; m + 1];
        v[0] = 1;
        inv_v[0] = 1;
        let mut index = 1;
        for i in 0..32 {
            if ((n >> i) & 1) == 1 {
                v[index] = (v[index - 1] * (1 << i)) % MOD;
                inv_v[index] = (inv_v[index - 1] * inv(1 << i)) % MOD;
                index += 1;
            }
        }
        let k = queries.len();
        let mut res = vec![0i32; k];

        for i in 0..k {
            let left = queries[i][0] as usize;
            let right = queries[i][1] as usize;
            res[i] = ((v[right + 1] * inv_v[left]) % MOD) as i32;
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::product_queries(15, vec![vec![0, 1], vec![2, 2], vec![0, 3]])
    );
    println!("{:?}", Solution::product_queries(2, vec![vec![0, 0]]));
}

//
// Created by zhiya at 8/16/2025 3:50 PM
//
