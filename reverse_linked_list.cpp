
#include <iostream>
struct ListNode {
  int data;
  ListNode *next;
};
ListNode *head = NULL;

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
};
