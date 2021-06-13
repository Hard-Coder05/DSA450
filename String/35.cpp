#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s)
{
    int l = s.length();
    int j;

    for (int i = 0, j = l - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

// Driver code
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    int flag = 0;

    while (s.length() > 0)
    {
        if (ispalindrome(s))
        {
            flag = 1;
            break;
        }
        else
        {
            cnt++;

            s.erase(s.begin() + s.length() - 1);
        }
    }

    if (flag)
        cout << cnt;
}
