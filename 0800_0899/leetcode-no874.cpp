#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

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


int main() {

    //  Solution test;
    //  vector<int> num1 = {4, -1, 3};
    //  vector<vector<int>> obs1 = {};
    //  cout << test.robotSim(num1, obs1) << endl;

    //  Solution test2;
    //  vector<int> num2 = {4, -1, 4, -2, 4};
    //  vector<vector<int>> obs2 = {{2, 4}};
    //  cout << test2.robotSim(num2, obs2) << endl;

    //  Solution test3;
    //  vector<int> num3 = { 6,-1,-1,6 };
    //  vector<vector<int>> obs3 = {{3, 4}};
    //  cout << test3.robotSim(num3, obs3) << endl;

    Solution test4;
    vector<vector<int>> obs4 = {
            {39,   83},
            {1,    30},
            {-62,  -88},
            {-82,  -65},
            {81,   -88},
            {-100, -74},
            {-33,  64},
            {96,   -15},
            {91,   -71},
            {27,   33},
            {-66,  28},
            {99,   83},
            {80,   3},
            {-65,  -53},
            {92,   -47},
            {14,   -71},
            {-70,  -6},
            {-42,  -31},
            {92,   73},
            {-47,  -59},
            {-77,  -8},
            {-89,  8},
            {-2,   -22},
            {-95,  61},
            {-76,  -75},
            {5,    -52},
            {81,   32},
            {12,   -15},
            {-69,  -20},
            {81,   -77},
            {-79,  -42},
            {13,   -32},
            {-6,   12},
            {-6,   95},
            {54,   -17},
            {-55,  -76},
            {9,    -93},
            {51,   -27},
            {73,   -70},
            {13,   -3},
            {-72,  38},
            {8,    56},
            {88,   56},
            {62,   16},
            {-5,   -94},
            {-55,  31},
            {-21,  69},
            {-32,  82},
            {-80,  60},
            {-1,   54},
            {-52,  22},
            {30,   52},
            {-35,  -55},
            {-100, 75},
            {98,   10},
            {-67,  41},
            {44,   38},
            {18,   -29},
            {73,   0},
            {-29,  -62},
            {-27,  -67},
            {-42,  -64},
            {-60,  20},
            {-32,  18},
            {60,   -89},
            {-31,  98},
            {-27,  85},
            {53,   -38},
            {-58,  -33},
            {9,    -9},
            {-66,  -26},
            {72,   46},
            {49,   99},
            {58,   -80},
            {-10,  -76},
            {-22,  13},
            {-34,  100},
            {-31,  -43},
            {89,   -95},
            {52,   -49},
            {61,   -5},
            {20,   -94},
            {-42,  79},
            {-39,  -60},
            {-70,  39},
            {-21,  -10},
            {-41,  51},
            {-21,  -51},
            {82,   97},
            {-81,  -77},
            {39,   63},
            {24,   96},
            {-73,  36},
            {88,   -92},
            {-84,  27},
            {-33,  78},
            {96,   7},
            {-19,  10},
            {19,   -40},
            {-94,  -25},
            {32,   52},
            {42,   -22},
            {77,   65},
            {-64,  -4},
            {93,   94},
            {21,   89},
            {-90,  9},
            {-74,  -33},
            {-30,  -13},
            {35,   2},
            {-38,  84},
            {-29,  96},
            {73,   57},
            {-43,  -9},
            {-9,   -86},
            {50,   -64},
            {24,   -83},
            {2,    18},
            {-96,  52},
            {77,   71},
            {-93,  -57},
            {-88,  -40},
            {85,   -40},
            {2,    -45},
            {1,    47},
            {89,   19},
            {-27,  40},
            {-6,   -39},
            {40,   -19},
            {35,   87},
            {88,   -37},
            {31,   -79},
            {33,   8},
            {-2,   56},
            {25,   16},
            {-60,  -9},
            {-7,   -23},
            {-24,  86},
            {-79,  79},
            {80,   -69},
            {10,   -21},
            {-93,  -25},
            {23,   -59},
            {-81,  -50},
            {-2,   -46},
            {-64,  -91},
            {82,   25},
            {24,   8},
            {-59,  53},
            {-94,  61},
            {-18,  -67},
            {47,   34},
            {77,   11},
            {11,   -81},
            {84,   29},
            {-61,  -12},
            {-94,  41},
            {-56,  -1},
            {-79,  10},
            {-32,  67},
            {17,   45},
            {-11,  -4},
            {44,   66},
            {-98,  -55},
            {67,   43},
            {-28,  -80},
            {72,   -97},
            {-86,  -99},
            {1,    43},
            {-75,  -72},
            {-24,  -92},
            {-42,  -44},
            {38,   33},
            {-64,  -12},
            {-82,  -60},
            {38,   -51},
            {71,   -47},
            {40,   42},
            {-85,  60},
            {-46,  -61},
            {-25,  17},
            {-13,  -17},
            {21,   84},
            {-56,  -72},
            {95,   67},
            {-28,  73},
            {53,   -4},
            {-14,  -92},
            {21,   -43},
            {82,   -63},
            {-98,  42},
            {65,   -97},
            {-78,  72},
            {54,   65},
            {44,   -15},
            {-88,  7},
            {23,   -62},
            {-8,   -6},
            {-11,  -93},
            {43,   81}};
    vector<int> num4 = {3, 2, 4, 1, -2, -1, -1, 3, 8, 7, 5, -2, 5, 9, -2,
                        8, 3, -1, 8, 7, -2, 7, -2, 7, 4, 9, 5, 7, 9, 9,
                        -1, 2, -1, -1, -2, -1, 8, -1, 7, -1, 2, 6, 6, 3, -1,
                        7, 5, 4, 4, 1, -2, 9, 4, -2, 5, 7, -2, -2, 5, 4,
                        3, 8, -2, 5, 5, 6, 6, 6, 8, -1, 1, -1, -1, 6, 3,
                        5, 8, 2, -1, 7, -2, 8, -2, -2, 2, 4, -1, -1, -2, 3,
                        4, -2, 1, 9, -1, -2, 4, 7, 5, 9};
    cout << test4.robotSim(num4, obs4) << endl;
}
//
// Created by ASUS on 2024/7/14.
//
