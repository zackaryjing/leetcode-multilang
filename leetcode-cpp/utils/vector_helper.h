#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template<typename T>
void show_vector(vector<T> data) {
    for (auto k: data) {
        cout << to_string(k) << " ";
    }
    cout << endl;
}

void show_vector(vector<string> data) {
    for (auto k: data) {
        cout << k << " ";
    }
    cout << endl;
}

template<typename T>
void show_matrix(vector<vector<T> > data) {
    for (auto k: data) {
        for (auto h: k) {
            cout << to_string(h) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
vector<T> &temp_vector(vector<T> v) {
    return *make_unique<vector<T> >(v);
}

vector<int> &temp_vector(vector<int> v) {
    return *make_unique<vector<int> >(v);
}

//
// Created by ASUS on 2025/2/10.
//
