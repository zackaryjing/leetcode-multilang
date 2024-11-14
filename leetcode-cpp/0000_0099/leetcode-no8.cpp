#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
//#include <string>
//#include <cstdlib>
using namespace std;
class Solution2 {
public:
    int myAtoi(string s) {
        int positive = 1;
        string num = "0";
        string validchar = " +-0123456789";
        string validsign = "+-";
        string validsign1 = " +-";
        string nums = "0123456789";
        string snums = " 0123456789";
        unsigned long long length = s.length();
//        cout << length << " length" << endl;
        for (int i = 0;i<length;i++){
//            cout << i << " i" << endl;
            if (validchar.find(s[i]) == string::npos){
//                cout << "bad" << endl;
                break;
            }
//            cout << nums << " " << s[i] << endl;
            if ((i < length - 1) && (validsign.find(s[i]) != string::npos) && (snums.find(s[i+1]) == string::npos)){
//                cout << "bad" << endl;
                break;
            }

//            cout << nums << " " << s[i] << endl;
            if (s[i] == '-'){
                if (nums.find(s[i+1]) == string::npos){
//                    cout << "bad" << endl;
                    break;
                }
                positive = 0;
            } else if (s[i] == '+'){
                if (nums.find(s[i+1]) == string::npos){
//                    cout << "bad" << endl;
                    break;
                }
            }
            if (nums.find(s[i]) != string::npos){
//                cout << i << " here" << endl;
                num += s[i];
                if (i < length - 1){
                    if (validsign1.find(s[i+1]) != string::npos){
//                        cout << "bad" << endl;
                        break;
                    }
                }
            }
        }
//        cout << num << " num**" << endl;
        while (num != "0") {
//            cout << num << endl;
            if (num[0] == '0') num.erase(0,1);
            else break;
        }
//        cout << num << " num" << endl;
        unsigned long long result;
        if (positive == 1) {
            if (num.length() >= 20){
                return 2147483647;
            };
            result = stoull(num);
            if (result > 2147483647){
                return 2147483647;
            } else {
                return (int)result;
            }
        } else {
            if (num.length() >= 20){
                return -2147483648;
            };
            result = stoull(num);
            if (result > 2147483648){
                return -2147483648;
            } else {
                return (int)-result;
            }
        }

//        if (positive == 0){
//            result = -stoull(num);
//        } else {
//            result = stoull(num);
//        }
//        if (result >= 2147483648) return 2147483647;
//        else if (result <= -2147483648) return -2147483648;
//        return result;
    }
};

class Automaton {
    string state = "start";
    unordered_map<string,vector<string>> table = {
            {"start",{"start","signed","in_number","end"}},
            {"signed",{"end","end","in_number","end"}},
            {"in_number",{"end","end","innumber","end"}},
            {"end",{"end","end","end","end"}}
    };
    int get_col(char c){
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c){
        state = table[state][get_col(c)];
        if (state == "in_number"){
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans,(long long)INT_MAX) : min(ans,-(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};


int main(){
    Solution2 t;
    cout << t.myAtoi("  0000000000012345678") << endl;
    cout << t.myAtoi("20000000000000000000") << endl;
    cout << t.myAtoi("-2147483648") << endl;
    cout << t.myAtoi(" -42") << endl;
    cout << t.myAtoi("42") << endl;
    cout << t.myAtoi("  +   413") << endl;
}

//
// Created by ASUS on 2023/4/18.
//
//    18446744073709551616
//    20000000000000000000
