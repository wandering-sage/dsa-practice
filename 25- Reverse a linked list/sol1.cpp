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

ListNode *reverseList(ListNode *head)
{
  ListNode *prev = NULL;
  ListNode *fwd = NULL;
  while (head)
  {
    fwd = head->next;
    head->next = prev;
    prev = head;
    head = fwd;
  }
  return prev;
}