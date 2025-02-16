#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void show_vector(vector<T>& data) {
    for (auto k : data) {
        cout << to_string(k) << " ";
    }
    cout << endl;
}

template<typename T>
void show_matrix(vector<vector<T>>& data) {
    for (auto k: data) {
        for (auto h : k) {
            cout << to_string(h) << " ";
        }
        cout << endl;
    }
    cout << endl;
}


//
// Created by ASUS on 2025/2/10.
//
