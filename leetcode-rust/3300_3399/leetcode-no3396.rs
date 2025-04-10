struct Solution;
use std::collections::HashSet;

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut vis: HashSet<i32> = HashSet::new();
        for i in (0..n).rev() {
            if vis.contains(&nums[i]) {
                return i as i32 / 3 + 1;
            } else {
                vis.insert(nums[i]);
            }
        }
        0
    }
}

fn main() {
    println!(
        "{}",
        Solution::minimum_operations(Vec::from([4, 2, 3, 3, 5, 7]))
    )
}
