#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    int i=0,n=s.length(),ans=0;stack<char> para;
    while(i<n){
        char curr=s[i];
        if(s[i]=='{'){
            para.push(curr);
        }
        else{
            if(para.empty()){
                ans++;
                para.push('{');
            }
            else
            {
                para.pop();
            }
        }
        i++;
    }
    if(para.empty())
    return ans;
    else{
        if(para.size()%2==0){
            ans+=para.size()/2;
        }
        else
        return -1;
    }
    return ans;
}