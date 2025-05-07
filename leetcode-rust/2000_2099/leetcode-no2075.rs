// problem: https://leetcode.cn/problems/decode-the-slanted-ciphertext/
struct Solution;

impl Solution {
    pub fn decode_ciphertext(encoded_text: String, rows: i32) -> String {
        let rows: usize = rows as usize;
        let encoded_text = encoded_text.as_bytes();
        let cols = encoded_text.len() / rows;
        if cols == 0 {
            return "".to_string();
        }
        let mut res = vec![b' '; encoded_text.len() - rows * (rows - 1) / 2];
        for i in 0..rows {
            if cols + i >= rows {
                for j in 0 + i..=cols + i - rows {
                    res[(j - i) * rows + i] = encoded_text[i * cols + j];
                }
            }
            for j in cols + i + 1 - rows..cols {
                // println!("{:?} {:?}", j, i);
                let temp = j as i32 - (cols as i32 + i as i32 - rows as i32) as i32;
                let delta = if temp <= 0 { 0 } else { (temp * (temp - 1) / 2) as usize};
                res[(j - i) * rows + i - delta] = encoded_text[i * cols + j];
            }
        }
        res.into_iter()
            .map(|c| c as char)
            .collect::<String>()
            .trim_end()
            .to_string()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::decode_ciphertext("ch   ie   pr".to_string(), 3)
    );
    println!(
        "{:?}",
        Solution::decode_ciphertext("iveo    eed   l te   olc".to_string(), 4)
    );
    println!("{:?}", Solution::decode_ciphertext("coding".to_string(), 1));
    println!("{:?}", Solution::decode_ciphertext("".to_string(), 5));
    println!("{:?}", Solution::decode_ciphertext("a ".to_string(), 2));
}

//
// Created by zhiya at 2025/5/6 23:35
//
