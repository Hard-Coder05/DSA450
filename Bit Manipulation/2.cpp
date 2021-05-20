#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n-1;){
            if((nums[i]^nums[i+1])==0)
            i+=2;
            else{
                ans.push_back(nums[i]);
                i++;
            }
            if(ans.size()==2)
            return ans;
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends