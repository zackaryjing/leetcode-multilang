// problem: https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/
struct Solution;

use std::cmp::min;
impl Solution {
    pub fn find_the_distance_value(mut arr1: Vec<i32>, mut arr2: Vec<i32>, d: i32) -> i32 {
        let base = 1000000;
        let limit = base - 2000;
        arr1.extend(arr2.into_iter().map(|num| num + base));
        arr1.sort_by(|mut num1, mut num2| {
            let mut n1 = *num1;
            let mut n2 = *num2;
            if n1 > limit {
                n1 -= base;
            }
            if n2 > limit {
                n2 -= base;
            }
            return n1.cmp(&n2);
        });
        let mut res = i32::MAX;
        let n = arr1.len();
        for i in 0..n - 1 {
            let first = arr1[i];
            let second = arr1[i + 1];
            let mut f_is = false;
            let mut s_is = false;
            if first > limit {
                f_is = true;
            }
            if second > limit {
                s_is = true;
            }
            if f_is ^ s_is {
                res = min(res, (arr1[i] - arr1[i - 1]).abs());
            }
        }
        res
    }
}
fn main() {
    println!(
        "{:?} e:2",
        Solution::find_the_distance_value(vec![4, 5, 8], vec![10, 9, 1, 8],2)
    );
    println!(
        "{:?} e:2",
        Solution::find_the_distance_value(vec![1,3,2,3],vec![-4,-3,6,10,20,30],2)
    );
    println!(
        "{:?} e:6",
        Solution::find_the_distance_value(vec![2,1,100,3],vec![-5,-2,10,-3,7],2)
    );
}

//
// Created by jing at 2025-09-07 15:47
//
