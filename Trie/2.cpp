//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    struct Trie{
        struct Trie* children[26];
        int isUnique;
    };
    struct Trie* getNode(void){
        struct Trie* node = new Trie();
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }
        node->isUnique=1;
        return node;
    }
    void insertNode(struct Trie* node, string s){
        struct Trie* curr=node;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(!curr->children[index])
            curr->children[index]=getNode();
            else
            curr->children[index]->isUnique=0;
            curr=curr->children[index];
        }
    }
    string unique(string s,struct Trie* node){
        struct Trie* curr=node; 
        string ans="";
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            ans+=s[i];
            if(curr->children[index]->isUnique){
            return ans;
            }
            else 
            curr=curr->children[index];
        }
        return ans;
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        struct Trie* node=new Trie();
        for(int i=0;i<n;i++)
        insertNode(node,arr[i]);
        
        vector<string> ans;
        for(int i=0;i<n;i++){
            ans.push_back(unique(arr[i],node));
        }
        
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends