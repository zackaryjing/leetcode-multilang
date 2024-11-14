#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648){
            return 0;
        }
        if (x >= 0){
            string temp = to_string(x);
            std::reverse(temp.begin(),temp.end());
            long long int ans = std::stoll(temp);
            if (ans < 2147483648){
                return ans;
            }
        } else {
            string temp = to_string(-x);
            std::reverse(temp.begin(),temp.end());
            long long int ans = std::stoll("-"+temp);
            if (ans >= -2147483648){
                return ans;
            }
        }
    return 0;
    }
};

int main(){
    Solution t;
    cout << t.reverse(-2340) << '\n';
    cout << t.reverse(-2147483648) << '\n';
    cout << t.reverse(1534236469) << '\n';
}
// int main(){
//     string temp = to_string(1234);
//     reverse(temp.begin(),temp.end());
//     cout << temp << '\n';
// }