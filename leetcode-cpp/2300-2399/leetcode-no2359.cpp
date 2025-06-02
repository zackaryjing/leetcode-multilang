// problem:  https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/?envType=daily-question&envId=2025-05-30
#include <deque>
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;

// time spent: 1:49:15
class Solution {
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        int dist = 0;
        while (node1 >= 0) {
            if (dist1[node1] < 0) {
                dist1[node1] = dist;
                node1 = edges[node1];
            } else {
                break;
            }
            dist++;
        }
        int min_dist = INT_MAX;
        int res = -1;
        dist = 0;
        while (node2 >= 0) {
            if (dist1[node2] >= 0) {
                int temp = max(dist1[node2], dist);
                if (temp < min_dist) {
                    min_dist = temp;
                    res = node2;
                } else if (temp == min_dist) {
                    res = min(node2, res);
                }
                min_dist = min(max(dist1[node2], dist), min_dist);
            }
            if (dist2[node2] < 0) {
                dist2[node2] = dist;
                node2 = edges[node2];
                dist++;
            } else {
                break;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.closestMeetingNode(temp_vector({2, 2, 3, -1}), 0, 1) << endl;
    cout << test.closestMeetingNode(temp_vector({1, 2, -1}), 0, 2) << endl;
    cout << test.closestMeetingNode(temp_vector({5, -1, 3, 4, 5, 6, -1, -1, 4, 3}), 0, 0) << endl;
    cout << test.closestMeetingNode(temp_vector({4, 4, 4, 5, 1, 2, 2}), 1, 1) << endl;
}

//
// Created By Zackary At 2025-05-30 15:12:56
//
