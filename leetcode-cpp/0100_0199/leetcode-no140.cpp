#include <iostream>
#include <memory>
#include <vector>


using namespace std;

class TrieNode {
public:
    vector<TrieNode *> child;
    bool isEnd;

    TrieNode() {
        this->child = vector<TrieNode *>(26, nullptr);
        this->isEnd = false;
    }

    void insert(TrieNode *root, const string &word) {
        TrieNode *node = root;
        for (auto c: word) {
            if (node->child[c - 'a'] == nullptr) {
                node->child[c - 'a'] = new TrieNode();
            }
            node = node->child[c - 'a'];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {

    }
};

int main(int argc, char *argv[]) {
    Solution test;
}


//
// Created by ASUS on 2025/2/21.
//
