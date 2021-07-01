#include <bits/stdc++.h>
using namespace std;

// Using Inplace sort

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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
  ListNode *newH, *cur;
  if (!l1)
    return l2;
  if (!l2)
    return l1;
  if (l1->val <= l2->val)
  {
    newH = l1;
    l1 = l1->next;
  }
  else
  {
    newH = l2;
    l2 = l2->next;
  }
  cur = newH;
  while (l1 && l2)
  {
    if (l1->val <= l2->val)
    {
      cur->next = l1;
      l1 = l1->next;
    }
    else
    {
      cur->next = l2;
      l2 = l2->next;
    }
    cur = cur->next;
  }
  if (l1)
    cur->next = l1;
  if (l2)
    cur->next = l2;
  return newH;
}