#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val)
    {
        this->data = val;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
class Trie
{
private:
    TrieNode *root;

public:
    Trie() { root = new TrieNode('\0'); }
    void insertRecursively(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode *child;

        int index = word[0] - 'a';
        if (root->children[index] == nullptr)
        {
            root->children[index] = new TrieNode(word[0]);
        }

        child = root->children[index];
        insertRecursively(child, word.substr(1));
    }

    bool searchRecursively(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            if (root->isTerminal == true)
                return true;
            else
                return false;
        }
        TrieNode *child;
        if (root->children[word[0] - 'a'] != NULL)
        {
            child = root->children[word[0] - 'a'];
        }

        else
            return false;

        return searchRecursively(child, word.substr(1));
    }

    bool startsWithRecursively(TrieNode *root, string word)
    {
        if (word.length() <= 0)
        {
            // if(root->isTerminal == true) return true;
            // else return false ;
            return true;
        }
        TrieNode *child;
        for (auto i : root->children)
            cout << i << " ";
        // cout << root->data<< " " << root->children[word[0] - 'a']->data << endl;
        if (root->children[word[0] - 'a'] != NULL)
        {
            child = root->children[word[0] - 'a'];
        }

        else
            return false;

        return startsWithRecursively(child, word.substr(1));
    }

    void insert(string word)
    {
        insertRecursively(root, word);
    }

    bool search(string word)
    {
        return searchRecursively(root, word);
    }

    bool startsWith(string prefix)
    {
        return startsWithRecursively(root, prefix);
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // returns true
    cout << trie->search("app") << endl;     // returns false
    cout << trie->startsWith("app") << endl; // returns true
    trie->insert("app");
    cout << trie->search("app") << endl; // returns true
    return 0;
}