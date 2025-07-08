// problem: https://leetcode.cn/problems/finding-pairs-with-a-certain-sum/?envType=daily-question&envId=2025-07-06

use std::collections::HashMap;
struct FindSumPairs {
    nums1: Vec<i32>,
    nums2: Vec<i32>,
    nums2_cnt: HashMap<i32, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FindSumPairs {
    fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
        let mut cnt = HashMap::new();
        for &num in &nums2 {
            *cnt.entry(num).or_default() += 1;
        }
        Self {
            nums1,
            nums2,
            nums2_cnt: cnt,
        }
    }

    fn add(&mut self, index: i32, val: i32) {
        let v = &mut self.nums2[index as usize];
        self.nums2_cnt.entry(*v).and_modify(|x| *x -= 1);
        *v += val;
        self.nums2_cnt
            .entry(*v)
            .and_modify(|x| *x += 1)
            .or_insert(1);
    }

    fn count(&self, tot: i32) -> i32 {
        let mut res = 0;
        for num in &self.nums1 {
            res += *self.nums2_cnt.get(&(tot - num)).unwrap_or(&0);
        }
        res
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * let obj = FindSumPairs::new(nums1, nums2);
 * obj.add(index, val);
 * let ret_2: i32 = obj.count(tot);
 */

fn main() {
    let test = FindSumPairs::new(vec![1, 1, 2, 2, 2, 3], vec![1, 4, 5, 2, 5, 4]);
    println!("{:?}", test.count(7));
}

//
// Created by zhiya at 7/6/2025 12:12 PM
//
