#include <iostream>
#include <memory>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

template<typename T>
void show_vector(vector<T> data) {
    cout << "[";
    for (auto k: data) {
        cout << to_string(k) << " ";
    }
    cout << "]" << endl;
}

template<size_t T>
void show_vector(vector<bitset<T>> data) {
    for (auto k: data) {
        cout << k << " ";
    }
    cout << endl;
}

void show_vector(vector<bool> data) {
    cout << "[";
    for (auto k: data) {
        cout << k << " ";
    }
    cout << "]" << endl;
}

void show_vector(vector<string> data) {
    for (auto k: data) {
        cout << k << " ";
    }
    cout << endl;
}

template<typename T>
void show_matrix(vector<vector<T>> data) {
    for (auto k: data) {
        for (auto h: k) {
            cout << to_string(h) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<size_t T>
void show_matrix(vector<vector<bitset<T>>> data) {
    for (auto k: data) {
        for (auto h: k) {
            cout << h << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
std::vector<T> &temp_vector(std::vector<T> v) {
    static std::vector<std::unique_ptr<std::vector<T>>> pool;
    pool.emplace_back(std::make_unique<std::vector<T>>(std::move(v)));
    return *pool.back();
}

template<typename T>
std::vector<T> &temp_vector(std::initializer_list<T> il) {
    return temp_vector(std::vector<T>(il));
}

inline std::vector<int> &temp_vector(vector<int> v) {
    static std::vector<std::unique_ptr<std::vector<int>>> pool;
    pool.emplace_back(std::make_unique<std::vector<int>>(std::move(v)));
    return *pool.back();
}

inline std::vector<vector<int>> &temp_vector(vector<vector<int>> v) {
    static std::vector<std::unique_ptr<std::vector<vector<int>>>> pool;
    pool.emplace_back(std::make_unique<std::vector<vector<int>>>(std::move(v)));
    return *pool.back();
}

//
// Created by ASUS on 2025/2/10.
//
