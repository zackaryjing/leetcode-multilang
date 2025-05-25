// problem: https://leetcode.cn/problems/circular-array-loop/
struct Solution;

impl Solution {
    // [Pass] perf ok, while the code ... no so good .
    pub fn circular_array_loop(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut slow = 0;
        let mut fast = ((nums[slow] + n as i32) as usize + slow) % n;
        let mut direction = if nums[slow] > 0 { 1 } else { -1 };

        let mut vis = vec![false; n];
        let mut anchor = 0;
        let mut valid = true;
        loop {
            while slow != fast {
                vis[slow] = true;
                if nums[slow] * direction < 0 {
                    valid = false;
                }
                slow = (nums[slow] + (slow + n) as i32) as usize % n;
                fast = (nums[fast] + (fast + n) as i32) as usize % n;
                if nums[fast] * direction < 0 {
                    valid = false;
                }
                fast = (nums[fast] + (fast + n) as i32) as usize % n;
                if nums[fast] * direction < 0 {
                    valid = false;
                }
            }
            if nums[slow].abs() as usize != n && valid {
                return true;
            } else {
                while vis[anchor] {
                    anchor += 1;
                    if anchor >= n {
                        return false;
                    }
                }
                slow = anchor;
                direction = if nums[slow] > 0 { 1 } else { -1 };
                fast = ((nums[slow] + n as i32) as usize + slow) % n;
                if slow == fast {
                    vis[slow] = true;
                }
            }
            valid = true;
        }
    }
}

fn main() {
    println!("{:?} true", Solution::circular_array_loop(vec![1, -1, 5, 1, 4]));
    println!(
        "{:?} false",
        Solution::circular_array_loop(vec![-1, -2, -3, -4, -5, 6])
    );
    println!("{:?} true", Solution::circular_array_loop(vec![2, -1, 1, 2, 2]));
    println!("{:?} false", Solution::circular_array_loop(vec![-2,1,-1,-2,-2]));
    println!("{:?} false", Solution::circular_array_loop(vec![1,-2]));
    println!("{:?} false", Solution::circular_array_loop(vec![-1,-2,-3,-4,-5]));
    println!("{:?} false", Solution::circular_array_loop(vec![-1]));
}

//
// Created by zhiya at 2025/5/25 19:33
//
