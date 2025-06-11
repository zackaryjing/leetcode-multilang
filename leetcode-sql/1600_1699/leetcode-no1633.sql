-- problem: https://leetcode.cn/problems/percentage-of-users-attended-a-contest/description/

SELECT DISTINCT contest_id,
                ROUND(
                        COUNT(*) over(partition by contest_id) * 100 /
            (SELECT COUNT(*) FROM Users), 2) as percentage
FROM Register
ORDER BY percentage DESC, contest_id;

--- solution2

SELECT DISTINCT contest_id,
                ROUND(COUNT(*) * 100 / (SELECT COUNT(*) FROM Users), 2) as percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;


-- Users
--
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | user_id     | int     |
-- | user_name   | varchar |
-- +-------------+---------+
--
--
--  Register
--
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | contest_id  | int     |
-- | user_id     | int     |
-- +-------------+---------+

-- Created by Zackary37 at 6/11/2025 2:29 PM