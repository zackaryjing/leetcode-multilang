
// problem: https://leetcode.cn/problems/splitting-a-string-into-descending-consecutive-values/
struct Solution;

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn split_string(s: String) -> bool {
        let s = s.as_bytes();
        let n = s.len();
        let check = Rc::new(RefCell::new(None));
        let make_check: Rc<RefCell<Option<Box<dyn Fn(usize, i64) -> bool>>>> = check.clone();
        *make_check.borrow_mut() = Some(Box::new(move |mut pos, past| {
            let mut cur = 0;
            let mut digit = 0;
            while true {
                cur += (s[pos] - '0' as u8) as i64 * 10i64.pow(digit);
                digit += 1;
                if cur == past + 1 {
                    if pos == 0 {
                        return true;
                    }
                    let valid = check.borrow().as_ref().unwrap()(pos - 1, cur);
                    if valid {
                        return true;
                    }
                }
                if pos > 0 {
                    pos -= 1;
                } else {
                    return false;
                }
            }
            false
        }));

        let mut digit = 0;
        let mut val = 0;
        for k in (1..n).rev() {
            val += (s[k] - '0' as u8) as i64 * 10i64.pow(digit);
            digit += 1;
            if make_check.borrow().as_ref().unwrap()(k - 1, val) {
                return true;
            }
        }
        false
    }
}

fn main() {
    println!("{:?}", Solution::split_string("050043".to_string()));
    println!("{:?}", Solution::split_string("64424509442147483647".to_string()));
    ()
}

//
// Created by zhiya at 2025/4/29 15:44
//
