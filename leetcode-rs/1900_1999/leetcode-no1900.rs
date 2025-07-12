// problem: https://leetcode.cn/problems/the-earliest-and-latest-rounds-where-players-compete/?envType=daily-question&envId=2025-07-12
struct Solution;

use std::cell::RefCell;
use std::cmp::{max, min};
use std::rc::Rc;
use std::usize;
impl Solution {
    pub fn earliest_and_latest(mut n: i32, first_player: i32, second_player: i32) -> Vec<i32> {
        let n = n as usize;
        let memo_out = Rc::new(RefCell::new(vec![
            vec![vec![(0usize, 0usize); n + 1]; n + 1];
            n + 1
        ]));
        let dfs_inner = {
            let memo = memo_out.clone();
            move |f: &dyn Fn(usize, usize, usize) -> (usize, usize),
                  n: usize,
                  mut first: usize,
                  mut second: usize|
                  -> (usize, usize) {
                if first + second == n + 1 {
                    return (1, 1);
                }
                if first + second > n + 1 {
                    (first, second) = (n + 1 - second, n + 1 - first);
                }

                let res = memo.borrow()[n][first][second];
                if res.0 != 0 {
                    return res;
                }

                let m = (n + 1) / 2;
                let min_mid = if second <= m { 0 } else { second - n / 2 - 1 };
                let max_mid = if second <= m {
                    second - first
                } else {
                    m - first
                };
                let mut earliest = usize::MAX;
                let mut latest = 0;
                for left in 0..first {
                    for mid in min_mid..max_mid {
                        let (e, l) = f(m, left + 1, left + mid + 2);
                        earliest = min(earliest, e);
                        latest = max(latest, l);
                    }
                }
                memo.borrow_mut()[n][first][second] = (earliest + 1, latest + 1);
                return (earliest + 1, latest + 1);
            }
        };
        fn real_dfs<'a>(
            f: &'a dyn Fn(
                &dyn Fn(usize, usize, usize) -> (usize, usize),
                usize,
                usize,
                usize,
            ) -> (usize, usize),
        ) -> impl Fn(usize, usize, usize) -> (usize, usize) + 'a {
            move |a, b, c| f(&real_dfs(f), a, b, c)
        }
        let dfs = |a, b, c| real_dfs(&dfs_inner)(a, b, c);

        let (earliest, latest) = dfs(n, first_player as usize, second_player as usize);
        vec![earliest as i32, latest as i32]
    }
}

impl Solution {
    // [Fail] not suitable for this kind of method...
    pub fn earliest_and_latest_2(mut n: i32, first_player: i32, second_player: i32) -> Vec<i32> {
        let mut on = n;
        let mut left = first_player - 1;
        let mut right = n - second_player;

        if left > right {
            (right, left) = (left, right);
        }
        let mut diff = (right - left).abs();
        if diff == 0 {
            return vec![1, 1];
        }
        let mut times_min = 1;

        let mut k = n / 2;

        while diff > 0 {
            k /= 2;
            diff -= k;
            times_min += 1;
        }
        println!("min: {:?}", times_min);
        let mut left = first_player - 1;
        let mut right = n - second_player;
        let mut times_max = 1;
        let mut k = n / 2;
        println!("left: {:?}, right: {:?}", left, right);
        while left > 0 || right > 0 {
            println!("left: {:?}, right: {:?}", left, right);
            let mid = n - right - left - 2;
            let cmid = (n - (right + 1) * 2).max(0);
            println!(
                "n: {:?},K: {:?},mid: {:?},cmid: {:?}, left: {:?},base: {:?}",
                n, k, mid, cmid, left, right
            );
            let left_remove = k - (mid - cmid + cmid / 2);
            // if left_remove < 0 {
            //     println!(
            //         "{:?},{:?},{:?},{:?},{:?},{:?}",
            //         n, k, mid, base, left, right
            //     );
            //     break;
            // }

            if left >= left_remove {
                left -= left_remove;
            } else {
                right -= left_remove - left;
                left = 0;
            }
            n -= k;
            k = n / 2;
            times_max += 1;
        }
        println!("max: {:?}", times_max);

        vec![times_min, times_max]
    }
}

fn main() {
    println!("{:?}", Solution::earliest_and_latest(5, 1, 4));
    println!("{:?}", Solution::earliest_and_latest(11, 2, 4));
    println!("{:?}", Solution::earliest_and_latest(5, 1, 5));
}

//
// Created by zhiya at 7/12/2025 2:23 PM
//
