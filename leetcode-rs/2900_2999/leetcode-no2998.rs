// problem: https://leetcode.cn/problems/minimum-number-of-operations-to-make-x-and-y-equal/description/
struct Solution;
use std::cmp::min;
impl Solution {
    pub fn minimum_operations_to_make_equal(x: i32, y: i32) -> i32 {
        if y >= x {
            return y - x;
        }
        let mut ans = x - y;
        let mut vis = vec![false; x as usize + 11];

        let mut add = |place: i32, places: &mut Vec<i32>| {
            if 0 <= place && place < x + 11 && !vis[place as usize] {
                vis[place as usize] = true;
                places.push(place);
            }
        };

        let mut step = 0;
        let mut arrived = vec![x];
        loop {
            // println!("step: {:?}", step);
            let mut places = vec![];
            for &place in &arrived {
                if place == y {
                    // println!("{:?} {:?}", place, y);
                    return min(step, ans);
                }
                if (place % 11) == 0 {
                    add(place / 11, &mut places);
                }
                if (place % 5) == 0 {
                    add(place / 5, &mut places);
                }
                add(place - 1, &mut places);
                add(place + 1, &mut places);
            }
            step += 1;
            arrived = places;
        }
    }
}

fn main() {
    println!("{:?} 3", Solution::minimum_operations_to_make_equal(26, 1));
    println!("{:?} 4", Solution::minimum_operations_to_make_equal(54, 2));
    println!("{:?} 5", Solution::minimum_operations_to_make_equal(25, 30));
    println!("{:?}", Solution::minimum_operations_to_make_equal(147, 31));
}

//
// Created by zhiya at 7/3/2025 11:51 PM
//