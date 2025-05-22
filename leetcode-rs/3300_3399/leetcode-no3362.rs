// problem: https://leetcode.cn/problems/zero-array-transformation-iii/?envType=daily-question&envId=2025-05-22
struct Solution;

use std::cmp::Ordering;
use std::collections::BinaryHeap;
#[derive(Eq, PartialEq)]
struct Query {
    first: i32,
    second: i32,
}

impl Ord for Query {
    fn cmp(&self, other: &Self) -> Ordering {
        self.second.cmp(&other.second)
    }
}

impl PartialOrd for Query {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn max_removal(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut tot = 0;
        let mut queries = queries;
        queries.sort();
        let mut cur = 0;
        let m = queries.len();
        let mut valid: BinaryHeap<Query> = BinaryHeap::new();
        let mut diff_vec = vec![0; n + 1];
        let mut res = 0;
        for i in 0..n {
            let num = nums[i];
            tot += diff_vec[i];
            while cur < m && i >= queries[cur][0] as usize {
                valid.push(Query {
                    first: queries[cur][0],
                    second: queries[cur][1],
                });
                cur += 1;
            }
            while tot < num {
                if valid.is_empty() {
                    return -1;
                } else {
                    let temp = valid.pop().unwrap();
                    if temp.second < i as i32 {
                        return -1;
                    }
                    tot += 1;
                    diff_vec[temp.second as usize + 1] -= 1;
                    res += 1;
                }
            }
        }
        m as i32 - res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::max_removal(vec![2, 0, 2], vec![vec![0, 2], vec![0, 2], vec![1, 1]])
    );
    println!(
        "{:?}",
        Solution::max_removal(
            vec![1, 1, 1, 1],
            vec![vec![1, 3], vec![0, 2], vec![1, 3], vec![1, 2]]
        )
    );
    println!(
        "{:?}",
        Solution::max_removal(vec![1, 2, 3, 4], vec![vec![0, 3]])
    );
    println!(
        "{:?}",
        Solution::max_removal(
            vec![0, 0, 3],
            vec![vec![0, 2], vec![1, 1], vec![0, 0], vec![0, 0]]
        )
    );
}

//
// Created by zhiya at 2025/5/22 13:20
//
