#include <iostream>
#include <stack>
#include <unordered_map>
class Solution {
public:
  bool isValid(std::string s) {
    std::unordered_map<char, char> check = {{'[', ']'}, {'{', '}'}, {'(', ')'}};
    int n = s.size();
    if (n % 2 != 0)
      return false;
    std::stack<char> c;
    for (char ch : s) {
      if (check.find(ch) != check.end()) {
        c.push(ch);
      } else {
        if (c.empty()) {
          return false;
        };
        // {(})
        char top = c.top();
        c.pop();
        if (check.find(top) == check.end() || check[top] != ch) {
          return false;
        }
      }
    }
    return c.empty();
  }
};
int main(int argc, char *argv[]) {
  std::string input;
  std::cin >> input;
  std::string final = Solution().isValid(input) ? "true" : "false";
  std::cout << final;
  return 0;
}
