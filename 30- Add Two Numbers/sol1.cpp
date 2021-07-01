#include <bits/stdc++.h>
using namespace std;

// Using Simple Solution

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  bool carry = false;
  ListNode *ans = l2;
  int cur = 0;
  while (true)
  {
    cur = l1->val + l2->val;
    cur = carry ? cur + 1 : cur;
    carry = false;
    if (cur > 9)
      carry = true;
    l2->val = cur % 10;

    if (!l1->next && !l2->next)
      break;

    if (!l1->next)
      l1->next = new ListNode(0);
    if (!l2->next)
      l2->next = new ListNode(0);

    l1 = l1->next;
    l2 = l2->next;
  }
  if (carry)
    l2->next = new ListNode(1);
  return ans;
}