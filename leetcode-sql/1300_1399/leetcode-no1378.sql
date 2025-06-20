-- problem: https://leetcode.cn/problems/replace-employee-id-with-the-unique-identifier/description/

SELECT u.unique_id, e.name
FROM Employees e
         LEFT JOIN EmployeeUNI u
                   ON e.id = u.id;


-- Table: Employees
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | name          | varchar |
-- +---------------+---------+
-- Table: EmployeeUNI
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | unique_id     | int     |
-- +---------------+---------+
-- +-----------+----------+
-- | unique_id | name     |
-- +-----------+----------+

-- Created by Zackary37 at 6/12/2025 11:42 AM