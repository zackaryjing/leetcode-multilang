// problem: https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/
struct Solution;

impl Solution {
    pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32 {
        let n = students.len();
        let s1 = students.iter().filter(|&&num| num == 1).count();
        let w1 = sandwiches.iter().filter(|&&num| num == 1).count();
        if s1 == w1 {
            return 0;
        }
        let (to_find, mut cnt) = if s1 > w1 { (0, s1 - w1) } else { (1, w1 - s1) };
        for i in (0..n).rev() {
            if sandwiches[i] == to_find {
                cnt -= 1;
            }
            if cnt == 0 {
                return (n - i) as i32;
            }
        }
        0
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::count_students(vec![1, 1, 0, 0], vec![0, 1, 0, 1])
    );
    println!(
        "{:?}",
        Solution::count_students(vec![1, 1, 1, 0, 0, 1], vec![1, 0, 0, 0, 1, 1])
    );
}

//
// Created by jing at 2025-09-18 12:48
//
