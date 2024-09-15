/*
      TRIE for String DP
*/
class TrieNode {
public:
    vector<TrieNode*> children;
    TrieNode() : children(26, nullptr) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() 
    {
        root = new TrieNode();
    }
    void insertWord(string& word) 
    {
        TrieNode* node = root;
        for(char c:word) 
        {
            int pos=c-'a';
            if (node->children[pos]==nullptr)
                node->children[pos]=new TrieNode();
            node=node->children[pos];
        }
    }
    
    void updateDP(string& target,int start,vector<int>&dp) 
    {
        TrieNode* node=root;
        for (int i=start;i<target.size();++i) 
        {
            int pos=target[i]-'a';
            if(node->children[pos]==nullptr)
                return;
            node=node->children[pos];
            if (dp[start]!=INT_MAX)
                dp[i+1]=min(dp[i+1],dp[start]+1);
        }
    }
};
