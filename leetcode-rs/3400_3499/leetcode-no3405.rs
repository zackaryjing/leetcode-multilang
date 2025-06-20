// problem: https://leetcode.cn/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/?envType=daily-question&envId=2025-06-17
struct Solution;


// time spent: 3:12:13
const MOD: i64 = 1_000_000_007;
const MX: usize = 100_000;
static mut fact: Vec<i64> = Vec::new();
static mut inv_fact: Vec<i64> = Vec::new();

impl Solution {
    pub fn qpow(mut x: i64, mut n: i64) -> i64 {
        let mut res: i64 = 1;
        while n != 0 {
            if n & 1 == 1 {
                res = (res * x) % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        res
    }

    pub fn comb(n: usize, m: usize) -> i64 {
        unsafe { fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD }
    }

    pub fn init() {
        unsafe {
            if (*fact).is_empty() {
                fact = vec![1; MX];
                for i in 1..MX {
                    fact[i] = fact[i - 1] * i as i64 % MOD;
                }
                inv_fact = vec![1; MX];
                inv_fact[MX - 1] = Self::qpow(fact[MX - 1], MOD - 2);
                for i in (1..MX).rev() {
                    inv_fact[i - 1] = inv_fact[i] * i as i64 % MOD;
                }
            }
        }
    }

    pub fn count_good_arrays(n: i32, m: i32, k: i32) -> i32 {
        unsafe {
            Self::init();
            (Self::comb(n as usize - 1, k as usize) * m as i64 % MOD
                * Self::qpow(m as i64 - 1, (n - k) as i64 - 1)
                % MOD) as i32
        }
    }
}

fn main() {
    unsafe {
        println!("{:?}", Solution::count_good_arrays(3, 2, 1));
        println!("{:?}", Solution::count_good_arrays(4, 2, 2));
        println!("{:?}", Solution::count_good_arrays(5, 2, 0));
    }
}

//
// Created by zhiya at 6/17/2025 7:44 PM
//
