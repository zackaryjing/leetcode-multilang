#include <iostream>
#include <String>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result;
        result.resize(1000,"");
        int node = numRows - 1;
        if (node == 0)
            return s;
        int length = s.length();
        int change = 0;
        for (int i = 0;i<length;i++){
            if (change == 0){
                result[i%node] += s[i];
            } else {
                result[node-i%node] += s[i];
            }
            if ((i % node == node - 1) && change == 0){
                change = 1;
            } else if ((i%node == node - 1) && change == 1) {
                change = 0;
            }
        }
        string output = "";
        for (auto j : result){
            output += j;
        }
        return output;
    }
};

int main(){
    Solution t;
    string ans = t.convert("PAYPALISHIRING",3);
    cout << ans << '\n';
    return 0;
}



