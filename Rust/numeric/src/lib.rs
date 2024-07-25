///! # Numerical Input Library
///!
use std::io;
use std::io::{stdout, Write}; 

/// Numerical Input
/// 
/// ## 引数
/// title　Title to be displayed before entering
/// 
/// ## 戻り値
/// Number entered (in case of an error, a message with the cause is returned)
/// 
/// ##  Examples
/// ```text  
/// match read_line_base::<T>("input number:".to_string()) {
///   Ok(val) => println!("[OK] val = {}", val),
///   Err(err) => eprintln!("[ERR]{}", err),
/// };
/// ```
/// 
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

/// Numerical input with limited number of re-entries
/// 
/// ## 型指定
/// T           String to numeric conversion type
/// 
/// ## 引数
/// title       Title to be displayed before entering
/// def_val     initial value  
/// retry_count Re-entry count
/// 
/// ## 戻り値
/// `Option<T>`（Returns None on error）
///
/// ##  Examples
/// ```text  
///　let ret = numeric::read_line::<i32>("Please enter any number here: ".to_string(), 3);
///  match ret {
///    Some(value) => println!("[OK] val = {:?}\n", value),
///    None => println!("[ERR] retry over!!\n"),        
///  };
/// 
/// ```
pub fn read_line<T: 'static +  std::str::FromStr>(title: String, retry_count: i32) -> Option<T> where <T as std::str::FromStr>::Err: std::fmt::Display {
    let mut ret: Option<T> = None;

    for _n in 0..retry_count {
        match read_line_base::<T>(title.to_string()) {
            Ok(ans) => {ret = Some(ans); break},
            Err(err) => eprintln!("[ERR]{}", err),
        };
    }
    ret
}
