#include <iostream>
#include <vector>

#include "../../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        if (n == 2) {
            return s[0] == s[1];
        }

        vector<unsigned char> half1(n / 2, 0), half2(n / 2, 0);
        vector<unsigned char> *curr = &half1, *prev = &half2;

        // 初始化half序列
        (*prev)[0] = 1;

        for (int i = 4; i <= n; i++) {
            (*curr)[0] = 1;
            int half_size = i / 2;
            for (int j = 1; j < (i - 1) / 2; j++) {
                (*curr)[j] = ((*prev)[j] + (*prev)[j - 1]) % 10;
            }
            if (i % 2 == 0) {
                (*curr)[half_size - 1] = ((*prev)[half_size - 2] * 2) % 10;
            }
            swap(curr, prev); // 交换指针，避免拷贝
        }

        vector<unsigned char> &half = *prev; // 最终的 half 存在 prev 里

        // show_vector(half);


        long long first = 0L;
        long long second = 0L;
        for (int i = 0; i < n - 1; i++) {
            int coeff = half[min(i, n - 2 - i)]; // 直接使用对称索引
            first = (first + (s[i] - '0') * coeff) % 10;
            second = (second + (s[i + 1] - '0') * coeff) % 10;
        }

        return first == second;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.hasSameDigits("33") << " <-" << endl;
    cout << test.hasSameDigits("33") << " <-" << endl;
    cout << test.hasSameDigits("333") << " <-" << endl;
    cout << test.hasSameDigits("3902") << " <-" << endl;
    cout << test.hasSameDigits("34789") << " <-" << endl;
    cout << test.hasSameDigits("347891") << " <-" << endl;
    cout << test.hasSameDigits("3478999") << " <-" << endl;
    cout << test.hasSameDigits("32789999") << " <-" << endl;
    cout << test.hasSameDigits("327899999") << " <-" << endl;
    cout << test.hasSameDigits("3278999999") << " <-" << endl;
    // cout << test.hasSameDigits(
    //             "129495904580593819405840275503271640167575942468717713001931500256181051542352807671016534391572584937145273251982655616180957892209623638927475919757645176627130689771566845400649994951040255774466397772898558015381610172678359394819502266450077945146015054209774634429738773288732173635665705969138926968192629272748399698455261010440802111329834520473895218693260033719927430976350990535484072670795612849761330958327790011213815706676356262955393437679364461603952876925465956502595269568051599897886473848391483060152534795704348701356663630034936179276802308270640930225306704362421291001409563775000832796244021573933920103312644843639121144368265021367436521998262155948200910195442227906791136215644730444495585993041857151274521174427471781155809183480617198908028067493729541422554829407379401690011628780963617921243745927377782614918338514207182124480773554261634005557616712911894643458297143033087581427589357795608404535334611311763593928460953854133588783209489300346431300")
    //         << " <-" << endl;
}


//
// Created by ASUS on 2025/2/23.
//
