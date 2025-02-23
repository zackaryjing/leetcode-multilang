#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string entityParser(string text) {
        size_t n = text.size();
        string ans;
        for (int i = 0; i < n; i++) {
            if (text[i] == '&') {
                if (i + 1 < n) {
                    switch (text[i + 1]) {
                        case 'q':
                            if (i + 5 < n and string_view(text.data() + i + 1, 5) == "quot;") {
                                ans.append("\"");
                                i += 5;
                                break;
                            }
                        case 'g':
                            if (i + 3 < n and string_view(text.data() + i + 1, 3) == "gt;") {
                                ans.append(">");
                                i += 3;
                                break;
                            }
                        case 'l':
                            if (i + 3 < n and string_view(text.data() + i + 1, 3) == "lt;") {
                                ans.append("<");
                                i += 3;
                                break;
                            }
                        case 'f':
                            if (i + 6 < n and string_view(text.data() + i + 1, 6) == "frasl;") {
                                ans.append("/");
                                i += 6;
                                break;
                            }

                        case 'a': {
                            if (i + 5 < n and string_view(text.data() + i + 1, 5) == "apos;") {
                                ans.append("'");
                                i += 5;
                                break;
                            }
                            if (i + 4 < n and string_view(text.data() + i + 1, 4) == "amp;") {
                                ans.append("&");
                                i += 4;
                                break;
                            }
                        }
                        default:
                            ans += '&';
                    }
                } else {
                    ans += text[i];
                }
            } else {
                ans += text[i];
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.entityParser("&amp; is an HTML entity but &ambassador; is not.") << endl;;
    cout << test.entityParser("&&&") << endl;;
}


//
// Created by ASUS on 2025/2/23.
//
