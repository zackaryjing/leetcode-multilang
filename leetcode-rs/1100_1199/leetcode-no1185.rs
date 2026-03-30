// problem:
struct Solution;

use std::collections::HashMap;
impl Solution {
    pub fn day_of_the_week(day: i32, month: i32, year: i32) -> String {
        let weekday = vec![
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
        ];
        let monthdays = vec![0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
        let monthsum: Vec<i32> = monthdays
            .iter()
            .scan(0, |a, &b| {
                *a += b;
                Some(*a)
            })
            .collect();
        let mut day = monthsum[month as usize - 1] + day;
        if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0)) && month > 2 {
            day += 1;
        }
        day += (year - 1971) * 365;
        day += (year - 1969) / 4;
        weekday[(day as usize + 4) % 7].to_string()
    }
}

fn main() {
    println!("{:?}", Solution::day_of_the_week(1, 1, 1971));
    println!("{:?}", Solution::day_of_the_week(28, 2, 1974));
    println!("{:?}", Solution::day_of_the_week(31, 8, 2019));
    println!("{:?}", Solution::day_of_the_week(18, 7, 1999));
    println!("{:?}", Solution::day_of_the_week(15, 8, 1993));
}

//
// Created by zhiya at 2026/3/28 21:29
//
