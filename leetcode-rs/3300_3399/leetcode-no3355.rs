// problem: https://leetcode.cn/problems/zero-array-transformation-i/?envType=daily-question&envId=2025-05-20
struct Solution;

impl Solution {
    pub fn is_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> bool {
        let n = nums.len();
        let mut diff = vec![0; n + 1];
        for query in queries {
            diff[query[0] as usize] += 1;
            diff[1 + query[1] as usize] -= 1;
        }
        // println!("{:?}\n{:?}", diff, nums);
        if nums[0] > diff[0] {
            return false;
        }
        for i in 1..n {
            diff[i] += diff[i - 1];
            if diff[i] < nums[i] {
                return false;
            }
        }
        true
    }
}

impl Solution {
    // [Pass] Well it is still slow.
    pub fn is_zero_array_3(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> bool {
        let mut first: Vec<i32> = queries.iter().map(|num| num[0]).collect();
        let mut second: Vec<i32> = queries.iter().map(|num| num[1]).collect();
        first.sort();
        second.sort();
        let n = nums.len();
        let m = queries.len();
        let mut pos1 = 0usize;
        let mut pos2 = 0usize;
        for i in 0..n {
            while pos1 < m && first[pos1] <= i as i32 {
                pos1 += 1;
            }
            while pos2 < m && second[pos2] < i as i32 {
                pos2 += 1;
            }
            if ((pos1 - pos2) as i32) < nums[i] {
                return false;
            }
        }
        true
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::is_zero_array(vec![1, 0, 1], vec![vec![0, 2]])
    );
    println!(
        "{:?}",
        Solution::is_zero_array(vec![4, 3, 2, 1], vec![vec![1, 3], vec![0, 2]])
    );
    println!(
        "{:?}",
        Solution::is_zero_array(
            vec![4, 6],
            vec![
                vec![0, 0],
                vec![0, 1],
                vec![1, 1],
                vec![0, 0],
                vec![1, 1],
                vec![1, 1],
                vec![0, 0],
                vec![1, 1],
                vec![1, 1],
                vec![1, 1],
                vec![0, 0],
                vec![1, 1],
                vec![0, 1],
                vec![0, 0],
                vec![1, 1]
            ]
        )
    );
}

impl Solution {
    // [TLE] correct but useless...
    pub fn is_zero_array_2(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> bool {
        let n = nums.len();
        let mut tot = vec![0; n];
        for query in queries {
            for i in query[0]..=query[1] {
                tot[i as usize] += 1;
            }
        }
        for k in 0..n {
            if tot[k] < nums[k] {
                return false;
            }
        }
        true
    }
}

//
// Created by zhiya at 2025/5/20 10:29
//
