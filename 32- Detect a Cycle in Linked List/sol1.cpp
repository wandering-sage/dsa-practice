#include <bits/stdc++.h>
using namespace std;

// Using Slow and Fast Pointers

// time-->O(N)          space-->O(1)

//  Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head)
{
  ListNode *slow = head, *fast = head;
  while (true)
  {
    if (fast == NULL || fast->next == NULL)
      return false;
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return true;
}
