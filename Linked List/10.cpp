// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
#include <bits/stdc++.h>
class Solution
{
public:
    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        stack<int> s1;
        while (first != NULL)
        {
            s1.push(first->data);
            first = first->next;
        }
        stack<int> s2;
        while (second != NULL)
        {
            s2.push(second->data);
            second = second->next;
        }
        struct Node *previous = NULL;
        int carry = 0;
        while (!s1.empty() && !s2.empty())
        {
            int a = (s1.top() + s2.top() + carry);
            s1.pop();
            s2.pop();
            struct Node *current = new Node(a % 10);
            carry = a / 10;
            current->next = previous;
            previous = current;
        }
        while (!s1.empty())
        {
            int a = (s1.top() + carry);
            s1.pop();
            struct Node *current = new Node(a % 10);
            carry = a / 10;
            current->next = previous;
            previous = current;
        }
        while (!s2.empty())
        {
            int a = (s2.top() + carry);
            s1.pop();
            s2.pop();
            struct Node *current = new Node(a % 10);
            carry = a / 10;
            current->next = previous;
            previous = current;
        }
        if (carry != 0)
        {
            struct Node *current = new Node(carry);
            current->next = previous;
            previous = current;
        }
        return previous;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends