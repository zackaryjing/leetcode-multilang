fn y_h<'a, A, O>(f: impl Fn(&dyn Fn(A) -> O, A) -> O + 'a) -> impl Fn(A) -> O + 'a {
    fn real_y<'a, A, O>(f: &'a dyn Fn(&dyn Fn(A) -> O, A) -> O) -> impl Fn(A) -> O + 'a {
        move |a| f(&real_y(f), a)
    }
    move |a| real_y(&f)(a)
}

fn y<'a, A, O, C>(f: impl Fn(&dyn Fn(A, C) -> O, A, C) -> O + 'a) -> impl Fn(A, C) -> O + 'a {
    fn real_y<'a, A, O, C>(
        f: &'a dyn Fn(&dyn Fn(A, C) -> O, A, C) -> O,
    ) -> impl Fn(A, C) -> O + 'a {
        move |a, c| f(&real_y(f), a, c)
    }
    move |a, c| real_y(&f)(a, c)
}

fn main() {
    let mut h = 0;
    let fact = y(|f, n, m| {
        if n == 0 {
            1 + m
        } else {
            n * f(n - 1, m + 1)
        }
    });

    let mut a = 10;
    let mut b = 20;
    let mut c = 30;
    (c, b, a) = (a, c, b);
    println!("a: {:?} b: {:?} c: {:?} ", a, b, c);

    println!("{}", fact(5, 6)); // 输出 120
    fn fact_fn(n: i32, m: i32) -> i32 {
        if n == 0 {
            1 + m
        } else {
            n * fact_fn(n - 1, m + 1)
        }
    }
    println!("{}", fact_fn(5, 6)); // 输出 120
}
