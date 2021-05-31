// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int i,int n,int arr[],int currsum,int total){
        if(currsum>total)
        return false;
        
        if(currsum==total) 
        return true; 
        
        for(;i<n;i++){
            currsum+=arr[i];
            if(solve(i+1,n,arr,currsum,total))
            return true;
            currsum-=arr[i];
        }
        return false;
    }
    int equalPartition(int n, int arr[])
    {
        int total=0;
        for(int i=0;i<n;i++)
            total+=arr[i]; 
        if(total&1)
        return 0;
        int currsum=0;
        total/=2; 
        if(solve(0,n,arr,currsum,total))
        return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends