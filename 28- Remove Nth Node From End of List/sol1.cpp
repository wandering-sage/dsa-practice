#include <bits/stdc++.h>
using namespace std;

// Using Two Pointers

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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
  ListNode *ptr1 = head, *ptr2;
  ListNode *start = new ListNode(0, head);
  ptr2 = start;
  while (ptr1)
  {
    if (n > 0)
      n--;
    else
      ptr2 = ptr2->next;
    ptr1 = ptr1->next;
  }
  ptr2->next = ptr2->next->next;
  return start->next;
}