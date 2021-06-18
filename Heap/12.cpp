
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution
{
    priority_queue<double> maxHeap;
    priority_queue<double,vector<double>,greater<double>> minHeap;
    int size=0;
    int median;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        size++;
        if(size==1){
        maxHeap.push(x); 
        }
        else{
            if(x<median){
                if(maxHeap.size()>minHeap.size()){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);
                }
                else{
                    maxHeap.push(x);
                }
                
            }
            else{
                if(minHeap.size()>maxHeap.size()){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                }
                else{
                    minHeap.push(x);
                } 
            }
        } 
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size()>minHeap.size())
        return median=maxHeap.top();
        else if(minHeap.size()>maxHeap.size())
        return median=minHeap.top();
        else
        return median=(minHeap.top()+maxHeap.top())/2;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends