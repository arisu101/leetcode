
/*
 * given two head nodes
 * join the last node of list1 to first node of list2
 */
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *temp = new ListNode();
    while (temp->next != NULL) {
      temp = list1->next;
      list1 = list1->next;
    }
    temp->next = list2;
  }

  void Print(ListNode *test) {
    ListNode *temp = test;
    while (temp != NULL) {
      std::cout << temp->val << ',';
      temp = temp->next;
    }
    std::cout << '\n';
  }
};

int main(int argc, char *argv[]) { return 0; }
