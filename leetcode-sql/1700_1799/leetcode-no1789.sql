-- problem: https://leetcode.cn/problems/primary-department-for-each-employee/description/

(SELECT e.employee_id employee_id, e.department_id department_id
 FROM Employee e
 WHERE e.primary_flag = 'Y')
UNION
(SELECT e.employee_id, e.department_id
 FROM Employee e
 GROUP BY e.employee_id
 HAVING COUNT(*) = 1)


-- some said not it's not recommended to use group by here because it
-- doesn't contain department_id. but it works for mysql, whatever.

-- +---------------+---------+
-- | Column Name   |  Type   |
-- +---------------+---------+
-- | employee_id   | int     |
-- | department_id | int     |
-- | primary_flag  | varchar |
-- +---------------+---------+

-- Created by Zackary37 at 6/10/2025 9:23 PM