// problem: https://leetcode.cn/problems/find-the-original-typed-string-ii/submissions/640797660/?envType=daily-question&envId=2025-07-02
struct Solution;

use std::cmp::{max, min};
impl Solution {
    // [Pass] performance ok
    pub fn possible_string_count(word: String, k: i32) -> i32 {
        let MOD = 1000_000_007i64;
        let word = word.as_bytes();
        let mut mul_list = Vec::new();
        let mut mul_cnt = 0i64;
        let mut res = 1;
        let mut minium = 0;
        for i in 1..word.len() {
            if word[i] == word[i - 1] {
                mul_cnt += 1;
            } else {
                if mul_cnt > 0 {
                    mul_list.push(mul_cnt);
                    res = (res * (mul_cnt + 1)) % MOD;
                    // println!("res: {:?}",res);
                    mul_cnt = 0;
                }
                minium += 1;
            }
        }
        minium += 1;
        if mul_cnt > 0 {
            mul_list.push(mul_cnt);
            res = (res * (mul_cnt + 1)) % MOD;
            // println!("res: {:?}",res);
        }
        if mul_list.is_empty() {
            return if word.len() >= k as usize { 1 } else { 0 };
        }
        let n = mul_list.len();
        if minium >= k as usize {
            return res as i32;
        }
        let m = k as i64 - minium as i64 - 1;

        let mut dp = vec![vec![0i64; m as usize + 1]; 2];
        for j in 0..=min(mul_list[0], m) as usize {
            dp[0][j] = 1;
        }
        let mut max_reach = mul_list[0];
        for i in 1..n {
            let (last, cur) = if i & 1 == 1 {
                let (left, right) = dp.split_at_mut(1);
                (&mut left[0], &mut right[0])
            } else {
                let (right, left) = dp.split_at_mut(1);
                (&mut left[0], &mut right[0])
            };
            cur[0] = 1;
            let cur_limit = mul_list[i];
            max_reach += cur_limit;
            let first_stage = min(cur_limit, m) as usize;
            for j in 1..=first_stage{
                cur[j] = (last[j] + cur[j - 1]) % MOD;
            }
            let mut base: i64 = cur[first_stage] - cur[0];
            for j in first_stage + 1..=min(max_reach, m) as usize {
                base += last[j] % MOD;
                cur[j] = base % MOD;
                base = (base + MOD - last[j - cur_limit as usize]) % MOD;
                base %= MOD;
            }
        }
        // println!("res: {:?}",res);
        // println!("{:?}",dp);
        let mut s = 0;

        let cur = &dp[(n - 1) % 2];
        for j in 0..=m as usize {
            s += cur[j] % MOD;
            s %= MOD;
        }
        ((res + MOD - s) % MOD) as i32
    }
}

impl Solution {
    // [TLE] too...
    pub fn possible_string_count_3(word: String, k: i32) -> i32 {
        const MOD: i64 = 1000_000_007;
        let word = word.as_bytes();
        let mut mul_list = Vec::new();
        let mut mul_cnt = 0;
        for i in 1..word.len() {
            if word[i] == word[i - 1] {
                mul_cnt += 1;
            } else {
                if mul_cnt > 0 {
                    mul_list.push(mul_cnt);
                    mul_cnt = 0;
                }
            }
        }
        if mul_cnt > 0 {
            mul_list.push(mul_cnt);
        }
        if mul_list.is_empty() {
            return if word.len() >= k as usize { 1 } else { 0 };
        }
        let w_size = word.len();
        let m = w_size - k as usize;
        let n = mul_list.len();
        let mut dp = vec![vec![0i64; m + 1]; 2];
        for j in 0..=min(mul_list[0], m) {
            dp[0][j] = 1;
        }
        let mut max_reach = mul_list[0];
        for i in 1..n {
            let (last, cur) = if i & 1 == 1 {
                let (left, right) = dp.split_at_mut(1);
                (&mut left[0], &mut right[0])
            } else {
                let (right, left) = dp.split_at_mut(1);
                (&mut left[0], &mut right[0])
            };
            cur[0] = 1;
            let cur_limit = mul_list[i];
            max_reach += cur_limit;
            for j in 1..=min(cur_limit, m) {
                cur[j] = (last[j] + cur[j - 1]) % MOD;
            }
            let mut base: i64 = cur[min(cur_limit, m)] - cur[0];
            for j in min(cur_limit, m) + 1..=min(max_reach, m) {
                base += last[j] % MOD;
                cur[j] = base % MOD;
                base = (base + MOD - last[j - cur_limit]) % MOD;
                base %= MOD;
            }
        }
        let mut res = 0;
        let cur = &dp[(n - 1) % 2];
        for j in 0..=m {
            res += cur[j] % MOD;
            res %= MOD;
        }
        res as i32
    }
}

impl Solution {
    // [MLE] easy to handle
    pub fn possible_string_count_2(word: String, k: i32) -> i32 {
        const MOD: i64 = 1000_000_007;
        let word = word.as_bytes();
        let mut mul_list = Vec::new();
        let mut mul_cnt = 0;
        for i in 1..word.len() {
            if word[i] == word[i - 1] {
                mul_cnt += 1;
            } else {
                if mul_cnt > 0 {
                    mul_list.push(mul_cnt);
                    mul_cnt = 0;
                }
            }
        }
        if mul_cnt > 0 {
            mul_list.push(mul_cnt);
        }
        if mul_list.is_empty() {
            return if word.len() >= k as usize { 1 } else { 0 };
        }
        let w_size = word.len();
        let m = w_size - k as usize;
        let n = mul_list.len();
        let mut dp = vec![vec![0i64; m + 1]; n];
        for j in 0..=min(mul_list[0], m) {
            dp[0][j] = 1;
        }
        let mut max_reach = mul_list[0];
        for i in 1..n {
            dp[i][0] = 1;
            max_reach += mul_list[i];
            for j in 1..=min(mul_list[i], m) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
            let mut base: i64 = dp[i][min(mul_list[i], m)] - dp[i][0];
            for j in min(mul_list[i], m) + 1..=min(max_reach, m) {
                base += dp[i - 1][j] % MOD;
                dp[i][j] = base % MOD;
                base = (base + MOD - dp[i - 1][j - mul_list[i]]) % MOD;
                base %= MOD;
            }
        }
        let mut res = 0;
        for j in 0..=m {
            res += dp[n - 1][j] % MOD;
            res %= MOD;
        }
        res as i32
    }
}

fn main() {
    println!(
        "{:?} 5",
        Solution::possible_string_count("aabbccdd".to_string(), 7)
    );
    println!(
        "{:?} 8",
        Solution::possible_string_count("aaabbb".to_string(), 3)
    );
    println!("{:?} 1", Solution::possible_string_count("d".to_string(), 1));
    println!(
        "{:?} ",
        Solution::possible_string_count("dddqq".to_string(), 2)
    );
    println!(
        "{:?} ",
        Solution::possible_string_count("kkkoohh".to_string(), 3)
    );
    // println!(
    //     "{:?}",
    //     Solution::possible_string_count(
    //         "ggggggggaaaaallsssssaaaaaaaaaiiqqqqqqqqqqbbbbbbbvvfffffjjjjeeeeeefffmmiiiix"
    //             .to_string(),
    //         34
    //     )
    // );
    // println!(
    //     "{:?}",
    //     Solution::possible_string_count("aaafffffeeeeoooooobbbbbbbbggghhhhhhheeeeeeewwwwwwwwiiiiiiiijjjjjjjjaaaannnnnnniiiiiiimmmmmmmmrrrrrrrriieeeiiiiiiyyyybbbbbbbbbbbbbbbbbbbbzzzzeelllllllliiippppmmmmmmmmmmuuuuuuunnnnnnnnzzzzzzzzzzijjjjvvb".to_string(), 118)
    // );
    // println!(
    //     "{:?}",
    //     Solution::possible_string_count("ddddddddnnjjjjjyyyyyyuuugggguuuqqqqddddddfffffrrrrrraaadddddddaaaaaaaaaggggggggggqqqqqqqqhhhhhhffffffffffyyyyywwwwwwwwwwiiiiixxxxxxxxxxzzuiiiiiiiiiimmmmmzzzxxxxxxxxxxcffffffffllllllllhhhhhhqqqqttttttttttssssssssstttttttxxxxxxtgggbbbbaaaaaarrrrraaaaaaaeeeerrbbbzzzzzzzooooooozkkkkkkkkkffffyyyyyyyyyybbbbbbbtgdddddddqqyyyyywwwwvllllllllllkvvvvvvvvggrrrrrrrrvviiiiiiikkkkkkkkeeeeeeecccccccccceeeeeeeeeoo".to_string(), 120)
    // );
}

//
// Created by zhiya at 7/2/2025 8:15 PM
//
