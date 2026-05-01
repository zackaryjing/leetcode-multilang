// problem: https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/?envType=problem-list-v2&envId=3rBpGyas
struct Solution;

impl Solution {
    pub fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
        struct Weights {
            weights: Vec<i32>,
            days: i32,
        }
        impl Weights {
            pub fn new(weights: Vec<i32>, days: i32) -> Self {
                Self { weights, days }
            }
            fn check(&self, limit: i32) -> bool {
                let mut temp = 0;
                let mut cnt = 1;
                for num in &self.weights {
                    temp += num;
                    if temp > limit {
                        temp = *num;
                        cnt += 1;
                    }
                }
                // println!("testing: {limit},needed:{cnt},allowed: {:?}", self.days);
                if cnt > self.days {
                    return false;
                }
                true
            }
            pub fn divide(&self) -> i32 {
                let mut right = self.weights.iter().sum::<i32>();
                let mut left = *self.weights.iter().max().unwrap();
                while left < right {
                    let mid = (left + right) / 2;
                    let test = self.check(mid);
                    if test {
                        right = mid;
                    } else {
                        left = mid + 1
                    }
                }
                left
            }
        }
        let w = Weights::new(weights, days);
        w.divide()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::ship_within_days(vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5)
    );
    println!("{:?}", Solution::ship_within_days(vec![1, 2, 3, 1, 1], 4));
}

//
// Created by jing at 2026-04-27 21:36
//
