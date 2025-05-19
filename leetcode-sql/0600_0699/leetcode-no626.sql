-- problem: https://leetcode.cn/problems/exchange-seats/
SELECT s.id AS id,
    s1.student AS student
FROM Seat s
    LEFT JOIN Seat s1 ON (
        s.id % 2 = 0
        AND s.id = s1.id + 1
    )
    OR (
        s.id % 2 = 1
        AND s.id = s1.id - 1
    )
    OR (
        s.id = (
            SELECT MAX(s2.id)
            FROM Seat s2
        )
        AND s.id % 2 = 1
        AND s.id = s1.id
    );
--
-- Created By Zackary37 At 2025-05-19 21:19:18
- -