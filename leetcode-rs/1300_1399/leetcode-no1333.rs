// problem: https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
struct Solution;

impl Solution {
    pub fn filter_restaurants(
        restaurants: Vec<Vec<i32>>,
        vegan_friendly: i32,
        max_price: i32,
        max_distance: i32,
    ) -> Vec<i32> {
        // id ,rating , vegan, price, distance
        let mut available = vec![];
        let n = restaurants.len();
        for i in 0..n {
            let place = &restaurants[i];
            if vegan_friendly == 1 && place[2] != 1 {
                continue;
            }
            if place[3] > max_price || place[4] > max_distance {
                continue;
            }
            available.push(place);
        }
        // println!("{:?}",available);
        available.sort_by(|v1, v2| {
            if v1[1] == v2[1] {
                return v1[0].cmp(&v2[0]).reverse();
            } else {
                return v1[1].cmp(&v2[1]).reverse();
            }
        });
        available.iter().map(|v| v[0]).collect()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::filter_restaurants(
            vec![
                vec![1, 4, 1, 40, 10],
                vec![2, 8, 0, 50, 5],
                vec![3, 8, 1, 30, 4],
                vec![4, 10, 0, 10, 3],
                vec![5, 1, 1, 15, 1]
            ],
            1,
            50,
            10
        )
    );
    println!(
        "{:?}",
        Solution::filter_restaurants(
            vec![
                vec![1, 4, 1, 40, 10],
                vec![2, 8, 0, 50, 5],
                vec![3, 8, 1, 30, 4],
                vec![4, 10, 0, 10, 3],
                vec![5, 1, 1, 15, 1]
            ],
            0,
            50,
            10
        )
    );
    println!(
        "{:?}",
        Solution::filter_restaurants(
            vec![
                vec![1, 4, 1, 40, 10],
                vec![2, 8, 0, 50, 5],
                vec![3, 8, 1, 30, 4],
                vec![4, 10, 0, 10, 3],
                vec![5, 1, 1, 15, 1]
            ],
            0,
            30,
            3
        )
    );
}

//
// Created by jing at 2025-09-21 02:54
//
