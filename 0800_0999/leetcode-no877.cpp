#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        piles.insert(piles.begin(),-1);
        piles.push_back(-1);
        int n = piles.size(),left,right,times = 0;
        vector<int> data;
        for (int i = 1;i<n + 1;i++){
            data = {0,0};
            left = i - 1;
            right = i + 1;
            while (left > 0 or right < n + 1){
                if (piles[left] > piles[right]){
                    data[times % 2] += piles[left];
                    left --;
                } else {
                    data[times % 2] += piles[right];
                    right ++;
                }
            }
        }
        if (data[0] > data[1]);
    }
};

int main() {
    cout << (4 < 3 + 2) << endl;
    printf("`what would you like to do?`");
}

/*
 * This is a comment
 * I am tring my  new keyboard
 * It is a little biy higher than my preioust one.
 * Really,i even need to place a book in the front of it to make my self feel a bit more comfortable.
 * So , here comes the question, Should I sell my old keyboar now?
 * So far it still feels smooth.`just a little bit tough to type the this symalbe`
 * it is indeed quiter than my previous keyboard.
 */



//
// Created by ASUS on 2023/7/3.
//目前我正在对比两款键盘的差异。可以说旧键盘的声音略大是因为底部的腔体，本身是红轴，轴体的声音并不大
// 现在来测试一下新键盘，其实还挺灵敏的，就是倾斜度不能调整，是一个遗憾的地方。
//

int main2(){
    for (int i = 0;i < 9;i++){
        printf("So far it is not that disappointing");
        printf("lalla,anyway it is going to be an interesting journey to go with my new keyboard.");
        cout << "goodday" << endl;
        cout << "So yes, this keyboard is even more fancy" << endl;
        cout << "keep tring the function of the new keyboard." <<endl;
        cout << "not that bad" << endl;
        cout << "yes the brand new one" << endl;

    }
   }