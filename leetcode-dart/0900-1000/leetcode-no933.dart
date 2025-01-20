class RecentCounter {
  List<int> link = [];
  int head = 0;
  int total = 0;

  RecentCounter() {}

  int ping(int t) {
    link.add(t);
    total += 1;
    while (link[head] < t - 3000) {
      head++;
      total -= 1;
    }
    return total;
  }
}

void main() {
  RecentCounter recentCounter = RecentCounter();
  print(recentCounter.ping(0));
  print(recentCounter.ping(1));
  print(recentCounter.ping(2));
  print(recentCounter.ping(3000));
  print(recentCounter.ping(3001));
  print(recentCounter.ping(6001));

}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = RecentCounter();
 * int param1 = obj.ping(t);
 */
