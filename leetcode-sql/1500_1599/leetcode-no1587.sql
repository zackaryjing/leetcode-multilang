-- problem: https://leetcode.cn/problems/bank-account-summary-ii/description/

SELECT u.name, temp.balance
FROM Users u
         JOIN (SELECT account, SUM(amount) as balance
               FROM Transactions
               GROUP BY account) temp
              ON u.account = temp.account
WHERE temp.balance > 10000;

-- Users
-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | account      | int     |
-- | name         | varchar |
-- +--------------+---------+
-- Transactions
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | trans_id      | int     |
-- | account       | int     |
-- | amount        | int     |
-- | transacted_on | date    |
-- +---------------+---------+
-- output
-- +------------+------------+
-- | name       | balance    |
-- +------------+------------+

-- Created by Zackary37 at 6/11/2025 2:40 PM