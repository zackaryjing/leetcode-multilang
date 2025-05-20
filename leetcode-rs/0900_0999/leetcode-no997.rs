// problem: https://leetcode.cn/problems/find-the-town-judge/
struct Solution;

impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut t = vec![0;n as usize];
        let mut h = vec![false;n as usize];
        for people in trust {
            t[people[1] as usize - 1] += 1;
            h[people[0] as usize - 1] = true;
        }
        for i in 0..n as usize {
            if t[i] >= n - 1 && !h[i] {
                return i as i32 + 1;
            }
        }
        -1
    }
}

fn main() {
    println!("{:?}", Solution::find_judge(3,vec![vec![1,3],vec![2,3],vec![3,1]]));
    println!("{:?}", Solution::find_judge(3,vec![vec![1,3],vec![2,3]]));
    println!("{:?}", Solution::find_judge(2,vec![vec![1,2]]));
}

//
// Created by zhiya at 2025/5/7 11:56
//