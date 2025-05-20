use std::mem::swap;

// problem: https://leetcode.cn/problems/sort-colors/?envType=daily-question&envId=2025-05-17
struct Solution;

impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut q0 = 0;
        let mut q1 = 0;
        let n = nums.len();
        for i in 0..n {
            if nums[i] == 1 {
                nums.swap(i, q1);
                q1 += 1;
            } else if nums[i] == 0 {
                nums.swap(q0, i);
                if q0 != q1 {
                    nums.swap(i, q1);
                }
                q1 += 1;
                q0 += 1;
            }
        }
    }
}

use std::cmp::max;
impl Solution {
    // [Pass] Feiwu. slower than turtle. I should really stop make trash...
    pub fn sort_colors_2(nums: &mut Vec<i32>) {
        let n = nums.len();
        let mut zero = n - 1;
        let mut two = n - 1;
        while two > 0 && nums[two] == 2 {
            two -= 1;
        }
        while zero > 0 && nums[zero] != 0 {
            zero -= 1;
        }
        let mut index = 0;
        while index < two {
            println!("{:?} {:?} {:?} {:?}", nums, index, two, zero);
            if nums[index] == 2 {
                nums.swap(index, two);
                while two > 0 && nums[two] == 2 {
                    two -= 1;
                }
                while zero > 0 && nums[zero] != 0 {
                    zero -= 1;
                }
            }
            if nums[index] == 1 && zero > index {
                nums.swap(index, zero);
                while zero > 0 && nums[zero] != 0 {
                    zero -= 1;
                }
            }
            index += 1;
        }
    }
}

fn main() {
    let mut nums1 = vec![2, 0, 2, 1, 1, 0];
    Solution::sort_colors(&mut nums1);
    println!("{:?}", nums1);
    let mut nums2 = vec![2, 0, 1];
    Solution::sort_colors(&mut nums2);
    println!("{:?}", nums2);
    let mut nums3 = vec![2];
    Solution::sort_colors(&mut nums3);
    println!("{:?}", nums3);
}

//
// Created by zhiya at 2025/5/17 0:19
//
