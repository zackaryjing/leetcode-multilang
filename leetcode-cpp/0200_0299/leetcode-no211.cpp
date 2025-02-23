#include <iostream>
#include <vector>

#include "../utils/treegenerator.h"

using namespace std;

class Trie {
    // 字典树，还行
    Trie *children[26] = {nullptr};
    char val;
    bool is_end = false;

public:
    Trie() {
    }

    Trie(const string &s, int index): val(s[index]) {
    };

    void insert(const string &s, const int index) {
        if (index <= s.size() - 1) {
            int pos = s[index] - 'a';
            if (children[pos] != nullptr) {
                children[pos]->insert(s, index + 1);
            } else {
                children[pos] = new Trie(s, index);
                children[pos]->insert(s, index + 1);
            }
        } else {
            this->is_end = true;
        }
    }

    bool search(const string &s, const int index) {
        bool ans = false;
        if (index <= s.size() - 1) {
            if (s[index] == '.') {
                for (auto child: children) {
                    if (child != nullptr) {
                        bool temp = child->search(s, index + 1);
                        if (temp) {
                            return true;
                        }
                    }
                }
            } else {
                if (children[s[index] - 'a'] != nullptr) {
                    return children[s[index] - 'a']->search(s, index + 1);
                } else {
                    return false;
                }
            }
        } else {
            return is_end;
        }
        return ans;
    }
};

class WordDictionary {
public:
    Trie data;

    WordDictionary() {
    }

    void addWord(string word) {
        data.insert(word, 0);
    }

    bool search(string word) {
        return data.search(word, 0);
    }
};


int main(int argc, char *argv[]) {
    WordDictionary test;
    test.addWord("bad");
    test.addWord("dad");
    test.addWord("mad");
    cout << test.search("pad") << endl;;
    cout << test.search("bad") << endl;;
    cout << test.search(".ad") << " <--" << endl;;
    cout << test.search("b..") << endl;;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


//
// Created by ASUS on 2025/2/18.
//
