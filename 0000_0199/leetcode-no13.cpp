#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <exception>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        map<char,int> dic {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int l = s.length();
        for (int i = 0;i<l;i++){
            try{
                if (dic[s[i]] >= dic[s[i+1]]){
                    total += dic[s[i]];
                } else {
                    total -= dic[s[i]];
                }
            } catch(std::exception) {
                total += dic[s[i]];
            }
        }
        return total;
    }
};

int main() {
    Solution t;
    int a = t.romanToInt("IV");
    printf("%d", a);
}