#include <bits/stdc++.h>
using namespace std;

// Using Inplace sort Optimized

// time-->O(N)          space-->O(1)

//  Definition for singly-linked list.
struct Node
{
  int data;
  struct Node *next;
  struct Node *bottom;

  Node(int x)
  {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
  bool flag = false;
  if (root->next == NULL)
    return root;
  Node *l1, *l2, *newRoot, *tmp;
  l1 = root;
  l2 = root->next;
  newRoot = root->next;
  if (l1->data > l2->data)
  {
    swap(l1, l2);
    flag = true;
  }

  while (l1 && l2)
  {
    while (l1 && l2->data >= l1->data)
    {
      tmp = l1;
      l1 = l1->bottom;
    }
    tmp->bottom = l2;
    swap(l1, l2);
  }
  root->next = root->next->next;
  if (flag)
  {
    return flatten(newRoot);
  }
  return flatten(root);
}