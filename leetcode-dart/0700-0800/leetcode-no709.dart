class Solution {
  String toLowerCase(String s) {
    StringBuffer ans = StringBuffer();
    for (int i = 0;i < s.length;i++){
      String char = s[i];
      if (char.compareTo('Z') <= 0 && char.compareTo('A') >= 0) {
        ans.writeCharCode(char.codeUnitAt(0) + 32);
      } else {
        ans.write(char);
      }
    }
    return ans.toString();
  }
}

void main(){
  Solution solution = Solution();
  String testString = "ThisIs&aTestString";
  print(solution.toLowerCase(testString));
}

