use std::io;
use std::io::{stdout, Write}; 

fn read_line_base<T:'static + std::str::FromStr>(title: String) -> std::result::Result<T, <T as std::str::FromStr>::Err> {
    // title
    print!("{}", title);
    stdout().flush().unwrap();

    // input numeric
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).expect("Something went wrong while typing");
    let num = buffer.trim().parse::<T>()?;
    Ok(num)
}    
pub struct NumericResult<T> {
    pub result: bool,
    pub val: T,
}    
pub fn read_line<T: 'static +  std::str::FromStr>(title: String, def_val: T, retry_count: i32) -> NumericResult<T> where <T as std::str::FromStr>::Err: std::fmt::Display {
    let mut is_success: bool = false;
    let mut ret: T = def_val;

    for _n in 0..retry_count {
        match read_line_base::<T>(title.to_string()) {
            Ok(ans) => {ret = ans; is_success = true; break},
            Err(err) => eprintln!("[ERR]{}", err),
        };    
    }
    NumericResult::<T>{result:is_success, val: ret}
}    
