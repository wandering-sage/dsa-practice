#include <bits/stdc++.h>
using namespace std;

// Using Slow and Fast Pointers

// time-->O(N)          space-->O(1)

//  Definition for singly-linked list.
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node *copyRandomList(Node *head)
{
  Node *cur = head, *res, *tmp;

  if (head == NULL)
    return NULL;

  while (cur != NULL)
  {
    tmp = new Node(cur->val);
    tmp->next = cur->next;
    cur->next = tmp;
    cur = tmp->next;
  }
  cur = head;
  while (cur != NULL)
  {
    cur->next->random = cur->random == NULL ? NULL : cur->random->next;
    cur = cur->next->next;
  }
  res = head->next;
  cur = head;
  tmp = head->next;

  while (tmp != NULL)
  {
    if (tmp->next == NULL)
    {
      cur->next = NULL;
      break;
    }
    cur->next = tmp->next;
    tmp->next = tmp->next->next;
    cur = cur->next;
    tmp = tmp->next;
  }
  return res;
}
