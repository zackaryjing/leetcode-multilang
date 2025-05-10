class Solution {
  bool lemonadeChange(List<int> bills) {
    List<int> available = [];
    for (var bill in bills) {
      int bill_copy = bill;
      if (bill == 5) {
        available.add(5);
      } else {
        int len = available.length - 1;
        available.sort();
        bill -= 5;
        for (var i = len; i >= 0; i--) {
          if (available[i] <= bill) {
            // print("currentBill: ${bill} remove ${available[i]}");
            bill -= available[i];
            available.removeAt(i);
          }
          if (bill == 0) {
            available.add(bill_copy);
            break;
          }
        }
        if (bill != 0) {
          return false;
        }
      }
    }
    return true;
  }
}


void main() {
  List<int> bills = [5,5,5,10,20];
  Solution test = Solution();
  bool ans = test.lemonadeChange(bills);
  print("ans: $ans");
}