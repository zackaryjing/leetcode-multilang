// problem: https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/?envType=daily-question&envId=2025-07-07
struct Solution;

use std::cmp::Reverse;
use std::collections::BTreeSet;
use std::collections::BinaryHeap;
impl Solution {
    pub fn max_events(mut events: Vec<Vec<i32>>) -> i32 {
        events.sort_by(|first, second| {
            let l1 = first[1] - first[0] + 1;
            let l2 = second[1] - second[0] + 1;
            return if l1 != l2 {
                l1.cmp(&l2)
            } else {
                first[0].cmp(&second[0])
            };
        });
        let mut min_available = 1;
        let mut res = 0;
        // let mut used_heap = BinaryHeap::<Reverse<i32>>::new();
        let mut used_set = BTreeSet::<i32>::new();
        for event in events {
            // println!(
            //     "event: {:?} min_a: {:?}, used_set: {:?}",
            //     event, min_available, used_set
            // );
            let start = event[0];
            let end = event[1];
            if start <= min_available && min_available <= end {
                min_available += 1;
                while !used_set.is_empty() {
                    let f = *used_set.first().unwrap();
                    if min_available == f {
                        used_set.remove(&f);
                        min_available += 1;
                    } else if min_available > f {
                        used_set.remove(&f);
                    } else {
                        break;
                    }
                }
                res += 1;
            } else if min_available < start {
                for candidate in start..=end {
                    if !used_set.contains(&candidate) {
                        used_set.insert(candidate);
                        res += 1;
                        break;
                    }
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?} 2",
        Solution::max_events(vec![
            vec![1, 10],
            vec![2, 2],
            vec![2, 2],
            vec![2, 2],
            vec![2, 2]
        ])
    );
    println!(
        "{:?} 4",
        Solution::max_events(vec![
            vec![1, 2],
            vec![2, 2],
            vec![3, 3],
            vec![3, 4],
            vec![3, 4]
        ])
    );
    println!(
        "{:?} 3",
        Solution::max_events(vec![vec![1, 2], vec![2, 3], vec![3, 4]])
    );
    println!(
        "{:?} 4",
        Solution::max_events(vec![vec![1, 2], vec![2, 3], vec![3, 4], vec![1, 2]])
    );
    println!(
        "{:?} 4",
        Solution::max_events(vec![
            vec![1, 4],
            vec![4, 4],
            vec![2, 2],
            vec![3, 4],
            vec![1, 1]
        ])
    );
}

//
// Created by zhiya at 7/7/2025 4:05 PM
//
