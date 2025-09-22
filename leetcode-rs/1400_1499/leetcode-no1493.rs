// problem:
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut cur = 0;
        let mut last = 0;
        let mut have_zero = false;

        for num in nums {
            if num == 1 {
                cur += 1;
            } else {
                have_zero = true;
                res = max(res, cur + last);
                last = cur;
                cur = 0;
            }
        }
        if have_zero {
            return res;
        } else {
            return if res != 0 { res - 1 } else { 0 };
        }
    }
}

fn main() {
    println!("{:?} e:3", Solution::longest_subarray(vec![1, 1, 0, 1]));
    println!(
        "{:?} e:5",
        Solution::longest_subarray(vec![0, 1, 1, 1, 0, 1, 1, 0, 1])
    );
    println!("{:?} e:2", Solution::longest_subarray(vec![1, 1, 1]));
    println!("{:?} e:1", Solution::longest_subarray(vec![1, 0, 0, 0, 0]));
    println!(
        "{:?} e:4",
        Solution::longest_subarray(vec![1, 1, 0, 0, 1, 1, 1, 0, 1])
    );
}

//
// Created by jing at 8/24/25 10:44PM
//
