//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next, *prev;

    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
struct node *update(struct node *start, int p);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        struct node *start = NULL;
        struct node *cur = NULL;
        struct node *ptr = NULL;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            ptr = new node(a);
            ptr->data = a;
            ptr->next = NULL;
            ptr->prev = NULL;
            if (start == NULL)
            {
                start = ptr;
                cur = ptr;
            }
            else
            {
                cur->next = ptr;
                ptr->prev = cur;
                cur = ptr;
            }
        }
        struct node *str = update(start, p);
        while (str != NULL)
        {
            cout << str->data << " ";
            str = str->next;
        }
        cout << endl;
    }
}

// } Driver Code Ends
//User function Template for C++

/*
struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

struct node *update(struct node *start, int p)
{
    if (start == NULL || start->next == NULL)
        return start;

    struct node *last = start;
    while (last->next != NULL)
        last = last->next;

    while (p--)
    {
        struct node *head = start->next;
        start->next = NULL;
        head->prev = NULL;
        last->next = start;
        start->prev = last;
        last = last->next;
        start = head;
    }
    return start;
}

// { Driver Code Starts.
// } Driver Code Ends