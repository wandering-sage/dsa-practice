#include <bits/stdc++.h>
using namespace std;

// Using Slow and Fast Ptr

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

ListNode *middleNode(ListNode *head)
{
  ListNode *fast = head;
  while (fast->next)
  {
    head = head->next;
    if (!fast->next->next)
      return head;
    fast = fast->next->next;
  }
  return head;
}