#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int romanToInt(std::string s) {
    std::unordered_map<std::string, int> romans = {
        {"I", 1},   {"V", 5},   {"X", 10},  {"L", 50},
        {"C", 100}, {"D", 500}, {"M", 1000}};
    int sum = 0;
    int n = s.size();
    int i = 0;
    while (i < n) {
      std::string current(1, s[i]);
      std::string next = (i < n - 1) ? std::string(1, s[i + 1]) : "";

      if (i < n - 1 && romans[current] < romans[next]) {
        sum += romans[next] - romans[current];
        i += 2;
      } else {
        sum += romans[current];
        i++;
      }
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {

  Solution test;
  std::string roman;
  std::cin >> roman;
  std::cout << test.romanToInt(roman);

  return 0;
}
