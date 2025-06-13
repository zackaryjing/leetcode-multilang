-- problem: https://leetcode.cn/problems/top-travellers/description/

SELECT u.name, COALESCE(t.d, 0) as travelled_distance
FROM Users u
         LEFT JOIN (SELECT user_id id, SUM(distance) d
                    FROM Rides
                    GROUP BY user_id) as t
                   ON u.id = t.id
ORDER BY travelled_distance DESC, u.name;

--
-- not so good solution:

SELECT u.name, COALESCE(sum(distance), 0) as travelled_distance
FROM Rides r
         RIGHT JOIN Users u on r.user_id = u.id
GROUP BY r.user_id, u.name
ORDER BY travelled_distance DESC, u.name;


-- Created by Zackary37 at 6/12/2025 11:48 AM