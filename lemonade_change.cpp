#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("Ofast")
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int no_of_fives = 0;
    int no_of_tens = 0;
    for (const auto &ch : bills) {
      switch (ch) {
      case 5:
        no_of_fives++;
        break;
      case 10:
        no_of_tens++;
        no_of_fives--;
        break;
      case 20:
        if (no_of_tens == 0) {
          no_of_fives -= 3;
          break;
        }
        no_of_tens--;
        no_of_fives--;
        break;
      }
      if (no_of_fives < 0 || no_of_tens < 0)
        return false;
    }
    return (no_of_fives < 0 || no_of_tens < 0) ? false : true;
  }
};

int main(int argc, char *argv[]) {
  vector<int> test = {5, 5, 10, 20, 5, 5, 5,  5, 5,  5,
                      5, 5, 5,  10, 5, 5, 20, 5, 20, 5};
  cout << Solution().lemonadeChange(test);

  return 0;
}
