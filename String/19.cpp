#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    void computeLPSArray(char* pat, int M, int* lps)
{ 
    int len = 0;
  
    lps[0] = 0;   
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else  
        { 
            if (len != 0) {
                len = lps[len - 1]; 
            }
            else  
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
    public: 
    
        vector <int> search(string pat, string txt)
        {
int n = txt.size(), m = pat.size() ;

vector < int > lcs(m + 1, 0) ;

auto kmp = [&](){
int i = 1, j = 0 ;
while(i < m){
if (txt[i] == txt[j]) lcs[i] = ++j ;
else j = 0 ;
++i ;
}
};

kmp() ;

vector < int > ans ;
// for(auto x : lcs) cout << x << " " ;
auto find = [&](){
int i = 0, j = 0 ;

while(i < n){
if (txt[i] == pat[j]){
i++ ;
j++ ;
// cout << j << " " ;
if (j == m){
ans.push_back(i - j + 1) ;
j = lcs[j - 1] ;
}
}
else {
if (!j) i++ ;
else j = lcs[j - 1] ;
}

}
};

find() ;

if (ans.empty()) ans.push_back(-1) ;
return ans ;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends