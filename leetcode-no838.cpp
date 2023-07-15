#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string ans = dominoes;
        int left = 0,right;
        for (int i = 0;i<n;i++){
            if (dominoes[i] != '.'){
//                cout << i << " + + " << endl;
//                cout << " he1 " << endl;
                right = i;
                if (left == 0){
                    if (dominoes[i] == 'L'){
                        for (int j = 0;j < right;j++){
                            ans[j] = dominoes[i];
                        }
                    }
                    left = i;
                } else {
//                    cout << " he2 " << endl;
                    if (dominoes[left] == dominoes[right]){
                        for (int j = left;j < right;j++){
                            ans[j] = dominoes[i];
                        }
                    } else {
//                        cout << " he3 " << endl;
                        for (int j = left;j <= (left + right - 1) / 2 ;j++){
                            ans[j] = dominoes[left];
                        }
//                        cout << " he4 " << left << " " << right << " " << ans << endl;
                        for (int j = right;j >= (left + right + 2) / 2 ;j--){
                            ans[j] = dominoes[right];
//                            cout << " j " << j << endl;
                        }
//                        cout << " where " << endl;
                        left = right;
                    }
                }
            }
        }
//        cout << left << " -- " << dominoes[left] << endl;
        if (dominoes[left] == 'R'){
            for (int j = left;j < n;j++){
                ans[j] = dominoes[left];
            }
        }
//        cout << ans.size() << endl;
        return ans;
    }
};

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(),left = 0,right = 0;
        string ans = dominoes;
        for (int i = 0;i < n;i++){
//            cout << " i: " << i << endl;
            if (dominoes[i] != '.' or i == n - 1) {
                left = right;
                right = i;
//                cout << "L: " << left << " R: " << right << endl;
                if (dominoes[left] == 'R' and dominoes[right] == 'L') {
                    for (int j = left; j <= (left + right - 1) / 2; j++) {
                        ans[j] = 'R';
                    }
                    for (int j = right; j >= (left + right + 2) / 2; j--) {
                        ans[j] = 'L';
                    }
                } else if (dominoes[left] == dominoes[right]) {
                    for (int j = left; j <= right; j++) {
                        ans[j] = dominoes[left];
                    }
                } else if (dominoes[left] == '.' and dominoes[right] == 'L') {
                    for (int j = left; j <= right; j++) {
                        ans[j] = 'L';
                    }
                } else if (dominoes[right] == '.' and dominoes[left] == 'R') {
                    for (int j = left; j <= right; j++) {
                        ans[j] = 'R';
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
//    cout << test.pushDominoes("RR.L") << endl;
    cout << test.pushDominoes(".L.R...LR..L..") << endl;
    cout << test.pushDominoes("RR.L") << endl;
    cout << test.pushDominoes(".L.R.") << endl;
    cout << test.pushDominoes("RL") << endl;
//    cout << test.pushDominoes(".L.R...LR..L..") << endl;
}
//
// Created by ASUS on 2023/7/12.
//
