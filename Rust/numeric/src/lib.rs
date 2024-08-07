///! # Numerical Input Library
///!
use std::io;
use std::io::{stdout, Write}; 

/// Numerical Input
/// 
/// ## Parameters
/// title　Title to be displayed before entering
/// 
/// ## Return
/// Number entered (in case of an error, a message with the cause is returned)
/// 
/// ##  Examples
/// ```text  
/// match read_line::<T>("input number:".to_string()) {
///   Ok(val) => println!("[OK] val = {}", val),
///   Err(err) => eprintln!("[ERR]{}", err),
/// };
/// ```
/// 
pub fn read_line<T:'static + std::str::FromStr>(title: String) -> std::result::Result<T, <T as std::str::FromStr>::Err> {
    // title
    print!("{}", title);
    stdout().flush().unwrap();

    // input numeric
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).expect("Something went wrong while typing");
    let num = buffer.trim().parse::<T>()?;
    Ok(num)
}    

/// Numerical input with limited number of re-entries
/// 
/// ## Type
/// T           String to numeric conversion type
/// 
/// ## Parameters
/// title       Title to be displayed before entering
/// def_val     initial value  
/// retry_count Re-entry count
/// 
/// ## Return
/// `Option<T>`（Returns None on error）
///
/// ##  Examples
/// ```text  
///　let ret = numeric::read_line_retry::<i32>("Please enter any number here: ".to_string(), 3);
///  match ret {
///    Some(value) => println!("[OK] val = {:?}\n", value),
///    None => println!("[ERR] retry over!!\n"),        
///  };
/// 
/// ```
pub fn read_line_retry<T: 'static +  std::str::FromStr>(title: String, retry_count: i32) -> Option<T> where <T as std::str::FromStr>::Err: std::fmt::Display {
    let mut ret: Option<T> = None;

    for _n in 0..retry_count {
        match read_line::<T>(title.to_string()) {
            Ok(ans) => {ret = Some(ans); break},
            Err(err) => eprintln!("[ERR]{}", err),
        };
    }
    ret
}
