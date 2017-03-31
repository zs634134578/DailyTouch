#include <iostream>

using namespace std;


struct TrieNode
{
    TrieNode* nodes[26];
    bool isTail; // if there is any word ends with curNode

    TrieNode()
    {
        for (int i = 0; i < 2; i++)
        {
            nodes[i] = NULL;
        }
        isTail = false;
    }
};


class Trie {

private:
    TrieNode* mRoot;

public:
    /** Initialize your data structure here. */
    Trie() {
        mRoot = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        if (word.length() == 0) return ;
        TrieNode* curNode = mRoot;
        for (int i = 0; i < word.length(); ++i)
        {
            int nodeIndex = word[i] - 'a';
            if (curNode->nodes[nodeIndex] == NULL)
            {
                curNode->nodes[nodeIndex] = new TrieNode();
            }
            curNode = curNode->nodes[nodeIndex];
        }
        curNode->isTail = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.length() == 0) return true;
        TrieNode* curNode = mRoot;
        for (int i = 0; i < word.length(); ++i)
        {
            int nodeIndex = word[i] - 'a';
            if (curNode->nodes[nodeIndex] == NULL)
            {
                return false;
            }
            curNode = curNode->nodes[nodeIndex];
        }
        return curNode->isTail ? true : false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.length() == 0) return true;
        TrieNode* curNode = mRoot;
        for (int i = 0; i < prefix.length(); ++i)
        {
            int nodeIndex = prefix[i] - 'a';
            if (curNode->nodes[nodeIndex] == NULL)
            {
                return false;
            }
            curNode = curNode->nodes[nodeIndex];
        }
        return true;
    }
};



/**
 *
 * Your Trie object will be instantiated and called as such:
 *
 * Trie obj = new Trie();
 *
 * obj.insert(word);
 *
 * bool param_2 = obj.search(word);
 *
 * bool param_3 = obj.startsWith(prefix);
 *
 */ 

int main()
{
    Trie* trieTree = new Trie();
    trieTree->insert("helloworld");
    std::cout << trieTree->search("helloworld") << std::endl;
    std::cout << trieTree->startsWith("hello") << std::endl;
    std::cout << trieTree->startsWith("world") << std::endl;
    return 0;
}
