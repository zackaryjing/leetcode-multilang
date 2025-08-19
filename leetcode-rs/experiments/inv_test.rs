const MOD: i64 = 1000_000_007;
fn q_pow(num: i64, mut t: i64) -> i64 {
    let mut res = 1;
    let mut temp = num;
    while t > 0 {
        println!("{:b} {:?}", t, temp);
        if (t & 1) == 1 {
            res = (res * temp) % MOD;
        }
        temp = (temp * temp) % MOD;
        t >>= 1;
    }
    res
}

fn inv(num: i64) -> i64 {
    let mut t = MOD - 2;
    let mut res = 1;
    let mut temp = num;
    while t > 0 {
        if (t & 1) == 1 {
            res = (res * temp) % MOD;
        }
        temp = (temp * num) % MOD;
        t >>= 1;
    }
    res
}

fn main() {
    let num = 101;
    let inum = inv(num);
    let k = 789;
    println!("{:?} ,{:?}", 789 / num, (789 * inum) % MOD);

    println!("{:?} 16", q_pow(2, 4));
    println!("{:?} 625", q_pow(5, 4));
}
