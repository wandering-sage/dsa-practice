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

ListNode *middleNode(ListNode *head)
{
  ListNode *fast = head;
  while (fast->next)
  {
    if (!fast->next->next)
      return head;
    head = head->next;
    fast = fast->next->next;
  }
  return head;
}

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

bool isPalindrome(ListNode *head)
{
  if (head->next == NULL)
    return true;
  ListNode *ptr, *mid;
  mid = middleNode(head);
  mid->next = reverseList(mid->next);
  ptr = mid->next;
  while (ptr)
  {
    if (head->val != ptr->val)
    {
      return false;
    }
    ptr = ptr->next;
    head = head->next;
  }
  return true;
}
