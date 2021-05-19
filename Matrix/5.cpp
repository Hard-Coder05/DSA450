// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
       vector<int> v;
       int n=Mat.size();
       int m=Mat[0].size();
       for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
           v.push_back(Mat[i][j]);
       sort(v.begin(),v.end());
       int a=0;
       for(int i=0;i<n;i++)
           for(int j=0;j<m;j++){
           Mat[i][j]=v[a];
               a++;
           }
           return Mat;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends