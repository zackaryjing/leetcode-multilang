// problem: https://leetcode.cn/problems/random-pick-index/

use std::collections::HashMap;

struct Solution {
    data: HashMap<i32, Vec<usize>>,
    seed: i64,
}

// spent: 33:22
/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(nums: Vec<i32>) -> Self {
        let mut temp: HashMap<i32, Vec<usize>> = HashMap::new();
        for (index, &num) in nums.iter().enumerate() {
            temp.entry(num).or_default().push(index);
        }
        Self {
            data: temp,
            seed: 65148648,
        }
    }

    fn pick(&mut self, target: i32) -> i32 {
        let mut res = 0;
        if let Some(list) = self.data.get(&target) {
            let n = list.len();
            res = list[self.seed as usize % n] as i32;
        }
        self.next_rand();
        res
    }

    fn next_rand(&mut self) {
        self.seed = ((self.seed * self.seed) / 10000) % 100000000;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(nums);
 * let ret_1: i32 = obj.pick(target);
 */

fn main() {
    let mut s = Solution::new(vec![
        1, 2, 3, 2, 3, 2, 3, 2, 3, 4, 3, 4, 1, 2, 3, 2, 3, 4, 1, 3, 4, 1, 3, 1,
    ]);
    for i in 0..100 {
        println!("{:?}", s.pick(3));
    }
}

//
// Created by zhiya at 2025/5/25 21:45
//
