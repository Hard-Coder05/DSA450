#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long low,long long mid,long long high){
        
        
        long long n1=mid-low+1;
        long long n2=high-mid;
        long long arr1[n1],arr2[n2];
        
        for(long long int i=0;i<n1;i++)
        arr1[i]=arr[low+i];
        
        for(long long int i=0;i<n2;i++)
        arr2[i]=arr[mid+i+1]; 
        
        long long int i=0,j=0,k=low,count=0;
         
        
        while(i<n1&&j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k++]=arr1[i++]; 
        }
        else{
            count+=(n1-i);
            arr[k++]=arr2[j++];
        } 
        }
        
        while(i<n1)
            arr[k++]=arr1[i++]; 
        
        while(j<n2)
            arr[k++]=arr2[j++];  
            
        return count;
    }
    long long mergeSort(long long arr[], long long low, long long high)
    {
        long long res = 0;
        if(low < high)
        {   long long mid = low + (high - low)/2;
           
            res += mergeSort(arr, low, mid);
            res += mergeSort(arr, mid + 1, high);
            
            res += merge(arr, low, mid, high);
        } 
        return res;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(arr,0,n-1);
    }
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends