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
std::vector<T> &temp_vector(std::vector<T> v) {
    static std::vector<std::unique_ptr<std::vector<T> > > pool;
    pool.emplace_back(std::make_unique<std::vector<T> >(std::move(v)));
    return *pool.back();
}

//
// Created by ASUS on 2025/2/10.
//
