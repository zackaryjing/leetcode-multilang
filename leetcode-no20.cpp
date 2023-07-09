#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> alist;
        string first = "([{";
        string second = "}])";
        map<char,char> dic = {{'(',')'},{'[',']'},{'{','}'}};
        char k;
        for (char i : s){
            if (first.find(i) != first.size()){
                alist.push_back(i);
            }
            printf("%c\n",i);
            if (second.find(i) != second.size()){
                try{
                    k = alist[alist.size()];
                } catch (exception){
                    return false;
                }
                if (i != dic[k]){
                    return false;
                }
            }
        }
        printf("asdf");
        if (alist.size() == 0){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    Solution t;
    printf(t.isValid("()[]{}") ? "yes" : "no");
}