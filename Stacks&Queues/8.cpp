#include <iostream>
#include <stack>
using namespace std;
void push(stack<int> &s, int a);
bool isFull(stack<int> &s, int n);
bool isEmpty(stack<int> &s);
int pop(stack<int> &s);
int getMin(stack<int> &s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        while (!isEmpty(s))
        {
            pop(s);
        }
        while (!isFull(s, n))
        {
            cin >> a;
            push(s, a);
        }
        cout << getMin(s) << endl;
    }
} // } Driver Code Ends

int minEle;
void push(stack<int> &s, int a)
{
    if (s.empty())
        minEle = a;

    if (s.empty() || a >= minEle)
    {
        s.push(a);
    }
    else
    {
        s.push(2 * a - minEle);
        minEle = a;
    }
    return;
}

bool isFull(stack<int> &s, int n)
{
    return (s.size() == n);
}

bool isEmpty(stack<int> &s)
{
    return (s.size() == 0);
}

int pop(stack<int> &s)
{
    if (s.empty())
        return -1;

    int x = s.top();
    s.pop();

    if (x < minEle)
    {
        int a = minEle;
        minEle = 2 * a - x;
        return a;
    }
    return x;
}

int getMin(stack<int> &s)
{
    if (s.empty())
        return -1;
    return minEle;
}