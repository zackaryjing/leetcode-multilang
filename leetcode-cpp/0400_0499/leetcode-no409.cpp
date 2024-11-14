#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> data;
        for (auto i : s){
            data[i] ++;
        }
        int ans = 0,max = 0,ok=0;
        for (auto [key,value] : data){
//            cout << key << " * " << value << endl;
            if (!(value % 2)) {
//                cout << "here" << " - " << value << endl;
                ans += value;
            } else {
                ans += value - 1;
                ok = 1;
                // max = (max < value) ? value : max;
            }
        }
//        cout << max << " " << ans << endl;
        return ans + ok;
    }
};

int main(){
    Solution test;
    cout << test.longestPalindrome("abccccdd") << endl;
    cout << test.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << endl;
    // map<string,int> test1;
    // test1["a"] = 9;
    // test1["b"] = 19;

//    cout << test1["lying"] + 1 << endl;
//    cout << test1["a"] << " " << test1["c"] << endl;
}

//
// Created by ASUS on 2023/6/15.
//
