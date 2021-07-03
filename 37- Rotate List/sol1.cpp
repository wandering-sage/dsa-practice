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

ListNode *rotateRight(ListNode *head, int k)
{
  if (!head || !head->next)
    return head;
  ListNode *cur = head;
  int len = 1;
  while (cur->next)
  {
    len++;
    cur = cur->next;
  }
  k = k % len;
  if (k == 0)
    return head;
  cur->next = head;
  k = len - k;
  while (k--)
  {
    cur = cur->next;
  }
  head = cur->next;
  cur->next = NULL;
  return head;
}
