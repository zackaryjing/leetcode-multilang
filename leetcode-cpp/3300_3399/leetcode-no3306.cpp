// problem: count-of-substrings-containing-every-vowel-and-k-consonants-ii
#include <unordered_set>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        auto count = [&](int m) -> long long {
            int n = word.size(), consonants = 0;
            long long res = 0;
            unordered_map<char, int> occur;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && (consonants < m || occur.size() < vowels.size())) {
                    if (vowels.count(word[j])) {
                        occur[word[j]]++;
                    } else {
                        consonants++;
                    }
                    j++;
                }
                if (consonants >= m && occur.size() == vowels.size()) {
                    res += n - j + 1;
                }
                if (vowels.count(word[i])) {
                    occur[word[i]]--;
                    if (occur[word[i]] == 0) {
                        occur.erase(word[i]);
                    }
                } else {
                    consonants--;
                }
            }
            return res;
        };
        return count(k) - count(k + 1);
    }
};


class Solution2 {
public:
    long long countOfSubstrings(string word, int k) {
        const int n = static_cast<int>(word.size());
        vector<int> last = vector(n, 0);
        vector<int> cur = vector(n, 0);

        int pos[26] = {0};
        pos['a' - 'a'] = 1;
        pos['e' - 'a'] = 2;
        pos['i' - 'a'] = 4;
        pos['o' - 'a'] = 8;
        pos['u' - 'a'] = 16;
        for (int i = 0; i < n; i++) {
            auto c = pos[word[i] - 'a'];
            if (c) {
                last[i] = c;
            } else {
                last[i] = 32;
            }
        }
        std::vector<int> vec(n - 1);
        std::iota(vec.begin(), vec.end(), 0);
        unordered_set tovis(vec.begin(), vec.end());
        int ans = 0;
        for (int i = 1; i < n; i++) {
            vector<int> to_erase;
            // j < n - i
            for (auto j: tovis) {
                const auto temp = pos[word[j + i] - 'a'];
                int val;
                if (temp) {
                    val = last[j] | temp;
                } else {
                    val = last[j] + 32;
                }
                cur[j] = val;
                if (val % 32 == 31) {
                    if (val >> 5 == k) {
                        ans++;
                    } else if (val >> 5 > k) {
                        to_erase.push_back(j);
                    }
                }
            }
            for (auto k: to_erase) {
                tovis.erase(k);
            }
            tovis.erase(n - i - 1);
            swap(last, cur);
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countOfSubstrings("aeioqq", 1) << endl;;
    cout << test.countOfSubstrings("aeiou", 0) << endl;;
    cout << test.countOfSubstrings("ieaouqqieaouqq", 1) << endl;;
}


//
// Created by ASUS on 2025/3/13.
//
