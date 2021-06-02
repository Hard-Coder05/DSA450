#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s1){
		    int x=s1.length();
		    
		   int dp[x+1][x+1];
        
        for(int i=0;i<=x;i++){
            dp[i][0]=0;
        }
        
        for(int i=0;i<=x;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=x;j++){
                if(i!=j&&s1[i-1]==s1[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[x][x];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends