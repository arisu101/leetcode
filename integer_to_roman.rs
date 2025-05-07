#[derive(Debug)]
struct Solution;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let map = [
            ("M", 1000),
            ("CM", 900),
            ("D", 500),
            ("CD", 400),
            ("C", 100),
            ("XC", 90),
            ("L", 50),
            ("XL", 40),
            ("X", 10),
            ("IX", 9),
            ("V", 5),
            ("IV", 4),
            ("I", 1),
        ];
        let mut _s = String::new();
        let mut _n = num;
        for (_sym, _val) in map.iter() {
            while _n >= *_val {
                _s.push_str(_sym);
                _n -= *_val;
            }
        }
        _s
    }
}
fn main() {
    let num = 2994;
    println!("{}", Solution::int_to_roman(num));
}
