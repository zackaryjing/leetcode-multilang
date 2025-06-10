-- problem: https://leetcode.cn/problems/invalid-tweets/

SELECT t.tweet_id
FROM Tweets t
WHERE LENGTH(t.content) > 15;


-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | tweet_id       | int     |
-- | content        | varchar |
-- +----------------+---------+

-- Created by Zackary37 at 6/10/2025 9:19 PM