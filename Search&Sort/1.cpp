#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
     int start=0,end=n-1,low=-1;
     
     while(start<=end){
         int mid=start + (end-start)/2;
         if(arr[mid]==x)
         low=mid;
         
         if(arr[mid]>=x)
         end=mid-1;
         else
         start=mid+1;
     }
     
     if(low==n)
     return  {-1,-1} ;
     
     start=0,end=n-1;
     int high=-1;
     while(start<=end){
         int mid=start + (end-start)/2;
         if(arr[mid]==x)
         high=mid;
         
         if(arr[mid]>x)
         end=mid-1;
         else
         start=mid+1;
     }
     
     return  {low,high} ;
}