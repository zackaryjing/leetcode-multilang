-- problem: https://leetcode.cn/problems/monthly-transactions-i/description/


SELECT DATE_FORMAT(t.trans_date,"%Y-%m") as month,
    t.country as country,
    COUNT(*) as trans_count,
    SUM(CASE WHEN t.state = 'approved' THEN 1 ELSE 0 END) as approved_count,
    SUM(amount) as trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) as approved_total_amount
FROM Transactions as t
GROUP BY month, t.country;


-- Transactions
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | country       | varchar |
-- | state         | enum    |
-- | amount        | int     |
-- | trans_date    | date    |
-- +---------------+---------+
-- output
-- +----------+---------+-------------+----------------+--------------------+-----------------------+
-- | month    | country | trans_count | approved_count | trans_total_amount | approved_total_amount |
-- +----------+---------+-------------+----------------+--------------------+-----------------------+


-- Created by Zackary37 at 6/11/2025 4:02 PM