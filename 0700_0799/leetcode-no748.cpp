#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, unsigned char> formal;
public:
    unordered_map<char, unsigned char> getCount(string word) {
        for (auto letter: licensePlate) {
            if ('a' <= letter and letter <= 'z') {
                formal[letter] += 1;
            } else if ('A' <= letter and letter <= 'Z') {
                formal[letter - 32] += 1;
            }
        }
    }

    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        for (auto letter: licensePlate) {
            if ('a' <= letter and letter <= 'z') {
                formal[letter] += 1;
            } else if ('A' <= letter and letter <= 'Z') {
                formal[letter - 32] += 1;
            }
        }
        for (auto word: words) {
            unordered_map<char, unsigned char> temp;
            for (auto letter: word) {

            }
        }
    }
};

int main() {

}
//
// Created by ASUS on 2024/7/17.
//
