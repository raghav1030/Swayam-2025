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

    void getAssociatedSubstrings(TrieNode* curr, vector<string> &temp, string prefix ){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch='a'; ch <= 'z'; ch++){
            TrieNode* child = curr->children[ch - 'a'];
            if(child != NULL){
                prefix.push_back(child->data);
                getAssociatedSubstrings(child, temp, prefix);
                            prefix.pop_back();

            }
        }
    }


    vector<vector<string>> getSuggestions(string &queryStr){
        TrieNode* prev = root;
        string prefix;
        vector<vector<string>> output;

        for(char ch : queryStr){
            prefix.push_back(ch);

            TrieNode* curr = prev->children[ch - 'a'];
            if(curr == NULL){
                break;
            }

            vector<string> temp;

            getAssociatedSubstrings(curr, temp, prefix );
            output.push_back(temp);

            temp.clear();
            prev = curr;
        }        

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie *trie = new Trie('\0');

    for(string contact : contactList){
        trie->insertIntoTrie(contact);
    }

  

    return trie->getSuggestions(queryStr);


}


int main()
{
    vector<string> contactList = {"james", "jacob", "jack", "jackson", "jason"};
    string queryStr = "ja";
    vector<vector<string>> result = phoneDirectory(contactList, queryStr);

    for(auto vec : result){
        for(string str : vec){
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}