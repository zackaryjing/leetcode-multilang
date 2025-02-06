#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<vector<int> > > results;

    vector<int> diffWaysToCompute(string expression) {
        vector<int> numbers;
        vector<int> operators;
        int curNum = 0;
        for (int i = 0; i < expression.length(); i++) {
            if (std::isalnum(expression.at(i))) {
                curNum *= 10;
                curNum += expression[i] - '0';
            } else {
                numbers.push_back(curNum);
                curNum = 0;
                operators.push_back(expression[i]);
            }
        }
        numbers.push_back(curNum);
        int n = numbers.size();
        results = vector(n, vector<vector<int> >(n));
        for (int i = 0; i < n; i++) {
            results[i][i].push_back(numbers[i]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                for (int k = j; k < j + i; k++) {
                    for (auto a: results[j][k]) {
                        for (auto b: results[k + 1][j + i]) {
                            results[j][j + i].push_back(operand(a, b, operators[k]));
                        }
                    }
                }
            }
        }
        return results[0][n - 1];
    }

    int operand(const int a, const int b, const int t) {
        switch (t) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            default:
                return a * b;
        }
    }
};

int main() {
    Solution test;
    string eg1 = "2-1-1";
    auto ans1 = test.diffWaysToCompute(eg1);
    for (auto var: ans1) cout << var << endl;
    string eg2 = "2*3-4*5";
    auto ans2 = test.diffWaysToCompute(eg2);
    for (auto var: ans2) cout << var << endl;
}


//
// Created by ASUS on 2025/1/23.
//
