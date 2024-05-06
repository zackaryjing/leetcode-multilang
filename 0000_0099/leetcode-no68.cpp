#include <iostream>
#include <vector>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        int curLength = 0;
        vector<string> ans;
        int wordsNum = 0;
        while (i < words.size()){
//            cout << i << endl;
            vector<string> tmp;
            string Tostring;
            while (true){
                if (i < words.size() and (curLength + wordsNum + words[i].size()) <= maxWidth){
                    tmp.push_back(words[i]);
                    curLength += words[i].size();
                    wordsNum ++;
                    i ++;
//                    cout << i << endl;
                } else {
//                    cout << " ---- " << wordsNum << " " << curLength << " --------- " << endl;
                    int even,extra;
                    if (wordsNum > 1) {
                        even = (maxWidth - curLength) / (wordsNum - 1);
                        extra = (maxWidth - curLength) % (wordsNum - 1);
                    } else {
                        even = (maxWidth - curLength);
                        extra = 0;
                    }
                    if (i != words.size()){
                        int j;
//                    cout << " Even:" << even << " extra:" << extra << endl;
                        for (j = 0;j < wordsNum - 1;j++){
                            Tostring += (tmp[j] + string(even,' ') + ((j < extra) ? " " : ""));
                        }
//                    cout << "here" << endl;
                        Tostring += tmp[j];
                        if (wordsNum == 1){
                            Tostring += string(even,' ');
                        }
                    } else {
                        int j = 0;
                        for (j = 0;j < wordsNum - 1;j++){
                            Tostring += (tmp[j] + " ");
                        }
                        Tostring += tmp[j] + string(maxWidth - curLength - wordsNum + 1,' ');
                    }
                    ans.push_back(Tostring);
                    curLength = 0;wordsNum = 0;
                    break;
                }
            }
        }
        return ans;
    }
};



class Solution2 {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        vector<string> ans;
//        cout << "?" << endl;
        while (i < words.size()){
            int curLength = words[i].size(),cnt = 0;
            while (true){
//                cout << i << endl;
                if ((i < words.size() - 1) and (curLength + words[i+1].size() < maxWidth)){
//                    cout << "now" << endl;
                    curLength += words[i+1].size();
//                    cout << "ok" << endl;
                    cout << curLength << " " << i << endl;
                    i++,cnt++;
                } else {
                    cout << " ----------- " << endl;
//                    cout << "failed here?" << endl;
                    int sufSpace,even;
                    if (cnt != 1){
                        sufSpace = (maxWidth - curLength) % (cnt - 1);
                        even = (maxWidth - curLength) / (cnt - 1);
                    } else {
                        sufSpace = 1;
                        even = maxWidth - curLength;
                    }
                    string tmp;
//                    cout << "please" << endl;
                    for (int j = i;j<i+cnt;j++){
                        tmp += words[j];
//                        cout << "must be here" << endl;
                        if (j < i + sufSpace){
//                            cout << even << " __ " << endl;
                            tmp += " " + string(even,' ');
                        } else if (j < i + cnt - 1){
//                            cout << even << " __ " << endl;
                            tmp += string(even,' ');
                        }
                    }
//                    cout << "never gonna give you up" << endl;
//                    cnt = 0;
//                    curLength = 0;
                    break;
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution test;
    vector<string> test1 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res = test.fullJustify(test1,16);
    for (auto i : res){
        cout << i << '|' << endl;
    }
    cout << endl;
    vector<string> test2 = {"What","must","be","acknowledgment","shall","be"};
    vector<string> res2 = test.fullJustify(test2,16);
    for (auto i : res2){
        cout << i << '|' << endl;
    }
    cout << endl;
    vector<string> test3 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> res3 = test.fullJustify(test3,20);
    for (auto i : res3){
        cout << i << '|' << endl;
    }
    cout << endl;
    vector<string> test4 = {"a"};
    vector<string> res4 = test.fullJustify(test4,1);
    for (auto i : res4){
        cout << i << '|' << endl;
    }
}

//
// Created by ASUS on 2023/7/8.
//
