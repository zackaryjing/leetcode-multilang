-- problem: https://leetcode.cn/problems/investments-in-2016/
SELECT ROUND(SUM(i.tiv_2016), 2) AS tiv_2016
FROM Insurance i
WHERE EXISTS (
    SELECT 1
    FROM Insurance j
    WHERE j.pid != i.pid AND j.tiv_2015 = i.tiv_2015
)
AND NOT EXISTS (
    SELECT 1
    FROM Insurance j
    WHERE j.pid != i.pid AND j.lat = i.lat AND j.lon = i.lon
);
--
-- Created By USER_NAME At 2025-04-13 23:13:06
- -