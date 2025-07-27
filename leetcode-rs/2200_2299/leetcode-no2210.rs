// problem: https://leetcode.cn/problems/count-hills-and-valleys-in-an-array/?envType=daily-question&envId=2025-07-27
struct Solution;

impl Solution {
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut cur = nums[0];
        let n = nums.len();
        let mut m_c: i32;
        let mut m_l: i32 = 0;
        for i in 0..n - 1 {
            let nxt = nums[i + 1];
            if cur > nxt {
                m_c = -1;
            } else if cur < nxt {
                m_c = 1;
            } else {
                m_c = m_l;
            }
            if m_c * m_l < 0 {
                res += 1;
            }
            (m_l, cur) = (m_c, nxt);
        }
        res
    }
}


impl Solution {
    pub fn count_hill_valley_2(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut cur = nums[0];
        let n = nums.len();
        let mut m_c: i32;
        let mut m_l: i32 = 0;
        for i in 0..n - 1 {
            let nxt = nums[i + 1];
            if cur > nxt {
                m_c = -1;
            } else if cur < nxt {
                m_c = 1;
            } else {
                m_c = m_l;
            }
            if m_c * m_l < 0 {
                res += 1;
            }
            (m_l, cur) = (m_c, nxt);
        }
        res
    }
}

fn main() {
    println!(
        "{:?} e:3",
        Solution::count_hill_valley(vec![2, 4, 1, 1, 6, 5])
    );
    println!(
        "{:?} e:0",
        Solution::count_hill_valley(vec![6, 6, 5, 5, 4, 1])
    );
    println!(
        "{:?} e:2",
        Solution::count_hill_valley(vec![
            1, 1, 1, 1, 1, 1, 1, 57, 57, 57, 50, 50, 50, 50, 22, 22, 22, 86
        ])
    );
}

//
// Created by zhiya at 7/27/2025 5:13 PM
//
