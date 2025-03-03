#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class OrderedStream {
public:
    vector<string> data;
    int _n;
    int cur = 0;

    OrderedStream(int n) {
        data = vector<string>(n);
        _n = n;
    }

    vector<string> insert(int idKey, string value) {
        idKey--;
        data[idKey] = value;
        vector<string> ans;
        if (idKey == cur) {
            ans.push_back(value);
            while (idKey + 1 < _n and not data[idKey + 1].empty()) {
                ans.push_back(data[idKey + 1]);
                idKey++;
            }
            cur = idKey + 1;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main(int argc, char *argv[]) {
    OrderedStream test(5);
    show_vector(test.insert(3, "ccccc"));
    show_vector(test.insert(1, "aaaaa"));
    show_vector(test.insert(2, "bbbbb"));
    show_vector(test.insert(5, "eeeee"));
    show_vector(test.insert(4, "ddddd"));
}

//
// Created by ASUS on 2025/2/24.
//
