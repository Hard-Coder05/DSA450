#include<bits/stdc++.h>
using namespace std;

int longestPalinSubseq (string A);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << longestPalinSubseq (s) << endl;
    }
} 
// } Driver Code Ends


//User function Template for C++

int longestPalinSubseq (string s1)
{
    string s2=s1;
    reverse(s2.begin(),s2.end());
    int x=s1.length();
    int y=x;
    
     int dp[x+1][y+1];
        
        for(int i=0;i<=x;i++){
            dp[i][0]=0;
        }
        
        for(int i=0;i<=y;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[x][y];
}