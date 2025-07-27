// problem: https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
struct Solution;

use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn alert_names(key_name: Vec<String>, key_time: Vec<String>) -> Vec<String> {
        let n = key_name.len();
        fn to_ts(time: &String) -> i32 {
            let hour_miniut: Vec<&str> = time.split(':').collect();
            let hour = hour_miniut[0].parse::<i32>().unwrap();
            let miniut = hour_miniut[1].parse::<i32>().unwrap();
            hour * 60 + miniut
        }

        let mut res: HashSet<String> = HashSet::new();
        let mut records: HashMap<String, Vec<i32>> = HashMap::new();
        for i in 0..n {
            records
                .entry(key_name[i].clone())
                .or_default()
                .push(to_ts(&key_time[i]));
        }

        for (name, val) in records.iter_mut() {
            val.sort();
            let m = val.len();
            if m < 3 {
                continue;
            } else {
                let mut last = val[0];
                let mut least = val[1];
                for i in 2..m {
                    let time = val[i];
                    if time > last && time - last <= 60 {
                        res.insert(name.clone());
                        break;
                    } else {
                        last = least;
                        least = time;
                    }
                }
            }
        }
        let mut res: Vec<String> = res.into_iter().collect();
        res.sort();
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::alert_names(
            vec![
                "daniel".to_string(),
                "daniel".to_string(),
                "daniel".to_string(),
                "luis".to_string(),
                "luis".to_string(),
                "luis".to_string(),
                "luis".to_string()
            ],
            vec![
                "10:00".to_string(),
                "10:40".to_string(),
                "11:00".to_string(),
                "09:00".to_string(),
                "11:00".to_string(),
                "13:00".to_string(),
                "15:00".to_string()
            ]
        )
    );
}

//
// Created by zhiya at 7/21/2025 1:20 PM
//
