#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>




using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        (void) n;
        if (roads.empty()) {
            return 0;
        }
        if (roads.size() == 1) {
            return 1;
        }
        auto road_set = set<vector<int>>(roads.begin(), roads.end());
        unordered_map<int, int> rank;
        for (auto road: roads) {
            rank[road[0]]++;
            rank[road[1]]++;
        }
        auto sorted_data = vector<pair<int, int>>(rank.begin(), rank.end());
        std::sort(sorted_data.begin(), sorted_data.end(),
                  [](const auto a, const auto b) { return a.second > b.second; });

        int data_length = static_cast<int>(sorted_data.size());

        int k = 0;
        int ans = sorted_data[0].second + sorted_data[1].second;
        while (k < data_length and sorted_data[0].second == sorted_data[k].second) {
            int j = k + 1;
            while (j < data_length and sorted_data[1].second == sorted_data[j].second) {
                if (not(road_set.find(vector<int>({sorted_data[k].first, sorted_data[j].first})) != road_set.end() or
                        road_set.find(vector<int>({sorted_data[j].first, sorted_data[k].first})) != road_set.end())) {
                    return ans;
                }
                j++;
            }
            k++;
        }

        auto secondary = sorted_data[0].second + sorted_data[2].second;
        if (road_set.find(vector<int>({sorted_data[0].first, sorted_data[2].first})) != road_set.end() or
            road_set.find(vector<int>({sorted_data[2].first, sorted_data[0].first})) != road_set.end())
            secondary -= 1;

        return ans - 1;
    }
};

int main() {
    Solution test;
    vector<vector<int>> array1 = {{0, 1},
                                  {1, 2},
                                  {2, 3},
                                  {2, 4},
                                  {5, 6},
                                  {5, 7}};
    cout << test.maximalNetworkRank(8, array1) << endl;

    vector<vector<int>> array2 = {{0, 1},
                                  {0, 3},
                                  {1, 2},
                                  {1, 3},
                                  {2, 3},
                                  {2, 4}};
    cout << test.maximalNetworkRank(5, array2) << endl;

};