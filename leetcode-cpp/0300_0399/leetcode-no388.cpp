#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> length = {0};
        int max_length = 0;
        int current_length = 0;
        int current_depth = 0;
        bool is_file = false;
        for (int i = 0; i < input.length(); i++) {
            auto ch = input[i];
            int depth = 0;
            if (ch == '.') {
                is_file = true;
            }
            if (ch == '\n') {
                current_length++;
                while (input[i + 1] == '\t') {
                    i++;
                    depth++;
                }
                if (current_length > max_length) {
                    if (is_file) {
                        max_length = current_length;
                    }
                }
                if (depth > current_depth) {
                    length.push_back(current_length);
                    current_depth++;
                } else if (depth < current_depth) {
                    for (; current_depth > depth; current_depth--) {
                        length.pop_back();
                        current_length = length.back();
                    }
                } else {
                    current_length = length.back();
                }
                is_file = false;
            } else {
                current_length++;
            }
        }
        current_length++;
        if (current_length > max_length) {
            if (is_file) {
                max_length = current_length;
            }
        }
        return max(max_length - 1, 0);
    }
};

int main() {
    Solution test;
    cout << test.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") << endl;
    cout << test.lengthLongestPath(
        "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
    cout << test.lengthLongestPath("a") << endl;
    cout << test.lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt") << endl;
    cout << test.lengthLongestPath(
                "skd\n\talskjv\n\t\tlskjf\n\t\t\tklsj.slkj\n\t\tsdlfkj.sdlkjf\n\t\tslkdjf.sdfkj\n\tsldkjf\n\t\tlskdjf\n\t\t\tslkdjf.sldkjf\n\t\t\tslkjf\n\t\t\tsfdklj\n\t\t\tlskjdflk.sdkflj\n\t\t\tsdlkjfl\n\t\t\t\tlskdjf\n\t\t\t\t\tlskdjf.sdlkfj\n\t\t\t\t\tlsdkjf\n\t\t\t\t\t\tsldkfjl.sdlfkj\n\t\t\t\tsldfjlkjd\n\t\t\tsdlfjlk\n\t\t\tlsdkjf\n\t\tlsdkjfl\n\tskdjfl\n\t\tsladkfjlj\n\t\tlskjdflkjsdlfjsldjfljslkjlkjslkjslfjlskjgldfjlkfdjbljdbkjdlkjkasljfklasjdfkljaklwejrkljewkljfslkjflksjfvsafjlgjfljgklsdf.a")
            << endl;
}


//
// Created by ASUS on 2025/2/4.
//
