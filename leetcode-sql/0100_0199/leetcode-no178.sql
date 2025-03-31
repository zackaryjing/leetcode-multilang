-- https://leetcode.cn/problems/rank-scores/description/ 
SELECT s.score,
    t.rk as `rank`
FROM scores s
    LEFT JOIN (
        SELECT DISTINCT score,
            DENSE_RANK() OVER (
                ORDER BY score DESC
            ) AS rk
        FROM scores
    ) as t on s.score = t.score
ORDER BY s.score DESC;
--
--
SELECT score,
    DENSE_RANK() OVER (
        ORDER BY score DESC
    ) AS `rank`
FROM scores