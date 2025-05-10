// problem: https://leetcode.cn/problems/longest-square-streak-in-an-array/
struct Solution;

use std::cmp::max;
use std::collections::{BTreeSet, HashMap};
impl Solution {
    pub fn longest_square_streak(nums: Vec<i32>) -> i32 {
        let mut cand: HashMap<i32, BTreeSet<i64>> = HashMap::new();
        for num in nums {
            let mut temp = num.isqrt();
            let mut root = num;
            while temp * temp == root {
                root = temp;
                temp = temp.isqrt();
            }
            (*cand.entry(root).or_insert(BTreeSet::<i64>::new())).insert(num as i64);
        }
        // println!("{:?}", cand);
        let mut res = -1;
        for (key, val) in cand.iter_mut() {
            let mut last = val.first().unwrap();
            let mut cur_iter = val.iter();
            let mut length = 1;
            loop {
                match cur_iter.next() {
                    Some(cur) => {
                        if last * last == *cur {
                            length += 1;
                            res = max(res, length);
                        } else {
                            length = 1;
                        }
                        last = cur;
                    }
                    None => break,
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{}",
        Solution::longest_square_streak(vec![256, 3, 6, 16, 16, 8, 65536, 4, 2])
    );
    println!("{}", Solution::longest_square_streak(vec![2, 3, 5, 6, 7]));
    println!("finished");
}

//
// Created by ASUS at 2025/5/8 23:06
//
