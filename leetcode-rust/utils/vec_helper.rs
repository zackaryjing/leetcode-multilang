// pretty_print.rs
use std::fmt::Display;

/// 打印一个二维 Vec，列宽自适应对齐
pub fn print_matrix<T: Display>(matrix: &[Vec<T>]) {
    if matrix.is_empty() {
        println!("[空矩阵]");
        return;
    }

    let cols = matrix[0].len();
    let mut col_widths = vec![0; cols];

    // 计算每列最大宽度
    for row in matrix {
        for (i, val) in row.iter().enumerate() {
            let len = format!("{}", val).len();
            if len > col_widths[i] {
                col_widths[i] = len;
            }
        }
    }

    // 打印每行
    for row in matrix {
        for (i, val) in row.iter().enumerate() {
            print!("{:>width$} ", val, width = col_widths[i]);
        }
        println!();
    }
}
