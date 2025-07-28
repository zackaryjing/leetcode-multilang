// problem: https://leetcode.cn/problems/count-number-of-maximum-bitwise-or-subsets/?envType=daily-question&envId=2025-07-28
struct Solution;

impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let mut m_num = 0;
        for num in &nums {
            m_num |= num;
        }
        let mut res = 0;

        let n = nums.len();
        let mut s_temp = vec![0; n + 1];
        let mut pos = n;
        for i in (0..2i32.pow(n as u32)).rev() {
            for j in (1..=pos).rev() {
                if (i >> (j - 1)) & 1 == 1 {
                    s_temp[j - 1] = s_temp[j] | nums[n - j];
                } else {
                    s_temp[j - 1] = s_temp[j];
                }
            }
            if s_temp[0] == m_num {
                res += 1;
            }
            pos = (i ^ (i - 1)).count_ones() as usize;
        }

        res
    }
}

fn main() {
    println!("{:?} e:6", Solution::count_max_or_subsets(vec![3, 2, 1, 5]));
    println!("{:?} e:7", Solution::count_max_or_subsets(vec![2, 2, 2]));
}

//
// Created by zhiya at 7/28/2025 8:27 PM
//
