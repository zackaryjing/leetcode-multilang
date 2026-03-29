// problem: https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/?envType=problem-list-v2&envId=3rBpGyas
struct Solution;

use std::collections::HashMap;
impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let mut groups: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut res: Vec<Vec<i32>> = Vec::new();
        for (index, size) in group_sizes.iter().enumerate() {
            groups.entry(*size).or_default().push(index as i32);
            if (groups.get(size).unwrap().len() == *size as usize) {
                res.push(groups.get(size).unwrap().clone());
                groups.get_mut(size).unwrap().clear();
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::group_the_people(vec![3, 3, 3, 3, 3, 1, 3])
    );
    println!("{:?}", Solution::group_the_people(vec![2, 1, 3, 3, 3, 2]));
}

//
// Created by ASUS at 2026-01-25 15:15
//
