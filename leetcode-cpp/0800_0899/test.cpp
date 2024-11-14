#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int find_upper(const vector<int> &data, int target) {
  cout << "find_upper: ";
  for (auto k : data) {
    cout << k << ",";
  }
  cout << endl;
  int n = data.size();
  int left = 0, right = n - 1;
  if (data[right] <= target) {
    return -1;
  } else if (data[left] > target) {
    return 0;
  }
  while (left <= right) {
    int mid = (left + right) / 2;
    if (target > data[mid]) {
      left = mid + 1;
    } else if (target < data[mid]) {
      right = mid - 1;
    } else {
      return mid + 1;
    }
  }
  return left;
}

int find_lower(const vector<int> &data, int target) {
  int n = data.size();
  int left = 0, right = n - 1;
  if (data[left] >= target) {
    return -1;
  } else if (data[right] < target) {
    return right;
  }
  while (left <= right) {
    int mid = (left + right) / 2;
    if (target > data[mid]) {
      left = mid + 1;
    } else if (target < data[mid]) {
      right = mid - 1;
    } else {
      return mid - 1;
    }
  }
  return right;
}

void find_next() {
  map<int, vector<int>> RowObs, ColObs;
  ColObs[0] = {6, 8, 9};
  vector<int> direction = {-1, 0};
  vector<int> curPos = {12, 0};
  vector<int> nextPos = {-2, 0};
  int command = 5;

  nextPos = {curPos[0] + direction[0] * command,
             curPos[1] + direction[1] * command};
  if (direction[0] == 1) {
    cout << "pos: " << curPos[0] << endl;
    auto res = find_upper(ColObs[curPos[1]], curPos[0]);
    cout << "type1: " << res << endl;
    if (res == -1 or ColObs[curPos[1]][res] > nextPos[0]) {
      curPos = nextPos;
    } else {
      curPos[0] = ColObs[curPos[1]][res] - 1;
    }

  } else if (direction[0] == -1) {
    auto res = find_lower(ColObs[curPos[1]], curPos[0]);
    if (res == -1) {
      curPos = nextPos;
    } else {
      curPos[0] = ColObs[curPos[1]][res] + 1;
    }
  } else if (direction[1] == 1) {
    auto res = find_upper(RowObs[curPos[0]], curPos[1]);
    if (res == -1) {
      curPos = nextPos;
    } else {
      curPos[0] = RowObs[curPos[0]][res] - 1;
    }
  } else if (direction[1] == -1) {
    auto res = find_lower(RowObs[curPos[0]], curPos[1]);
    if (res == -1) {
      curPos = nextPos;
    } else {
      curPos[0] = RowObs[curPos[0]][res] + 1;
    }
  }
  cout << curPos[0] << "," << curPos[1] << endl;
}

int main() {
  vector<int> a = {1, 3, 5, 7, 9, 11};
  find_next();
  //  cout << find_upper(a, 11) << endl;
  //  cout << find_upper(a, 5) << endl;
  //  cout << find_lower(a, 5) << endl;
  //  cout << find_lower(a, 6) << endl;
  //  cout << find_lower(a, 1) << endl;
}
//
// Created by ASUS on 2024/7/14.
//



using namespace std;

void show(const vector<int> &data) {
    for (auto k: data) {
        cout << k << ",";
    }
    cout << endl;
}

class Solution {
public:
    map<int, vector<int>> RowObs, ColObs;
    vector<int> direction = {1, 0};
    vector<int> curPos = {0, 0};
    vector<int> nextPos;
    int maxPos = 0;

    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        for (int i = 0; i < obstacles.size(); ++i) {
            RowObs[obstacles[i][1]].push_back(obstacles[i][0]);
            ColObs[obstacles[i][0]].push_back(obstacles[i][1]);
        }

        for (auto &[key, line]: RowObs) {
            std::sort(line.begin(), line.end());
        }
        for (auto &[key, line]: ColObs) {
            std::sort(line.begin(), line.end());
        }
        for (auto command: commands) {
            if (command == -1) {
                direction = {-direction[1], direction[0]};
            } else if (command == -2) {
                direction = {direction[1], -direction[0]};
            } else {
                nextPos = {curPos[0] + direction[0] * command,
                           curPos[1] + direction[1] * command};

                if (direction[0] == 1) {
                    auto res = find_upper(ColObs[curPos[1]], curPos[0]);
                    if (res == -1 or ColObs[curPos[1]][res] > nextPos[0]) {
                        curPos = nextPos;
                    } else {
                        curPos[0] = min(nextPos[0],ColObs[curPos[1]][res] - 1);
                    }

                } else if (direction[0] == -1) {
                    auto res = find_lower(ColObs[curPos[1]], curPos[0]);
                    if (res == -1) {
                        curPos = nextPos;
                    } else {
                        curPos[0] = max(nextPos[0],ColObs[curPos[1]][res] + 1);
                    }
                } else if (direction[1] == 1) {
                    auto res = find_upper(RowObs[curPos[0]], curPos[1]);
                    if (res == -1) {
                        curPos = nextPos;
                    } else {
                        curPos[1] = min(nextPos[1],RowObs[curPos[0]][res] - 1);
//                        curPos[1] = RowObs[curPos[0]][res] - 1;
                    }
                } else if (direction[1] == -1) {
                    auto res = find_lower(RowObs[curPos[0]], curPos[1]);
                    if (res == -1) {
                        curPos = nextPos;
                    } else {
                        curPos[1] = max(nextPos[1],RowObs[curPos[0]][res] + 1);
//                        curPos[1] = RowObs[curPos[0]][res] + 1;
                    }
                }
            }
            maxPos = max(maxPos, (int) pow(curPos[0], 2) + (int) pow(curPos[1], 2));
        }
        return maxPos;
    }

    int find_upper(const vector<int> &data, int target) {
        int n = data.size();
        if (n == 0) {
            return -1;
        }
        int left = 0, right = n - 1;
        if (data[right] <= target) {
            return -1;
        } else if (data[left] > target) {
            return 0;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > data[mid]) {
                left = mid + 1;
            } else if (target < data[mid]) {
                right = mid - 1;
            } else {
                return mid + 1;
            }
        }
        return left;
    }

    int find_lower(const vector<int> &data, int target) {
        int n = data.size();
        if (n == 0) {
            return -1;
        }
        int left = 0, right = n - 1;
        if (data[left] >= target) {
            return -1;
        } else if (data[right] < target) {
            return right;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > data[mid]) {
                left = mid + 1;
            } else if (target < data[mid]) {
                right = mid - 1;
            } else {
                return mid - 1;
            }
        }
        return right;
    }
};

