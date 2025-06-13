-- problem: https://leetcode.cn/problems/find-followers-count/

SELECT user_id, COUNT(*) as followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;


-- Created by Zackary37 at 6/12/2025 11:39 AM