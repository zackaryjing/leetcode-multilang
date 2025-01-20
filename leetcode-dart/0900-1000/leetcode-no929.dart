import 'dart:collection';

class Solution {
  int numUniqueEmails(List<String> emails) {
    Set<String> address = Set();
    for (var email in emails) {
      var parts = email.split("@");
      address.add(parts[0].split("+")[0].split(".").join() + "@" + parts[1]);
    }
    return address.length;
  }
}

void main() {
  Solution test = Solution();
  List<String> emails = [
    "test.email+alex@leetcode.com",
    "test.e.mail+bob.cathy@leetcode.com",
    "testemail+david@lee.tcode.com"
  ];
  print(test.numUniqueEmails(emails));
}
