// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct Trie{
        struct Trie* children[26];
        set<string> elements;
    };
    struct Trie* getNode(void){
        struct Trie* node = new Trie();
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }
        return node;
    }
    void insertNode(struct Trie* node, string s){
        struct Trie* curr=node;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(!curr->children[index])
            curr->children[index]=getNode();
            curr=curr->children[index];
            curr->elements.insert(s);
        }
    }
    vector<vector<string>> displayContacts(int n, string arr[], string s)
    {
        struct Trie* curr=new Trie();
        for(int i=0;i<n;i++)
        insertNode(curr,arr[i]);
        
        vector<vector<string>> ans;
        int i=0;
        for(;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->children[index]){
                vector<string> abss;
            for(auto &ele:curr->children[index]->elements)
            abss.push_back(ele);
            ans.push_back(abss); 
            }
            else 
            break;
            curr=curr->children[index];
        }
        for(;i<s.length();i++){ 
            ans.push_back({"0"});
        }
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
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends