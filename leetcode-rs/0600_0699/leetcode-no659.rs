// problem: https://leetcode.cn/problems/split-array-into-consecutive-subsequences/
struct Solution;

use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};
use std::hash::Hash;
impl Solution {
    pub fn is_possible(nums: Vec<i32>) -> bool {
        let mut freq: HashMap<i32, i32> = HashMap::new();
        let mut append: HashMap<i32, i32> = HashMap::new();

        for num in &nums {
            *freq.entry(*num).or_default() += 1;
        }

        for num in &nums {
            if *freq.get(num).unwrap_or(&0) <= 0 {
                continue;
            }
            if *append.get(&(num - 1)).unwrap_or(&0) > 0 {
                *append.get_mut(&(num - 1)).unwrap() -= 1;
                *append.entry(*num).or_default() += 1;
            } else if *freq.get(&(num + 1)).unwrap_or(&0) > 0
                && *freq.get(&(num + 2)).unwrap_or(&0) > 0
            {
                *freq.get_mut(&(num + 1)).unwrap() -= 1;
                *freq.get_mut(&(num + 2)).unwrap() -= 1;
                *append.entry(num + 2).or_insert(0) += 1;
            } else {
                return false;
            }
            freq.entry(*num).and_modify(|mut x| *x -= 1);
        }
        true
    }
}

struct Solution2;
impl Solution2 {
    // [Pass] too slow...
    pub fn is_possible(nums: Vec<i32>) -> bool {
        let mut sublist: HashMap<i32, BinaryHeap<Reverse<i32>>> = HashMap::new();
        for num in nums {
            if let Some(list) = sublist.get_mut(&(num - 1)) {
                if let Some(Reverse(l)) = list.pop() {
                    sublist
                        .entry(num)
                        .or_insert(BinaryHeap::new())
                        .push(Reverse(l + 1));
                    continue;
                }
            }
            sublist
                .entry(num)
                .or_insert(BinaryHeap::new())
                .push(Reverse(1));
        }
        for (key, val) in sublist {
            for Reverse(v) in val {
                if v < 3 {
                    return false;
                }
            }
        }
        true
    }
}

fn main() {
    println!("{:?}", Solution::is_possible(vec![1, 2, 3, 3, 4, 5]));
    println!("{:?}", Solution::is_possible(vec![1, 2, 3, 3, 4, 4, 5, 5]));
    println!("{:?}", Solution::is_possible(vec![1, 2, 3, 4, 4, 5]));
}

//
// Created by zhiya at 2025/5/24 14:33
//
