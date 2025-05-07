fn convert(s: String, num_rows: usize) -> String {
    if num_rows == 1 {
        return s;
    }
    let mut rows: Vec<String> = vec![String::new(); num_rows as usize];
    let mut current_row = 0;
    let mut going_down = false;
    for c in s.chars() {
        rows[current_row].push(c);
        if current_row == 0 || current_row == num_rows - 1 {
            going_down = !going_down;
        }
        current_row = if going_down {
            current_row + 1
        } else {
            current_row - 1
        };
    }
    rows.into_iter().collect()
}

fn main() {
    let s = "PAYPALISHIRING".to_string();
    let num_rows = 3;
    let result = convert(s, num_rows);
    println!("{}", result);
}
