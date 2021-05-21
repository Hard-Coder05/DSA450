// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int n;
    vector<vector<int>> ans;
    void search(int i, int n, int diag1[], int diag2[], int col[]){
        if(i==n){
            vector<int> curr;
            for(int a=0;a<n;a++){
                curr.push_back(col[a]);
            }
            ans.push_back(curr);
            return;
        }
        for(int j=0;j<n;j++){
            if(diag1[j-i+n-1]||diag2[i+j]||col[j]) continue;
            diag1[j-i+n-1]=diag2[i+j]=col[j]=(i+1);
            search(i+1,n,diag1,diag2,col);
            diag1[j-i+n-1]=diag2[i+j]=col[j]=0;
        }
    }
    vector<vector<int>> nQueen(int n) {
        int diag1[(2*n)-1];
        int diag2[(2*n)-1];
        int col[n]; 
        memset(diag1,0,sizeof(diag1));
        memset(diag2,0,sizeof(diag2));
        memset(col,0,sizeof(col));
        search(0,n,diag1,diag2,col);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends