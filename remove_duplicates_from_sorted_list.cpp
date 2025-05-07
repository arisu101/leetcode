#include <cstdlib>
#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 */
struct node {

  int data;
  node *next;
};
node *head;

void insert(int data, int n) {
  node *temp1 = new node();
  temp1->data = data;
  temp1->next = NULL;

  if (n == 1) {
    temp1->next = head;
    head = temp1;
    return;
  }

  node *temp2 = head;
  for (int i = 0; i < n - 2; i++) {
    if (temp2 == NULL) {
      std::cerr << "Invalid position\n";
      delete temp1;
      return;
    }
    temp2 = temp2->next;
  }

  if (temp2 == NULL) {
    std::cerr << "Invalid position\n";
    delete temp1;
    return;
  }

  temp1->next = temp2->next;
  temp2->next = temp1;
}

class Solution {
public:
  node *deleteDuplicates(node *head) {

    if (head == NULL) {

      return NULL;
    }
    std::cout << head->data << " ";
    deleteDuplicates(head->next);
    std::cout << "\n";
    return head;
  }
};
int main(int argc, char *argv[]) {

  head = NULL;
  insert(2, 1);
  insert(4, 2);
  insert(6, 3);
  Solution test;
  test.deleteDuplicates(head);
  return 0;
}
