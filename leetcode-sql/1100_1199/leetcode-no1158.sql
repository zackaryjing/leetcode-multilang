-- problem: https://leetcode.cn/problems/market-analysis-i/
SELECT u.user_id as buyer_id,
    u.join_date as join_date,
    COALESCE(b.cnt, 0) as orders_in_2019
FROM Users u
    LEFT JOIN (
        SELECT o.buyer_id,
            count(*) as cnt
        FROM Orders o
        WHERE o.order_date BETWEEN "2019-01-01" AND "2020-01-01"
        GROUP BY o.buyer_id
    ) as b ON b.buyer_id = u.user_id;
--
-- Created By Zackary37 At 2025-05-17 22:45:17
- -