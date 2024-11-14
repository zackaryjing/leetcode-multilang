#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<string> inject(vector<string> alist){
    vector<string> newlist;
    for (string j : alist){
        int length = j.length();
        for (int i = 0;i<length+1;i++){
            string t = j.substr(0,i)+"()"+j.substr(i,length);
            if (find(newlist.begin(),newlist.end(),t) == newlist.end()){
                newlist.push_back(t);
            }
        }
    }
    return newlist;
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result{""};
        for (int i = 0;i<n;i++){
            result = inject(result);
        }
        return result;
    }
};

int main(){
    Solution t;
    for (string k : t.generateParenthesis(5))
        cout << k << ' ';
}