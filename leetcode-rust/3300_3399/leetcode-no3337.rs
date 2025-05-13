// problem: https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/
const L: usize = 26;
const MOD: i64 = 1_000_000_007;
struct Mat {
    data: [[i64; L]; L],
}

impl Mat {
    fn new() -> Self {
        Mat { data: [[0; L]; L] }
    }

    fn copy_from(&mut self, other: &Mat) {
        for i in 0..L {
            for j in 0..L {
                self.data[i][j] = other.data[i][j];
            }
        }
    }

    fn mul(&self, other: &Mat) -> Mat {
        let mut result = Mat::new();
        for i in 0..L {
            for j in 0..L {
                for k in 0..L {
                    result.data[i][j] =
                        (result.data[i][j] + self.data[i][k] * other.data[k][j]) % MOD;
                }
            }
        }
        result
    }
}
fn I() -> Mat {
    let mut m = Mat::new();
    for i in 0..L {
        m.data[i][i] = 1;
    }
    m
}

fn quickmul(x: &Mat, mut y: i32) -> Mat {
    let mut ans = I();
    let mut cur = Mat::new();
    cur.copy_from(x);
    while y > 0 {
        if y & 1 == 1 {
            ans = ans.mul(&cur);
        }
        cur = cur.mul(&cur);
        y >>= 1;
    }
    ans
}

struct Solution;

impl Solution {
    pub fn length_after_transformations(s: String, t: i32, nums: Vec<i32>) -> i32 {
        let mut T = Mat::new();
        for i in 0..L {
            for j in 1..=nums[i] as usize {
                T.data[(i + j) % L][i] = 1;
            }
        }
        let res = quickmul(&T, t);
        let mut f = [0; L];
        for ch in s.chars() {
            f[(ch as u8 - b'a') as usize] += 1;
        }
        let mut ans: i64 = 0;
        for i in 0..L {
            for j in 0..L {
                ans = (ans + res.data[i][j] * f[j]) % MOD;
            }
        }
        ans as i32
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::length_after_transformations(
            "abcyy".to_string(),
            2,
            vec![
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2
            ]
        )
    );
}

//
// Created by zhiya at 2025/5/13 11:28
//
