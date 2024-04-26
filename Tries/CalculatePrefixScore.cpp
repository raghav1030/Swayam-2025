#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    int prefixCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        childCount = 0;
        prefixCount = 0;
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
            ++root->childCount;
            child = new TrieNode(word[0]);
            root->children[index] = child;

        }

        else
        {
            child = root->children[index];
        }
            ++child->prefixCount;


// cout << child->data << " " << child->prefixCount <<endl;


        insertIntoTrieRecursively(child, word.substr(1));

    }
    void insertIntoTrie(string word)
    {
        insertIntoTrieRecursively(root, word);
    }

    int getScore(string &word){
        TrieNode* curr = root;
        int score = 0;
        for(char ch : word){
            int index = ch - 'a';

            if(curr->children[index] != NULL){
                curr = curr->children[index];
                score += curr->prefixCount;
            }
            else break;
        }

        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie('\0');

        for(string word : words){
            trie->insertIntoTrie(word);
        }
        vector<int> ans;
        for(string word : words){
            ans.push_back(trie->getScore(word));
        }

        return ans;
    }
};



int main(){
    Solution s;
    vector<string> words = {"abc", "def", "ghi", "jkl"};
    vector<int> ans = s.sumPrefixScores(words);
    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}