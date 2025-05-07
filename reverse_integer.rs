fn main() {
    use std::io;

    let mut number = String::new();

    io::stdin()
        .read_line(&mut number)
        .expect("failed to read line");
    let num: i32 = number.trim().parse().expect("Input is not a valid integer");

    let result = Solution::reverse(num);
    print!("{}", result);
}

struct Solution;
impl Solution {
    pub fn reverse(x: i32) -> i32 {
        const INT_MAX: i32 = 2_147_483_647;
        const INT_MIN: i32 = -2_147_483_648;
        let mut temp = 0;
        let mut x = x;
        while x != 0 {
            let digit = x % 10;
            x = x / 10;
            if (temp > 0 && temp > (INT_MAX - digit) / 10)
                || (temp < 0 && temp < (INT_MIN - digit) / 10)
            {
                return 0;
            }
            temp = temp * 10 + digit;
        }
        temp
    }
}
