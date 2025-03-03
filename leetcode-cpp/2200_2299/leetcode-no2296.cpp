#include <iostream>
#include <vector>

using namespace std;

class TextEditor {
private:
    string first;
    string second;

public:
    TextEditor() {
    }

    void addText(string text) {
        first.append(text);
    }

    int deleteText(int k) {
        int n = first.size();
        k = min(n, k);
        first.erase(n - k);
        return k;
    }

    string cursorLeft(int k) {
        k = min(static_cast<int>(first.size()), k);
        second.insert(0, first, first.size() - k, k);
        first.erase(first.size() - k, k);
        return first.substr(max((int) first.size() - 10, 0));
    }

    string cursorRight(int k) {
        k = min(static_cast<int>(second.size()), k);
        first.append(second, 0, k);
        second.erase(0, k);
        return first.substr(max((int) first.size() - 10, 0));
    }

    void show() {
        cout << 3 << endl;
        cout << first << " " << second << endl;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main(int argc, char *argv[]) {
    TextEditor test;
    test.addText("leetcode");
    test.show();
    test.deleteText(4);
    test.show();
    test.addText("practice");
    test.show();
    cout << test.cursorRight(4) << "<-" << endl;
    cout << test.cursorLeft(8) << "<-" << endl;
    test.show();
    test.show();
}


//
// Created by ASUS on 2025/2/27.
//
