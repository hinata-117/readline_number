extern crate numeric;

/**
 * メイン処理
 * 
 * @param なし
 * @return なし
*/
fn main() {
    test_readline_i32();
    test_readline_f32();
}
/**
 * i32数値入力テスト
 * 
 * @param なし
 * @return なし
*/
fn test_readline_i32() {
    let ret = numeric::read_line::<i32>("Please enter any number here: ".to_string(), 0, 3);
    if ret.result {
        println!("[OK] {}\n", ret.val);
    }
}
/**
 * f32数値入力テスト
 * 
 * @param なし
 * @return なし
*/
fn test_readline_f32() {
    let ret = numeric::read_line::<f32>("Please enter any number here: ".to_string(), 0.0, 3);
    if ret.result {
        println!("[OK] {}\n", ret.val);
    }
}
