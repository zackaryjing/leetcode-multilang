#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm> 
#include <vector>
using namespace std;

void test(int* v,int lvl){
    cout << lvl << " ** " ;
    if (lvl > 6){
        *v = 10;
        return;
    }
    test(v,lvl + 1);
}

int main() {
    int ans = 9;
    test(&ans,0);
    cout << ans;
//    vector<int> test1 = {1,1,2,34,5};
//    vector<int> test2 = {23,2,4,5,6};
//    int a = 9,b = 3;
//    cout << min(test1.size(),test2.size()) << endl;
//    cout << test1.size() << " " << test2.size() << endl;
//    cout << min(3,11) << endl;
//    cout << min(a,b) << endl;
//    cout << test1.size();
//    string test1 = "asdf";
//    string test2 = test1;
//    test2[1] = 'h';
//    cout << test1 << endl;
//    cout << test2 << endl;
//    vector<string> t1 = {"a","b","c","d"};
//    vector<string> t2 = {"a","b","c","d","t","h"};
//    vector<string> res(8);
//    auto iter = set_intersection(t1.begin(),t1.end(),t2.begin(),t2.end(),res.begin());
//    cout << res.size() << endl;
//    for (auto i : res) cout << i << endl;
    // cout << iter << endl;
}

// #define k 18446744073709551615
// #define h 4958209

//int main(){
//    vector<int> ans(10);
//    ans[3] = 2;
//    vector<int> hhh = {1,23,4,5};
//    cout << hhh.back() << endl;
//    typedef struct asdf{
//        int a;
//        explicit asdf(int x) : a(x) {};
//    } asdf;
//    vector<asdf> fds = {asdf(1),asdf(3),asdf(4),asdf(5),asdf(6)};
//    cout << fds.back().a << endl;
//    vector<int> another;
//    cout << another.empty() << endl;
//    vector<int> list1 = {1,2,3,4};
//    vector<int> list2(list1);
//    cout << list2[2] << endl;
//    string t = "0";
//    unsigned long long u = stoull(t);
//    cout << u << endl;
//    unsigned long long bad = 1844073709551616;
//    cout << -(long long)bad << endl;
//    cout << 9146744073709551614 << endl;
//    cout << k << endl;
//    cout << h << endl;
//    cout << k << endl;
//    string temp = to_string(1234);
//    reverse(temp.begin(),temp.end());
//    vector<int> alist = {1,2,3,4};
//    string alist = "1234";
//    if (alist.find("2") == alist.length()){
//        printf("True");
//    } else {
//        printf("False");
//    }
//    string str1 = "hhlkjk";
//    if (str1.find('h') == string::npos) {
//        cout << "bad" << endl;
//    } else {
//        cout << "good" << endl;
//    }

//    if (str1[0] == "h"){
//        cout << "good" << endl;
//    }
// };
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         vector <string> a;
//         a.resize(1000,"");
//         string b = "asdf";
//         a[0] += b;
//         cout << a[0] << '\n';
//         return "hello";
//     }
// };


