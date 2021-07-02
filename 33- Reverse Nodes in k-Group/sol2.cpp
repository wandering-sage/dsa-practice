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

ListNode *reverseKGroup(ListNode *head, int k)
{
  if (head == NULL || k == 1)
    return head;
  ListNode *dummy = new ListNode();
  ListNode *cur, *nex, *pre;
  int i, n;
  n = getSize(head);
  dummy->next = head;
  cur = dummy;
  for (int j = 0; j < n / k; j++)
  {
    pre = cur;
    cur = pre->next;
    nex = cur->next;
    i = 1;
    while (i < k)
    {
      i++;
      cur->next = nex->next;
      nex->next = pre->next;
      pre->next = nex;
      nex = cur->next;
    }
  }
  return dummy->next;
}