extern crate numeric;

fn main() {
    println!("test read_line");
    let ret = numeric::read_line::<i32>("Please enter any number here: ".to_string());
    match ret {
        Ok(value) => println!("[OK] val = {:?}\n", value),
        Err(e) => eprintln!("[ERR] {:?}", e),        
    };

    println!("test read_line_retry");
    let ret = numeric::read_line_retry::<i32>("Please enter any number here: ".to_string(), 3);
    match ret {
        Some(value) => println!("[OK] val = {:?}", value),
        None => eprintln!("[ERR] retry over!!"),        
    };
}
