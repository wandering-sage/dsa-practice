#include <bits/stdc++.h>
using namespace std;

// Using Optimized approch

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

  // states l2 is smaller than l1
  bool flag = false;

  int n = 0;

  ListNode *ptr1 = headA, *ptr2 = headB;
  while (ptr1->next || ptr2->next)
  {
    if (!ptr1->next || !ptr2->next)
      n++;
    if (!ptr2->next && ptr1->next)
    {
      flag = true;
    }
    if (ptr1->next)
      ptr1 = ptr1->next;
    if (ptr2->next)
      ptr2 = ptr2->next;
  }
  if (ptr1 != ptr2)
  {
    return NULL;
  }
  ptr1 = headA;
  ptr2 = headB;
  if (flag)
    swap(ptr1, ptr2);
  while (ptr1 != ptr2 && ptr1 && ptr2)
  {
    if (n <= 0)
    {
      ptr1 = ptr1->next;
    }
    ptr2 = ptr2->next;
    n--;
  }
  return ptr1;
}