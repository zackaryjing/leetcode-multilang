#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
bool isPalindrome(int x){
    char string[16] = {0};
    itoa(x,string,10);
    // printf("%s",string);
    int length = strlen(string);
    for (int i = 0;i<length;i++){
        if (!(string[i] == string[length - i - 1])){
            return false;
        }
    }
    return true;
}
int main(){
    bool t = isPalindrome(-12321);
    printf(t ? "true" : "false");
}