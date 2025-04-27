// problem: https://leetcode.cn/problems/count-of-interesting-subarrays/?envType=daily-question&envId=2025-04-25
struct Solution;

use std::ffi::c_ushort;

use std::cmp::min;
impl Solution {
    pub fn count_interesting_subarrays(nums: Vec<i32>, modulo: i32, k: i32) -> i64 {
        let mut presum = 0;
        let n = nums.len();
        let mut cnt = vec![0; min(modulo as usize, n + 1)];
        let mut res = 0i64;
        cnt[0] = 1;
        for i in 0..nums.len() {
            presum += if nums[i] % modulo == k { 1 } else { 0 };
            if presum >= k {
                res += cnt[((presum - k) % modulo) as usize];
            }
            cnt[(presum % modulo) as usize] += 1;
        }
        res
    }
}


fn main() {
    println!(
        "{:?}",
        Solution::count_interesting_subarrays(vec![7, 2], 7, 0)
    );
    println!(
        "{:?}",
        Solution::count_interesting_subarrays(vec![2, 7], 7, 0)
    );
    println!(
        "{:?}",
        Solution::count_interesting_subarrays(vec![3, 1, 9, 6], 3, 0)
    );
    println!(
        "{:?}",
        Solution::count_interesting_subarrays(vec![3, 2, 4], 2, 1)
    );
}

impl Solution {
    // [Fatal] TLE
    pub fn count_interesting_subarrays_2(nums: Vec<i32>, modulo: i32, k: i32) -> i64 {
        let mut inums: Vec<i64> = Vec::new();
        for (i, num) in nums.iter().enumerate() {
            if num % modulo == k {
                inums.push(i as i64);
            }
        }
        let n = inums.len();
        let mut res = 0i64;
        let mut b = k as usize;
        if k == 0 {
            b = modulo as usize;
            let mut last = -1i64;
            for num in &inums {
                let temp = *num - last;
                res += (temp - 1) * (temp) / 2;
                last = *num;
            }
            if last != nums.len() as i64 - 1 {
                let temp = nums.len() as i64 - last;
                res += (temp - 1) * (temp) / 2;
            }
        }
        // println!("n: {:?} res: {:?}", n, res);
        for size in (b..=n).step_by(modulo as usize) {
            for start in 0..=n - size {
                // println!("\t start: {:?},size: {:?}", start, size);
                let end = start + size - 1;
                let mut before = 1;
                let mut after = 1;
                if start > 0 {
                    before = inums[start] - inums[start - 1];
                } else {
                    before = inums[start] + 1;
                }
                if end < n - 1 {
                    after = inums[end + 1] - inums[end];
                } else {
                    after = nums.len() as i64 - inums[end];
                }
                // println!("\t b: {:?} a: {:?}", before, after);
                res += before * after;
            }
        }
        res
    }
}


//
// Created by zhiya at 2025/4/25 14:26
//
