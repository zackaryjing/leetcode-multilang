use std::cmp::Ordering;
use std::u32;

#[derive(Eq, PartialEq)]
struct OrdNum(i32);

const BASE: usize = 15;
const SIGN_MASK: i32 = (!(u32::MAX >> 1)) as i32;

fn aligment(mut num: i32) -> (i32, i32) {
    let mut rlength = 0;
    while num > 0 {
        num <<= 1;
        rlength += 1;
    }
    (rlength, num)
}
impl Ord for OrdNum {
    fn cmp(&self, other: &Self) -> Ordering {
        let all_zero1 = (self.0 & (self.0 + 1)) == 0;
        let all_zero2 = (other.0 & (other.0 + 1)) == 0;
        if all_zero1 & all_zero2 {
            Ordering::Equal
        } else if all_zero1 {
            Ordering::Greater
        } else if all_zero2 {
            Ordering::Less
        } else {
            // println!("m: {:?}", SIGN_MASK);
            let (first_r_len, first) = aligment(self.0 << BASE);
            let (second_r_len, second) = aligment(other.0 << BASE);
            for i in 0..32 - BASE {
                let sign1 = (first << i) & SIGN_MASK;
                let sign2 = (second << i) & SIGN_MASK;
                // println!("i: {:?} , s: {:?} {:?}", i, sign1, sign2,);
                if sign1 == sign2 {
                    continue;
                } else {
                    // println!("s: {:?} {:?}", sign1, sign2);
                    return sign2.cmp(&sign1);
                }
            }

            // println!("l: {:?} {:?}", first_r_len, second_r_len);
            first_r_len.cmp(&second_r_len)
        }
    }
}

impl PartialOrd for OrdNum {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    println!("{:?} true", OrdNum(12) < OrdNum(13));
    println!("{:?} unknow", OrdNum(1) < OrdNum(3));
    println!("{:?} true", OrdNum(5) < OrdNum(11));
    println!("{:?} unknow", OrdNum(7) < OrdNum(15));
    println!("{:?} true", OrdNum(12) < OrdNum(27));
    println!("{:?} true", OrdNum(6) > OrdNum(9));
    println!("{:?} true", OrdNum(12) < OrdNum(25));
}
