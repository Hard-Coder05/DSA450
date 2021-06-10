// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int A[], int n)
    {
        int j=0,sum=0,ans=0,k=0;
        map<int,int> mp;
        while(j<n){
            sum+=A[j];
            
            if(sum==k)
            ans=max(ans,j+1);
            
            if(mp.find(sum)==mp.end())
            mp[sum]=j;
            
            if(mp.find(sum-k)!=mp.end())
            ans=max(ans,j-mp[sum-k]);
            
            j++;
        } 
        if(ans>0)
        return true;
        return false;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends