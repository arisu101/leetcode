#include <iostream>
class Solution {
public:
  int reverse(int x) {
    int temp = 0;
    while (x != 0) {
      temp = temp * 10 + (x % 10);
      x = (int)x / 10;
    }
    return temp;
  }
};
int main(int argc, char *argv[]) {
  int number;
  std::cin >> number;
  std::cout << Solution().reverse(number);
  return 0;
}
