#include <iostream>

class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    int s1 = s.size();
    int s2 = t.size();
    int count = 0;
    int i = 0, j = 0;
    while (i < s1 && j < s2) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return i == s1;
  };
};

int main(int argc, char *argv[]) {

  std::string s = "abs";
  std::string s1 = "agbfas";
  std::string s2 = "ggaarrai";
  std::string s3 = "gab";
  std::cout << Solution().isSubsequence(s, s1);
  std::cout << Solution().isSubsequence(s2, s3);
  return 0;
}
