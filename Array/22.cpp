// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        if(N==0||N==1)
        return {1};
        
        vector<int> ans;
        int n=N;
        while(N>0){
        ans.push_back(N%10);
        N/=10;
        }
        
        
        for(int i=n-1;i>1;i--){
            int carry=0;
            for(int j=0;j<ans.size();j++){
                int curr=(ans[j]*i)+carry;
                ans[j]=curr%10;
                carry=curr/10;
            }
            while(carry>0){
                ans.push_back(carry%10);
                carry/=10;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends