class Solution {
  bool squareIsWhite(String coordinates) {
    return (((coordinates.codeUnitAt(0) - 'a'.codeUnitAt(0)) +
                int.parse(coordinates[1])) %
            2) ==
        0;
  }
}

void main() {
  Solution test = Solution();
  print(test.squareIsWhite('a1'));
  print(test.squareIsWhite('h3'));
  print(test.squareIsWhite('c7'));}
