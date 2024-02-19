#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class TopVotedCandidate2 {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.sizes();
        vector<pair<int,int>> candidate;
        map<int,int> votes;
        int lastperson = persons[0];
        for (int i = 0;i < n;++i){
            cout << votes[persons[i]]<< " "<< persons[i] << " <-" << endl;
            votes[persons[i]]++;
//            if (votes.rbegin()->second == (++votes.rbegin())->second){
            if (votes.rbegin()->second == votes[persons[i]]){
                candidate.emplace_back(times[i],persons[i]);
            } else {
                candidate.emplace_back(times[i],votes.rbegin()->first);
//                lastperson = persons[i];
                lastperson = votes.rbegin()->first;
            }
            cout << votes.end()->first << " " << votes.rbegin()->second << endl;
        }
        cout << "----" << endl;
        for (auto [t,j] : votes) cout << t << " " << j << endl;
        cout << "----" << endl;
//        for (auto [t,j] : votes) cout << t << " " << j << endl;
        for (auto [t,j] : candidate) cout << t << " " << j << endl;
        cout << "----" << endl;
        cout << votes.rbegin()->first << " " << votes.rbegin()->second << endl;
        cout << votes.begin()->first << " " << votes.begin()->second << endl;
    }
    int q(int t) {
        ;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

class TopVotedCandidate {
public:
    vector<int> tops;
    vector<int> times;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> voteCounts;
        voteCounts[-1] = -1;
        int top = -1;
        for (auto & p : persons) {
            voteCounts[p]++;
            if (voteCounts[p] >= voteCounts[top]) {
                top = p;
            }
            tops.emplace_back(top);
        }
        this->times = times;
    }

    int q(int t) {
        int pos = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return tops[pos];
    }
};


int main(){
    vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
    vector<int> times = {0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate test(persons,times);
    test.q(120);
    return 0;
}
//
// Created by ASUS on 2023/9/11.
//
