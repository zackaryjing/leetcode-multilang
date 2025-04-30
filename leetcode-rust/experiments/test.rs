fn y<'a, A, O>(f: impl Fn(&dyn Fn(A) -> O, A) -> O + 'a) -> impl Fn(A) -> O + 'a {
    fn real_y<'a, A, O>(f: &'a dyn Fn(&dyn Fn(A) -> O, A) -> O) -> impl Fn(A) -> O + 'a {
        move |a| f(&real_y(f), a)
    }
    move |a| real_y(&f)(a)
}


fn main() {
    let fact = y(|f, n| {
        if n == 0 {
            1
        } else {
            n * f(n - 1)
        }
    });

    println!("{}", fact(5)); // 输出 120
}
