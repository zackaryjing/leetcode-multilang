-- problem: https://leetcode.cn/problems/human-traffic-of-stadium/


WITH triple AS (SELECT s1.id         i1,
                       s1.visit_date d1,
                       s1.people     p1,
                       temp.i2       i2,
                       temp.d2       d2,
                       temp.p2       p2,
                       temp.i3       i3,
                       temp.d3       d3,
                       temp.p3       p3
                FROM Stadium s1
                         JOIN (SELECT s2.id         i2,
                                      s2.visit_date d2,
                                      s2.people     p2,
                                      s3.id         i3,
                                      s3.visit_date d3,
                                      s3.people     p3
                               FROM Stadium s2
                                        JOIN Stadium s3
                                             ON s2.id + 1 = s3.id
                               WHERE s2.people >= 100
                                 AND s3.people >= 100) temp
                              ON s1.id + 1 = temp.i2
                WHERE s1.people >= 100)
SELECT i1 as id, d1 as visit_date, p1 as people
FROM (SELECT i1, d1, p1
      FROM triple
      UNION
      SELECT i2, d2, p2
      FROM triple
      UNION
      SELECT i3, d3, p3
      FROM triple) as t
ORDER BY i1;


-- +------+------------+-----------+
-- | id   | visit_date | people    |
-- +------+------------+-----------+
-- Stadium
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | visit_date    | date    |
-- | people        | int     |
-- +---------------+---------+

-- Created by Zackary37 at 6/11/2025 3:24 PM