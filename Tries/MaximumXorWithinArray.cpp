#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* links[2];

    TrieNode(){
        links[0] = NULL;
        links[1] = NULL;
    }
    bool containsKey(int bit){
        return (links[bit] != NULL) ;
    }

    TrieNode* get(int bit){
        return links[bit];
    }

    void put(int bit, TrieNode* node){
        links[bit] = node;
    }

};

class Trie{
private :
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insertIntoTrie(int num){
        TrieNode* node = root;
        for(int i = 31; i>=0 ; i--){
            int bit = (num >> i) & 1;

            if(!node->containsKey(bit)){
                node->put(bit, new TrieNode());
            }

            node = node->get(bit);
        }
    }

    int getMaxXor(int num){
        TrieNode* node = root;
        int maxNum = 0;

        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }

        }

        return maxNum;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();

        for(auto &num : nums){
            trie->insertIntoTrie(num);
        }

        int maxi = 0;
        for(auto &num : nums){
            maxi = max(maxi, trie->getMaxXor(num));
        }

        return maxi;
    }
};



int main(){
    Solution s;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << s.findMaximumXOR(nums) << endl;
    return 0;
}