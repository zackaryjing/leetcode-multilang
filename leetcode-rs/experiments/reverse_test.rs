fn main() {
    let temp = vec![1, 1, 1, 1, 1, 1];
    let pos1 = temp.partition_point(|num| *num < 2);
    println!("{:?}", pos1);
    let pos2 = temp.partition_point(|num| *num < 0);
    println!("{:?}", pos2);
}
