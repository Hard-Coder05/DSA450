#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
     sort(arr,arr+N);
     int max_till_here=1;
     int length_curr=1;
     for(int i=1;i<N;i++){
         
         if((arr[i]-arr[i-1])==0)
         {
             continue;
         }
         else if((arr[i]-arr[i-1])==1)
         {
             length_curr++;
             max_till_here=max(max_till_here,length_curr);
         }
         else{
             length_curr=1;
         }
     }
     return max_till_here;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends