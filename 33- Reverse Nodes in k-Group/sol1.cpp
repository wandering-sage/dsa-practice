#include <bits/stdc++.h>
using namespace std;

// Using ...

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

ListNode *reverseKGroup(ListNode *head, int k)
{
  ListNode *dummy = new ListNode();
  ListNode *start = dummy, *last, *temp;
  int i = 0;
  dummy->next = head;
  while (head)
  {
    i++;
    if (i % k == 0)
    {
      last = head->next;
      head->next = NULL;
      temp = start->next;
      start->next = reverseList(start->next);
      temp->next = last;
      start = temp;
      head = start;
    }
    head = head->next;
  }
  return dummy->next;
}