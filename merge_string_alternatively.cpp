
#include <iostream>
using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int s1 = word1.size();
    int s2 = word2.size();
    string append = "";
    if (s1 == s2) {
      for (int i = 0; i < s1; i++) {
        append += word1[i];
        append += word2[i];
      }
    }
    if (s1 < s2) {
      for (int i = 0; i < s1; i++) {
        append += word1[i];
        append += word2[i];
      }
      append += word2.substr(s1);
    }

    if (s2 < s1) {
      for (int i = 0; i < s2; i++) {
        append += word1[i];
        append += word2[i];
      }
      append += word1.substr(s2);
    }

    return append;
  }
};

int main(int argc, char *argv[]) {

  string test1 = "abc";
  string test2 = "pqr";
  string test3 = "ab";
  string test4 = "pqrs";
  string test5 = "abcd";
  string test6 = "pq";
  Solution testa;

  cout << testa.mergeAlternately(test1, test2);
  cout << "\n";
  cout << testa.mergeAlternately(test3, test4);
  cout << "\n";
  cout << testa.mergeAlternately(test5, test6);
  cout << "\n";

  return 0;
}
