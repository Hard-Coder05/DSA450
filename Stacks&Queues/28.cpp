//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
} // } Driver Code Ends

//User function Template for C++

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    int n = q.size();
    stack<int> inter;
    while (k--)
    {
        inter.push(q.front());
        q.pop();
    }
    queue<int> rest;
    while (!q.empty())
    {
        rest.push(q.front());
        q.pop();
    }

    while (!inter.empty())
    {
        q.push(inter.top());
        inter.pop();
    }
    while (!rest.empty())
    {
        q.push(rest.front());
        rest.pop();
    }
    return q;
}