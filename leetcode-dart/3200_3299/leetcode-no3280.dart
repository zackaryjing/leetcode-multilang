class Solution {
  String convertDateToBinary(String date) {
    List<String> ans = [];
    for (var part in date.split("-")) {
      int value = int.parse(part);
      ans.add(value.toRadixString(2));
    }
    return ans.join("-");
  }
}

void main() {
  var test = Solution();
  print(test.convertDateToBinary("2080-02-29"));
}