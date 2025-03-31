// problem: https://leetcode.cn/problems/design-twitter/
#include <iostream>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bits/ranges_algo.h>

#include "../utils/vector_helper.h"

using namespace std;

#include <ranges>

class Twitter {
public:
    int cur_id = 0;
    unordered_map<int, vector<pair<int, int> > > posts_;
    unordered_map<int, unordered_set<int> > follow_;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        posts_[userId].emplace_back(cur_id++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > posts;

        follow_[userId].insert(userId);
        for (auto followee: follow_[userId]) {
            for (auto post: views::reverse(posts_[followee])) {
                posts.push(post);
                if (posts.size() > 10) {
                    posts.pop();
                }
            }
        }
        vector<int> res = {};
        while (not posts.empty()) {
            res.push_back(posts.top().second);
            posts.pop();
        }
        ranges::reverse(res);
        return res;
    }

    void follow(int followerId, int followeeId) {
        follow_[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follow_[followerId].erase(followeeId);
    }
};

class Twitter2 {
public:
    int cur_id = 0;
    unordered_map<int, vector<pair<int, int> > > posts_;
    unordered_map<int, unordered_set<int> > follow_;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        posts_[userId].emplace_back(cur_id++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        pmr::set<pair<int, int> > posts;
        bool first_time = true;
        int min_id = -1;


        follow_[userId].insert(userId);
        int cnts = 0;
        for (auto followee: follow_[userId]) {
            for (auto post: views::reverse(posts_[followee])) {
                if (not first_time) {
                    if (post.first > min_id) {
                        posts.insert(post);
                        posts.erase(posts.begin());
                        min_id = posts.begin()->first;
                    }
                } else {
                    posts.insert(post);
                    cnts++;
                    if (cnts >= 10) {
                        min_id = posts.begin()->first;
                        first_time = false;
                    }
                }
            }
        }
        // cout << posts.rbegin()->first << endl;
        auto first_view = views::reverse(posts) | views::transform(&pair<int, int>::second);
        return {first_view.begin(), first_view.end()};
    }

    void follow(int followerId, int followeeId) {
        follow_[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follow_[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main(int argc, char *argv[]) {
    Twitter twitter;

    twitter.postTweet(1, 6765);
    twitter.postTweet(5, 671);
    twitter.postTweet(3, 2868);
    twitter.postTweet(4, 8148);
    twitter.postTweet(4, 386);
    twitter.postTweet(3, 6673);
    twitter.postTweet(3, 7946);
    twitter.postTweet(3, 1445);
    twitter.postTweet(4, 4822);
    twitter.postTweet(1, 3781);
    twitter.postTweet(4, 9038);
    twitter.postTweet(1, 9643);
    twitter.postTweet(3, 5917);
    twitter.postTweet(2, 8847);

    twitter.follow(1, 3);
    twitter.follow(1, 4);
    twitter.follow(4, 2);
    twitter.follow(4, 1);
    twitter.follow(3, 2);
    twitter.follow(3, 5);
    twitter.follow(3, 1);
    twitter.follow(2, 3);
    twitter.follow(2, 1);
    twitter.follow(2, 5);
    twitter.follow(5, 1);
    twitter.follow(5, 2);

    // vector<int> feed1 = twitter.getNewsFeed(1);
    // vector<int> feed2 = twitter.getNewsFeed(2);
    // vector<int> feed3 = twitter.getNewsFeed(3);
    // vector<int> feed4 = twitter.getNewsFeed(4);
    // vector<int> feed5 = twitter.getNewsFeed(5);
    show_vector(twitter.getNewsFeed(1));

    for (auto k: twitter.posts_[3]) {
        cout << k.first << ", " << k.second << endl;
    }
}


//
// Created by ASUS on 2025/3/27.
//
