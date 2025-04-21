// problem: https://leetcode.cn/problems/count-the-number-of-fair-pairs/?envType=daily-question&envId=2025-04-19
struct Solution;

impl Solution {
    pub fn count_fair_pairs(nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        let mut nums = nums;
        nums.sort();
        let mut res = 0i64;
        // println!("{:?}", nums);
        for i in 0..nums.len() {
            let left = nums[0..i].partition_point(|num| num + nums[i] < lower);
            let right = nums[0..i].partition_point(|num| num + nums[i] <= upper);
            // println!("l {:?}, r {:?}", left, right);
            res += (right - left) as i64;
        }
        res
    }
}

impl Solution {
    // FIXME: [Fatal] TLE
    pub fn count_fair_pairs_2(nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        let mut nums = nums;
        nums.sort();
        let mut res = 0i64;
        let n = nums.len();
        let mut cur: usize = 0;
        let mut left: usize = 0;
        let mut right: usize = 0;
        let mut found = false;
        for i in 1..n {
            if nums[i] + nums[i - 1] < lower {
                continue;
            }
            if nums[i] + nums[0] > upper {
                break;
            }
            for k in (0..i).rev() {
                let temp = nums[i] + nums[k];
                if lower <= temp && temp <= upper {
                    cur = i;
                    right = k;
                    found = true;
                    break;
                }
            }
            if found {
                break;
            }
        }
        if found {
            for j in 0..=cur {
                if nums[j] + nums[cur] >= lower {
                    left = j;
                    break;
                }
            }
        } else {
            return 0;
        }

        // println!("{:?}", nums);
        // println!("{:?},{:?},{:?} <-----", left, right, cur);

        for c in cur..n {
            while right > 0 && nums[right] + nums[c] > upper {
                right -= 1;
            }

            while right + 1 < c && nums[right + 1] + nums[c] <= upper {
                right += 1;
            }

            while left > 0 && nums[left - 1] + nums[c] >= lower {
                left -= 1;
            }
            // println!("{:?},{:?},{:?}", left, right, c);
            if right < left || nums[right] + nums[c] > upper {
                break;
            }
            res += (right - left + 1) as i64;
        }
        res
    }
}

fn main() {
    println!(
        "{:?} 15",
        Solution::count_fair_pairs(vec![0, 0, 0, 0, 0, 0], 0, 0)
    );
    println!(
        "{:?} 6",
        Solution::count_fair_pairs(vec![0, 1, 7, 4, 4, 5], 3, 6)
    );
    println!(
        "{:?} 1",
        Solution::count_fair_pairs(vec![1, 7, 9, 2, 5], 11, 11)
    );
}

//
// Created by zhiya at 2025/4/20 13:27
//
