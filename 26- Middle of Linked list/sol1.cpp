#include <bits/stdc++.h>
using namespace std;

// Using Brute Force

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

int getSize(ListNode *head)
{
  if (!head)
    return 0;
  int len = 1;
  while (head->next)
  {
    len++;
    head = head->next;
  }
  return len;
}

ListNode *middleNode(ListNode *head)
{
  int s = getSize(head);
  for (int i = 0; i < s / 2; i++)
  {
    head = head->next;
  }
  return head;
}