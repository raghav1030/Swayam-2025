#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* children[26];
    char data;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }

    bool containsKey(int index){
        return children[index] != NULL;
    }

    TrieNode* get(int index){
        return children[index];
    }

    void put(int index, TrieNode* newNode){
        children[index] = newNode;
    }
};

class Trie{
private :
    TrieNode* root;

public:
    Trie(char ch){
        root = new TrieNode(ch);
    }

    void insertIntoTrieRecursively(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        if(!root->containsKey(index)){
            root->put(index, new TrieNode(word[0]));
        }

        TrieNode* child = root->get(index);
        insertIntoTrieRecursively(child, word.substr(1));

        
    }

    void insertIntoTrie(string word){
        insertIntoTrieRecursively(root, word);
    }

    string compareStringWithTrie(TrieNode* root, string word, string str){
        
        for(auto ch : word){
            if(!root->containsKey(ch - 'a')) return word;

            str += ch;

            root = root->get(ch - 'a');

            if(root->isTerminal == true) return str;
            
        }

        return word;
    }


    void analyzeString(vector<string> &vectorString){
        string str = "";
        TrieNode* curr = root;
        for(int i = 0; i < vectorString.size(); i++){
            string newString = compareStringWithTrie(curr, vectorString[i], str);
            vectorString[i] = newString;
        }
    }

    
 
};

class Solution {
public:
    vector<string> convertStringIntoVector(string str){
    vector<string> ans; 
    stringstream ss(str);  
    string temp; 
 
    while(getline(ss, temp, ' ')) { 
        ans.push_back(temp); 
    } 

    
  return ans; 
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> newVectorString = convertStringIntoVector(sentence);

        Trie* trie = new Trie('\0');

        for(auto word : dictionary){
            trie->insertIntoTrie(word);
        } 

        trie->analyzeString(newVectorString);

        string result;
        for (size_t i = 0; i < newVectorString.size(); ++i) {
            if (i != 0) {
                result += " "; // Add a space between words.
            }
            result += newVectorString[i];
        }

        return result; // Return the joined string.
        
    }
};


int main(){
    Solution sol;
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    cout<<sol.replaceWords(dictionary, sentence);
    return 0;
}