// problem: https://leetcode.cn/problems/count-number-of-maximum-bitwise-or-subsets/?envType=daily-question&envId=2025-07-28
struct Solution;

impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let mut m_num = 0;
        for num in &nums {
            m_num |= num;
        }
        println!("{:?}",m_num);
        let n = nums.len();
        let mut res = 0;
        let mut cur = 0;
        let mut right = 0;
        for left in 0..n {
            while right < n && cur != m_num {
                cur |= nums[right];
                right += 1;
            }
            if cur == m_num && right < n {
                res += 2i32.pow((n - right) as u32 - 1);
                cur = 0;
                for i in left + 1..=right {
                    cur |= nums[i];
                }
            } else {
                break;
            }
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
