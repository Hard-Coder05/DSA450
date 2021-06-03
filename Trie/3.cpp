
#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        cout << wordBreak(line, dict) << "\n";
    }
}
// } Driver Code Ends

struct Trie
{
    struct Trie *children[26];
    int isLeaf;
};
struct Trie *getNode(void)
{
    struct Trie *node = new Trie();
    for (int i = 0; i < 26; i++)
    {
        node->children[i] = NULL;
    }
    node->isLeaf = 0;
    return node;
}
void insertNode(struct Trie *node, string s)
{
    struct Trie *curr = node;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = getNode();
        curr = curr->children[index];
    }
    curr->isLeaf = 1;
}
bool search(string s, struct Trie *node)
{
    struct Trie *curr = node;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!curr->children[index])
            return false;
        curr = curr->children[index];
    }
    if (curr->isLeaf)
        return true;
    return false;
}
int breakWord(string s, struct Trie *node)
{

    int n = s.length();
    if (n == 0)
        return 1;

    for (int i = 1; i <= n; i++)
    {
        if (search(s.substr(0, i), node) && breakWord(s.substr(i, n - i), node))
            return 1;
    }

    return 0;
}
int wordBreak(string A, vector<string> &B)
{
    struct Trie *node = new Trie();
    for (int i = 0; i < B.size(); i++)
        insertNode(node, B[i]);

    return breakWord(A, node);
}