
pub fn foo(k:&mut i32) {
    *k += 1;
    println!("{:?}",k);
}
fn main() {
    let mut h = 100;
    foo(&mut h);
}
