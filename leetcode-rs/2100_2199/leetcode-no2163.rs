// problem: https://leetcode.cn/problems/minimum-difference-in-sums-after-removal-of-elements/?envType=daily-question&envId=2025-07-18

struct Solution;

use std::cmp::{Reverse, min};
use std::collections::BinaryHeap;
impl Solution {
    pub fn minimum_difference(nums: Vec<i32>) -> i64 {
        let n = nums.len() / 3;
        let nums: Vec<i64> = nums.iter().map(|&i| i as i64).collect();
        let mut mx = vec![0; n + 1];
        let mut mx_queue: BinaryHeap<Reverse<i64>> = BinaryHeap::from(
            nums[2 * n..3 * n]
                .iter()
                .map(|&i| Reverse(i))
                .collect::<Vec<Reverse<i64>>>(),
        );
        let mut cur_mx: i64 = nums[2 * n..3 * n].iter().map(|&i| i).sum();
        mx[n] = cur_mx;
        for i in (0..n).rev() {
            let num = nums[n + i];
            if let Some(&Reverse(top)) = mx_queue.peek() {
                if num > top {
                    cur_mx += num - top;
                    mx_queue.pop();
                    mx_queue.push(Reverse(num));
                }
            }
            mx[i] = cur_mx;
        }
        let mut mn_queue: BinaryHeap<i64> = BinaryHeap::from(nums[0..n].to_vec());
        let mut cur_mn: i64 = nums[0..n].iter().map(|&i| i).sum();
        let mut res = i64::MAX;
        res = min(res, cur_mn - mx[0]);
        for i in 0..n {
            let num = nums[i + n];
            if let Some(&top) = mn_queue.peek() {
                if num < top {
                    cur_mn += num - top;
                    mn_queue.push(num);
                    mn_queue.pop();
                }
            }
            res = min(res, cur_mn - mx[i + 1]);
        }
        res
    }
}

impl Solution {
    pub fn minimum_difference_2(nums: Vec<i32>) -> i64 {
        let n = nums.len() / 3;
        let mut mx = vec![0; n + 1];
        let mut mx_queue: BinaryHeap<Reverse<i64>> = BinaryHeap::from(
            nums[2 * n..3 * n]
                .iter()
                .map(|&i| Reverse(i as i64))
                .collect::<Vec<Reverse<i64>>>(),
        );
        let mut cur_mx: i64 = nums[2 * n..3 * n].iter().map(|&i| i as i64).sum();
        mx[n] = cur_mx;
        for i in (0..n).rev() {
            let num = nums[n + i] as i64;
            if Reverse(num) != *mx_queue.peek().unwrap() {
                cur_mx += num;
                mx_queue.push(Reverse(num));
                let Reverse(temp) = mx_queue.pop().unwrap();
                cur_mx -= temp;
            }
            mx[i] = cur_mx;
        }
        let mut mn = vec![0; n + 1];
        let mut mn_queue: BinaryHeap<i64> = BinaryHeap::from(
            nums[0..n]
                .iter()
                .map(|&i| i as i64)
                .collect::<Vec<i64>>()
                .to_vec(),
        );
        let mut cur_mn: i64 = nums[0..n].iter().map(|&i| i as i64).sum();
        mn[0] = cur_mn;
        for i in 0..n {
            let num = nums[i + n] as i64;
            if num != *mn_queue.peek().unwrap() {
                cur_mn += num;
                mn_queue.push(num);
                let temp = mn_queue.pop().unwrap();
                cur_mn -= temp;
            }
            mn[i + 1] = cur_mn;
        }
        let mut res = i64::MAX;
        for i in 0..=n {
            res = min(res, mn[i] - mx[i]);
        }
        res
    }
}

fn main() {
    println!(
        "{:?} expect:1",
        Solution::minimum_difference(vec![7, 9, 5, 8, 1, 3])
    );
    println!(
        "{:?} expect:-1",
        Solution::minimum_difference(vec![3, 1, 2])
    );
}

//
// Created By Zackary At 2025/7/18 10:50
//
