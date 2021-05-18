#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
           map<int,int> mp;
            for(int i=0;i<n1;i++)
            if(mp[A[i]]==0)
            mp[A[i]]++;
            for(int i=0;i<n2;i++)
            if(mp[B[i]]==1)
            mp[B[i]]++;
            for(int i=0;i<n3;i++)
            if(mp[C[i]]==2)
            mp[C[i]]++;
            vector<int> ans;
            for(auto &i:mp)
            if(i.second==3)
            ans.push_back(i.first);
            return ans;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends