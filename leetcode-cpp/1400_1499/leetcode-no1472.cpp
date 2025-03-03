#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class BrowserHistory {
    // 直接抄了官解，交了一发，看上去也不太行啊
public:
    BrowserHistory(string homepage) {
        this->urls.push_back(homepage);
        this->currIndex = 0;
    }

    void visit(string url) {
        while (urls.size() > currIndex + 1) {
            urls.pop_back();
        }
        urls.push_back(url);
        this->currIndex++;
    }

    string back(int steps) {
        currIndex = max(currIndex - steps, 0);
        return urls[currIndex];
    }

    string forward(int steps) {
        currIndex = min(currIndex + steps, int(urls.size() - 1));
        return urls[currIndex];
    }

private:
    vector<string> urls;
    int currIndex;
};


class BrowserHistory2 {
    // 双端队列，emm，效率挺糟糕的，但是吧，感觉没必要重做
public:
    deque<string> prev;
    deque<string> next;

    BrowserHistory(string homepage) {
        next.push_front(homepage);
    }

    void visit(string url) {
        prev.push_back(next.front());
        next.clear();
        next.push_back(url);
    }

    string back(int steps) {
        int size = min(steps, static_cast<int>(prev.size()));
        for (int i = 0; i < size; i++) {
            next.push_front(prev.back());
            prev.pop_back();
        }
        return next.front();
    }

    string forward(int steps) {
        int size = min(steps, static_cast<int>(next.size() - 1));
        for (int i = 0; i < size; i++) {
            prev.push_back(next.front());
            next.pop_front();
        }
        return next.front();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(int argc, char *argv[]) {
    BrowserHistory test("leetcode.com");
    test.visit("google.com");
    test.visit("facebook.com");
    test.visit("youtube.com");
    cout << test.back(1) << endl;
    cout << test.back(1) << endl;
    cout << test.forward(1) << endl;
    test.visit("linkedin.com");
    cout << test.forward(2) << endl;
    cout << test.back(2) << endl;
    cout << test.back(7) << endl;
}


//
// Created by ASUS on 2025/2/26.
//
