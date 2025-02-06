#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        vector<string> table = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
            ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
        };
        set<string> translations;
        for (auto word : words) {
            string translation;
            for (auto ch : word) {
                translation += table[ch - 'a'];
            }
            translations.insert(translation);
        }
        return translations.size();
    }
};

int main() {
    Solution test;
    cout << test.uniqueMorseRepresentations(*new vector<string>({"gin", "zen", "gig", "msg"})) << endl;
}

//
// Created by ASUS on 2025/2/6.
//
