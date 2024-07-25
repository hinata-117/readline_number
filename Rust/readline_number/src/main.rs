extern crate numeric;

fn main() {
    let ret = numeric::read_line::<i32>("Please enter any number here: ".to_string(), 3);
    match ret {
        Some(value) => println!("[OK] val = {:?}\n", value),
        None => println!("[ERR] retry over!!\n"),        
    };
}
