//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    int solve(Node *head)
    {
        int a;
        if (head->next != NULL)
            a = head->data + solve(head->next);
        else
            a = 1 + head->data;

        if (a == 10)
        {
            head->data = 0;
            return 1;
        }
        head->data = a;
        return 0;
    }

public:
    Node *addOne(Node *head)
    {
        int c = solve(head);
        if (c == 1)
        {
            Node *curr = new Node(1);
            curr->next = head;
            head = curr;
        }
        return head;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends