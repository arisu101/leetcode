#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummynode = new ListNode(0);
    ListNode *tail = dummynode;
    int digit1 = 0, digit2 = 0;
    int carry = 0;
    int sum = 0;
    int digit;
    while (l1 != NULL || l2 != NULL || carry != 0) {
      digit1 = (l1 != nullptr) ? l1->val : 0;
      digit2 = (l2 != nullptr) ? l2->val : 0;
      sum = carry + digit1 + digit2;
      digit = sum % 10;
      carry = (int)sum / 10;

      ListNode *newNode = new ListNode(digit);
      tail->next = newNode;
      tail = tail->next;

      l1 = (l1 != nullptr) ? l1->next : nullptr;
      l2 = (l2 != nullptr) ? l2->next : nullptr;
    }
    ListNode *result = dummynode->next;
    delete dummynode;
    return result;
  }
};

int main() {
  // ListNode *l1 = new ListNode(
  //     1,
  //     new ListNode(
  //         9, new ListNode(
  //                9, new ListNode(
  //                       9, new ListNode(
  //                              9, new ListNode(
  //                                     9, new ListNode(
  //                                            9, new ListNode(
  //                                                   9, new ListNode(
  //                                                          9, new ListNode(
  //                                                                 9))))))))));
  //
  ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  Solution sol;
  ListNode *node = sol.addTwoNumbers(l1, l2);

  // Output result
  while (node != NULL) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << std::endl;

  // Free allocated memory
  while (l1 != NULL) {
    ListNode *temp = l1;
    l1 = l1->next;
    delete temp;
  }
  while (l2 != NULL) {
    ListNode *temp = l2;
    l2 = l2->next;
    delete temp;
  }
  while (node != NULL) {
    ListNode *temp = node;
    node = node->next;
    delete temp;
  }

  return 0;
}
