-- https://leetcode.cn/problems/consecutive-numbers/
SELECT DISTINCT a.num as ConsecutiveNums
FROM Logs a
    LEFT JOIN Logs b on a.id + 1 = b.id
    LEFT JOIN Logs c on a.id + 2 = c.id
WHERE a.num = b.num AND b.num = c.num