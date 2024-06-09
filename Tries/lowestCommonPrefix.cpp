#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertIntoTrieRecursively(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] == NULL)
        {
            root->childCount++;
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        else
        {
            child = root->children[index];
        }

        insertIntoTrieRecursively(child, word.substr(1));
    }
    void insertIntoTrie(string word)
    {
        insertIntoTrieRecursively(root, word);
    }

    void findLongestCommonPrefix(string base_string, string &ans)
    {

        for (char ch : base_string)
        {
            cout << root->childCount << " ";
            cout << ch << " ";
            int index = ch - 'a';
            if (root->children[index] != NULL && root->children[index]->data == ch && root->childCount == 1)
            {
                ans.push_back(ch);
                root = root->children[index];
            }
            else
                break;

            if (root->isTerminal == true)
                break;
        }
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        Trie *trie = new Trie('\0');
        string base_string;
        int minLength = INT_MAX;
        for (string word : strs)
        {

            if (word.length() < minLength)
            {
                base_string = word;
                minLength = word.length();
            }

            trie->insertIntoTrie(word);
        }

        string ans = "";

        trie->findLongestCommonPrefix(base_string, ans);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs);
    return 0;
}