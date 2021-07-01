#include <bits/stdc++.h>
using namespace std;

// Using Inplace sort Optimized

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
  ListNode *res, *tmp;
  if (!l1)
    return l2;
  if (!l2)
    return l1;
  if (l1->val > l2->val)
    swap(l1, l2);
  res = l1;
  while (l1 && l2)
  {
    while (l1 && l2->val >= l1->val)
    {
      tmp = l1;
      l1 = l1->next;
    }
    tmp->next = l2;
    swap(l1, l2);
  }
  return res;
}