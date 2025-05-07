#[derive(Debug)]
struct Solution {
    s: String,
}
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let mut res: String = String::new();
        let mut res_len: usize = 0;
        { 0..s.len() }.for_each(|i| {
            //for odd length of palindrome sequence
            let (mut l, mut r) = (i, i);
            while l >= 0 && r < s.len() && s.chars().nth(l) == s.chars().nth(r) {
                if (r - l + 1) > res_len {
                    res = s[l..r + 1].to_string();
                    res_len = r - l + 1;
                }
                if l != 0 {
                    l -= 1;
                }
                r += 1;
            }
            (l, r) = (i, i + 1);
            while l >= 0 && r < s.len() && s.chars().nth(l) == s.chars().nth(r) {
                if (r - l + 1) > res_len {
                    res = s[l..r + 1].to_string();
                    res_len = r - l + 1;
                }
                if l != 0 {
                    l -= 1;
                }
                r += 1;
            }
        });
        res
    }
}

fn main() {
    let word: String = String::from("aaabaaaa");
    println!("{}", Solution::longest_palindrome(word));
}
