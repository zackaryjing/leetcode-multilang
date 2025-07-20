// problem: https://leetcode.cn/problems/count-primes/

struct Solution;

impl Solution {
    // eratosthenes sieve
    pub fn count_primes(n: i32) -> i32 {
        if n <= 1 {
            return 0;
        }
        let n = n as usize;
        let mut is_prime = vec![true; n];
        unsafe {
            *is_prime.get_unchecked_mut(0) = false;
            *is_prime.get_unchecked_mut(1) = false;
        }
        let limit = n.isqrt() + 1;
        unsafe {
            for i in 2..limit {
                if is_prime[i] {
                    for j in (i + i..n).step_by(i) {
                        *is_prime.get_unchecked_mut(j) = false;
                    }
                }
            }
        }
        is_prime.iter().filter(|&&x| x).count() as _
    }
}

impl Solution {
    // linear sieve
    pub fn count_primes_linear_sieve(n: i32) -> i32 {
        if n <= 1 {
            return 0;
        }
        let n = n as usize;
        let mut is_prime = vec![true; n];
        // let estimate_cnt = (n as f32 / (n as f32).ln()) as usize + 1;
        let estimate_cnt = n / 3;
        let mut primes = Vec::with_capacity(estimate_cnt);
        unsafe {
            *is_prime.get_unchecked_mut(0) = false;
            *is_prime.get_unchecked_mut(1) = false;
        }
        for i in 2..n {
            unsafe {
                if *is_prime.get_unchecked(i) {
                    primes.push(i);
                }
                for &prime in primes.iter() {
                    let composite = i * prime;
                    if composite >= n {
                        break;
                    }
                    *is_prime.get_unchecked_mut(composite) = false;
                    if i % prime == 0 {
                        break;
                    }
                }
            }
        }
        primes.len() as _
    }
}

impl Solution {
    pub fn count_primes_brute_force(n: i32) -> i32 {
        struct Primes {
            primes: Vec<i32>,
        }

        impl Primes {
            pub fn new() -> Self {
                Self { primes: Vec::new() }
            }
            pub fn check(&mut self, num: i32) -> bool {
                let limit = num.isqrt() + 1;
                for &prime in &self.primes {
                    if prime >= limit {
                        break;
                    }
                    if num % prime == 0 {
                        return false;
                    }
                }
                self.primes.push(num);
                true
            }
        }
        let mut cnt = 0;
        let mut p = Primes::new();
        for i in 2..n {
            if p.check(i) {
                cnt += 1;
            }
        }
        cnt
    }
}

fn main() {
    println!("{:?}", Solution::count_primes(10));
}

//
// Created By Zackary At 2025/7/9 17:26
//