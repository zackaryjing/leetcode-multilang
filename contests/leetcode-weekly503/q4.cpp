// problem: https://leetcode.cn/contest/weekly-contest-503/problems/number-of-pairs-after-increment/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    vector<int> numberOfPairs(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
        const int m = nums1.size(), n = nums2.size();
        vector diff = vector(m, vector(n + 1, 0));
        nums2.push_back(0);
        vector sum = vector(m, nums2);
        for (int i = 0; i < m; ++i) {
            diff[i][0] = nums1[i];
        }
        bool updated = false;
        vector<int> res;
        int lastTot = -1;
        int lastCnt = 0;
        for (const auto &query: queries) {
            if (query[0] == 1) {
                updated = false;
                lastTot = -1;
                int val = query[3];
                for (int j = 0; j < m; ++j) {
                    diff[j][query[1]] += val;
                    diff[j][query[2] + 1] -= val;
                }
            }
            if (query[0] == 2) {
                int tot = query[1];
                int cnt = 0;
                if (lastTot == tot) {
                    res.push_back(lastCnt);
                    continue;
                }
                if (not updated) {
                    for (int j = 0; j < m; ++j) {
                        for (int k = 0; k < n; ++k) {
                            sum[j][k] += diff[j][k];
                            if (sum[j][k] == tot) {
                                cnt++;
                            }
                            diff[j][k + 1] += diff[j][k];
                        }
                        ranges::fill(diff[j], 0);
                    }
                    updated = true;
                } else {
                    for (int j = 0; j < m; ++j) {
                        for (int k = 0; k < n; ++k) {
                            if (sum[j][k] == tot) {
                                cnt++;
                            }
                        }
                    }
                }
                // show_matrix(sum);
                lastTot = tot;
                lastCnt = cnt;
                res.push_back(cnt);
            }
        }
        return res;
    }
};


class Solution3 {
public:
    // [TLE] failed really slow, but is correct.
    vector<int> numberOfPairs(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
        const int m = nums1.size(), n = nums2.size();
        vector diff = vector(n + 1, 0);
        bool updated = false;
        vector<int> res;
        int lastTot = -1;
        int lastCnt = 0;
        unordered_map<int, int> freq;
        for (const auto &query: queries) {
            if (query[0] == 1) {
                updated = false;
                lastTot = -1;
                const int val = query[3];
                diff[query[1]] += val;
                diff[query[2] + 1] -= val;
                freq.clear();
            }
            if (query[0] == 2) {
                const int tot = query[1];
                int cnt = 0;
                if (lastTot == tot) {
                    res.push_back(lastCnt);
                    continue;
                }
                if (not updated) {
                    for (int k = 0; k < n; ++k) {
                        nums2[k] += diff[k];
                        diff[k + 1] += diff[k];
                        freq[nums2[k]]++;
                    }
                    ranges::fill(diff, 0);
                    updated = true;
                }
                for (int j = 0; j < m; ++j) {
                    const int ntot = tot - nums1[j];
                    cnt += freq[ntot];
                }
                // show_vector(nums2);
                lastTot = tot;
                lastCnt = cnt;
                res.push_back(cnt);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> numberOfPairs(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
        vector<long long> nums2Value(nums2.begin(), nums2.end());
        int nums2Size = nums2Value.size();
        int blockSize = max(1, (int) sqrt(nums2Size));
        int blockCount = (nums2Size + blockSize - 1) / blockSize;
        vector blockLazyAdd(blockCount, 0LL);
        vector<unordered_map<long long, int>> blockValueFreq(blockCount);
        auto getBlockId = [&](int index) { return index / blockSize; };
        auto getBlockLeft = [&](int blockId) { return blockId * blockSize; };
        auto getBlockRight = [&](int blockId) { return min(nums2Size - 1, (blockId + 1) * blockSize - 1); };
        auto rebuildBlockFreq = [&](int blockId) {
            blockValueFreq[blockId].clear();
            int left = getBlockLeft(blockId);
            int right = getBlockRight(blockId);
            for (int index = left; index <= right; ++index) {
                blockValueFreq[blockId][nums2Value[index]]++;
            }
        };
        auto pushBlockLazy = [&](int blockId) {
            if (blockLazyAdd[blockId] == 0)
                return;
            int left = getBlockLeft(blockId);
            int right = getBlockRight(blockId);
            for (int index = left; index <= right; ++index) {
                nums2Value[index] += blockLazyAdd[blockId];
            }
            blockLazyAdd[blockId] = 0;
            rebuildBlockFreq(blockId);
        };
        auto decreaseBlockValueCount = [&](int blockId, int value) {
            auto it = blockValueFreq[blockId].find(value);
            if (--it->second == 0) {
                blockValueFreq[blockId].erase(it);
            }
        };
        auto increaseBlockValueCount = [&](int blockId, int value) { blockValueFreq[blockId][value]++; };
        auto addValueToSingleIndex = [&](int index, int valueToAdd) {
            int blockId = getBlockId(index);
            decreaseBlockValueCount(blockId, nums2Value[index]);
            nums2Value[index] += valueToAdd;
            increaseBlockValueCount(blockId, nums2Value[index]);
        };
        auto addValueToRange = [&](int queryLeft, int queryRight, int valueToAdd) {
            int leftBlockId = getBlockId(queryLeft);
            int rightBlockId = getBlockId(queryRight);
            if (leftBlockId == rightBlockId) {
                pushBlockLazy(leftBlockId);
                for (int index = queryLeft; index <= queryRight; ++index) {
                    addValueToSingleIndex(index, valueToAdd);
                }
                return;
            }
            pushBlockLazy(leftBlockId);
            int leftBlockRight = getBlockRight(leftBlockId);
            for (int index = queryLeft; index <= leftBlockRight; ++index) {
                addValueToSingleIndex(index, valueToAdd);
            }
            for (int blockId = leftBlockId + 1; blockId < rightBlockId; ++blockId) {
                blockLazyAdd[blockId] += valueToAdd;
            }
            pushBlockLazy(rightBlockId);
            int rightBlockLeft = getBlockLeft(rightBlockId);
            for (int index = rightBlockLeft; index <= queryRight; ++index) {
                addValueToSingleIndex(index, valueToAdd);
            }
        };
        for (int index = 0; index < nums2Size; ++index) {
            int blockId = getBlockId(index);
            blockValueFreq[blockId][nums2Value[index]]++;
        }
        vector<int> ans;
        for (const auto &query: queries) {
            if (query[0] == 1) {
                int left = query[1];
                int right = query[2];
                int valueToAdd = query[3];
                addValueToRange(left, right, valueToAdd);
            } else {
                int targetSum = query[1];
                long long pairCount = 0;
                for (int nums1Value: nums1) {
                    int neededNums2Value = targetSum - nums1Value;
                    for (int blockId = 0; blockId < blockCount; ++blockId) {
                        int storeValueNeeded = neededNums2Value - blockLazyAdd[blockId];
                        auto it = blockValueFreq[blockId].find(storeValueNeeded);
                        if (it != blockValueFreq[blockId].end()) {
                            pairCount += it->second;
                        }
                    }
                }
                ans.push_back((int) pairCount);
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.numberOfPairs(temp_vector({1, 2}), temp_vector({3, 4}),
                                   temp_vector({temp_vector({2, 5}), temp_vector({1, 0, 0, 2}), temp_vector({2, 5})})));
    show_vector(test.numberOfPairs(temp_vector({1, 1}), temp_vector({2, 2, 3}),
                                   temp_vector({temp_vector({2, 4}), temp_vector({1, 0, 1, 1}), temp_vector({2, 4})})));
}

//
// Created By ASUS At 2026-05-24 11:16
//
