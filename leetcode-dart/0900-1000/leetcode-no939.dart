import 'dart:collection';

import 'dart:math';

class Solution {
  int minAreaRect(List<List<int>> points) {
    points.sort((x, y) => x[0] - y[0]);
    Map<int, Set<int>> pointsSet = Map();
    for (var point in points) {
      int x = point[0];
      int y = point[1];
      if (pointsSet[x] == null) {
        pointsSet[x] = Set();
      }
      pointsSet[x]!.add(y);
    }
    int ans = 1600000001;
    for (int i = 0; i < points.length; i++) {
      int x1 = points[i][0];
      int y1 = points[i][1];
      for (int j = i + 1; j < points.length; j++) {
        int x2 = points[j][0];
        int y2 = points[j][1];
        if (pointsSet[x2]!.contains(y1) && pointsSet[x1]!.contains(y2) && x1 != x2 && y1 != y2) {
          ans = min(ans, ((y2 - y1) * (x2 - x1)).abs());
        }
      }
    }
    if (ans == 1600000001) {
      return 0;
    }
    return ans;
  }
}

void main() {
  Solution test = Solution();
  List<List<int>> points = [[1,1],[1,3],[3,1],[3,3],[2,2]];
  print(test.minAreaRect(points));
}
